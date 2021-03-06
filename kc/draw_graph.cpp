#include "gui.h"
#include "ILI9341_t3n.h"
#include "ili9341_t3n_font_OpenSans.h"

#include "kc_data.h"


//  temp val
int Gui::TempFtoB(float tm)
{
	int t = 255.f * (tm - par.minTemp) / (par.maxTemp - par.minTemp);
	t = t > 255 ? 255 : (t < 1 ? 1 : t);  // 0 not measured
	return t;
}
float Gui::TempBtoF(uint8_t b)
{
	return b / 255.f * (par.maxTemp - par.minTemp) + par.minTemp;
}

//  auto range  get min,max
void Gui::AutoRange(int d)
{
	uint8_t tmin = 255, tmax = 0;
	for (int i=0; i <= W-1; ++i)
	{
		uint8_t t = grTemp[d][i];
		if (t > 0)  // measured
		{
			if (t > tmax)  tmax = t;
			if (t < tmin)  tmin = t;
		}
	}
	if (tmin > tmax)  // none yet
	{
		grFmin[d] = 20;  grBmin[d] = TempFtoB(grFmin[d]);
		grFmax[d] = 23;  grBmax[d] = TempFtoB(grFmax[d]);
	}else
	{	grFmin[d] = floor(TempBtoF(tmin));
		grFmax[d] =  ceil(TempBtoF(tmax));  // in 'C
		if (grFmin[d] + 3 >= grFmax[d])  // min range 3'C
		{	--grFmin[d];  ++grFmax[d];  }
		
		grBmin[d] = TempFtoB(grFmin[d]);
		grBmax[d] = TempFtoB(grFmax[d]);
		if (grBmin[d] == grBmax[d])
			++grBmax[d];
	}
}


//  Graphs ~ ~
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void Gui::DrawGraph(int16_t xMin, int16_t xMax, int16_t yMin, int16_t yMax,
	int8_t type, bool legend, int day/*daily*/)
{
	const int16_t xLen = xMax - xMin, yLen = yMax - yMin,
		yF = 13, left = 22, top = legend ? 10 : 6,  // marg
		hscP = legend ? 7 : 5;  // press h scale / 12

	int xc = par.xCur;
	bool cursor = legend && xc < W;
	auto cur = [&](auto i) {  return cursor && i == xc;  };

	int i,x,y, v,h;  // var
	char a[64];

	auto getPv = [&](auto i){  int ii = kc.grPpos[day] + i + W+1;  return kc.grPMin[day][ii % W];  };
	auto getTv = [&](auto i){  int ii =    grTpos[day] + i + W+1;  return    grTemp[day][ii % W];  };

	//  x time, press and temp
	auto xtD = [&](auto hr){  return W * hr / par.dailyHours;  };
	auto xtP = [&](auto tm){  return xMax - (day ? xtD(tm) : tm * 60000 / t1min(par));  };
	auto xtT = [&](auto tm){  return xMax - (day ? xtD(tm) : tm * 60000 / tTgraph(par));  };


	//  draw grid line with text value
	auto GridLineV = [&](int x, int n/*clr*/, const char* s)
	{
		if (x < xMin || x > xMax)  return;
		if (!legend)  n -= 7;

		if (!legend && d->readPixel(x, yMin) > 0)  return;  // only on black, looks bad..
		uint16_t clr = RGB(n,n,n);
		d->drawFastVLine(x, yMin + top, yLen - top, clr);  // |
		
		x -= 6;
		if (/*legend ||*/ x < xMin + left || x >= xMax-10)  return;
		n += 3;  clr = RGB(n,n,n);

		d->setCursor(x, yMin + 2);  d->setClr(clr);
		d->print(s);  // txt
	};

	auto GridLineH = [&](int y, int n/*clr*/, int val)//, bool show=false)
	{
		if (y < yMin || y > yMax)  return;
		if (!legend)  n -= 5;
		
		if (!legend && d->readPixel(xMin, y) > 0)  return;  // only
		uint16_t clr = RGB(n,n,n);
		d->drawFastHLine(xMin, y, xLen, clr);  // --
		
		n += 4;  clr = RGB(n,n,n);
		//if (show || legend)
		{
			if (y + 10 >= yMax)  y = yMax - 10;
			d->setCursor(xMin, y + 2);  d->setClr(clr);
			sprintf(a,"%d", val);  d->print(a);  // txt val
		}
	};

	if (legend)
		d->setFont(OpenSans10);
	else
		d->setFont();


	//  Press/1min
	//------------------------------------------------------------------------
	if (type == 0)
	{
		//  grid  ===
		for (i = 1; i <= 4; ++i)
		{
			v = i * 50;
			y = yMax - hscP * v / 12;
			GridLineH(y, v == 100 ? 11 : v == 50 || v == 150 ? 8 : 5, v);
		}

		//  grid  |||
		if (day)
		for (i = 2; i < par.dailyHours; i+=2)
		{	sprintf(a,"%d",i);
			GridLineV(xtP(i), i%4==0 ? 15:11, a);
		}else
		{	GridLineV(xtP( 10), 14, "10");  // m
			GridLineV(xtP( 30), 14, "30");
			GridLineV(xtP( 60), 18, "1h");  // h
			GridLineV(xtP(120), 16, "2h");
			GridLineV(xtP(240), 16, "4h");
			GridLineV(xtP(480), 16, "8h");
		}

		//  graph  Press/1min  ~~~
		for (i = xMin; i <= xMax; ++i)
		{
			v = getPv(i);
			if (v > 0)
			{
				ClrPress(v);

				h = hscP * v / 12;	if (h > yLen)  h = yLen;
				y = yMax - h;		if (y < 1)  y = 1;
				if (y+h < H)
				{
					if (legend)
					{
						d->drawFastVLine(i, y, h, d->getClr());
						if (cur(i))
							d->drawPixel(i, y, RGB(31,31,31));  //.
					}else
					{	d->drawPixel(i, y, d->getClr());
						//d->drawPixel(i, y-1, d->getClr());  // bold
				}	}
		}	}

		//  legend
		x = xMin + left;  y = yMin + top;
		if (legend)
		{
			d->setClr(20, 20, 25);
			d->setCursor(x, y);  d->print("Press/min");  y += yF+3;

			if (cursor)
			{
				v = getPv(xc);
				ClrPress(v);
				d->setCursor(x,y);  sprintf(a,"%d", v);  d->print(a);  y += yF;
				d->setCursor(x,y);  PrintInterval(
					(day ? tDaily(par) : t1min(par)) * (W-1-xc));  y += yF;
			}
			//  max
			v = yLen * 12 / hscP;
			d->setClr(16, 16, 20);
			d->setCursor(x,y);
			if (!cursor)
			{	d->print("max ");
				sprintf(a,"%d", v);  d->print(a);  y += yF;
			}
		}
		if (cursor)
		{
			d->drawPixel(xc, yMin, RGB(29,29,29));  // :
			d->drawPixel(xc, yMax, RGB(29,29,29));
		}
	}

	#ifdef TEMP1   //  Temp'C
	//------------------------------------------------------------------------
	if (type == 1)
	{
		if (grTempUpd[day])
		{	grTempUpd[day] = 0;
			AutoRange(day);
		}

		//  grid  |||
		if (day)
		for (i = 2; i < par.dailyHours; i+=2)
		{	sprintf(a,"%d",i);
			GridLineV(xtT(i), i%4==0 ? 15:11, a);
		}else
		{	GridLineV(xtT(  5), 10, "5" );
			GridLineV(xtT( 10), 15, "10");  // m
			GridLineV(xtT( 30), 13, "30");
			GridLineV(xtT( 60), 18, "1h");  // h
			GridLineV(xtT(120), 16, "2h");
			GridLineV(xtT(240), 16, "4h");
			GridLineV(xtT(480), 16, "8h");
		}

		//  vertical  ===
		if (grFmax[day] > grFmin[day])
		for (i = grFmin[day]; i <= grFmax[day]; ++i)  // 'C
		{
			y = yMax - yLen * (float(i) - grFmin[day]) / (grFmax[day] - grFmin[day]);
			GridLineH(y, i%5==0 ? 10 : i%2==0 ? 8 : 7, i);
		}

		//  graph  Temp  ~~~
		int dim = legend ? 1 : 2;
		if (grBmax > grBmin)
		for (i = xMin; i <= xMax; ++i)
		{
			v = getTv(i - xMax);
			if (v > 0)
			{	ClrTemp(v, dim);

				y = yMax - yLen * (float(v) - grBmin[day]) / (grBmax[day] - grBmin[day]);
				if (y >= yMin && y <= yMax)
					d->drawPixel(i,y, cur(i) ? RGB(31,31,31) : d->getClr());
		}	}

		//  legend
		x = xMin;  y = yMin + top;
		d->setCursor(x, y);
		if (legend)
		{
			d->setClr(18, 22, 25);
			x = xMin + left;
			d->setCursor(x,y);  d->print("Temp \x01""C");  y += yF+3;

			if (cursor)
			{
				d->drawPixel(xc, yMin+1, RGB(29,29,29));  // :
				d->drawPixel(xc, yMax, RGB(29,29,29));

				v = getTv(xc);
				ClrTemp(v);

				float f = xc == W-1 ? fTemp : // latest
				TempBtoF(v);
				d->setCursor(x,y);  dtostrf(f,4,2,a);  d->print(a);  y += yF;

				d->setCursor(x,y);  PrintInterval(
					(day ? tDaily(par) : tTgraph(par)) * (W-1-xc));  y += yF;
			}
		}
	}
	#endif
}
