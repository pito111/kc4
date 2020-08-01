#include "gui.h"
#include "ILI9341_t3n.h"
#include "ili9341_t3n_font_OpenSans.h"

#include "usb_keyboard.h"
#include "matrix.h"
#include "kc_data.h"


//const uint8_t Gui::InfoPages[I_All] = {0,1};

//  Info use,ver
//....................................................................................
void Gui::DrawInfo()
{
	//  menu
	if (mlevel == 1)
	{
		DrawTitleMain(RGB(22,20,26), &bmpINFO);
		DrawMenu(I_All,strInfo,0, C_Info,RGB(22,20,28),RGB(4,4,8));
		pressGui = 0;
		return;
	}
	char a[64];
	int16_t y = yTitle, x1 = W / 2, x2 = x1 + 14;
	auto yadd = [&y](int16_t h){  y += h*15/8;  };


	if (yy == I_Version)
	{	demos.Version();  return;  }

	//  title
	DrawTitle(strInfo[yy], RGB(17,17,22), yy == I_Version ? &bmpHELP : &bmpINFO);
	d->setFont(OpenSans12);
	d->setClr(21,21,26);


	//int ii = InfoPages[yy];
	switch (yy)
	{
	//-----------------------------------------------------
	case I_Use:  // use
	{
		d->setClr(15,23,30);
		d->setCursor(40, y);  d->print("> ");

		d->setClr(16,20,24);
		sprintf(a,"Save counter:");  PrintR(a, x1, y);
		sprintf(a,"%d", par.verCounter);  d->setCursor(x2, y);  d->print(a);  yadd(14);

		int i,l,k, s = 0, t = 0, si = 0;

		//  count nonempty seqs
		for (i=0; i < KC_MaxSeqs; ++i)
		{
			l = kc.set.seqs[i].len();
			if (l > 0)
			{	++s;  si += l;

				//  find if used, mapped
				uint8_t q = K_Seq0 + i; //seqId();  // code
				bool u = true;
				for (l=0; l < KC_MaxLayers; ++l)
				for (k=0; k < kc.set.scanKeys; ++k)
					if (kc.set.key[l][k] == q)  // found
						u = false;
				if (u) ++t;
			}
		}

		d->setClr(21,25,29);
		sprintf(a,"Sequences:");  PrintR(a, x1, y);
		sprintf(a,"%d  of %d", s, kc.set.seqSlots/*KC_MaxSeqs*/);
		d->setCursor(x2, y);  d->print(a);  yadd(10);
		d->setClr(15,21,25);
		sprintf(a,"Unused:");  PrintR(a, x1, y);
		sprintf(a,"%d", t);    d->setCursor(x2, y);  d->print(a);  yadd(10);
		sprintf(a,"Size:");     PrintR(a, x1, y);
		sprintf(a,"%d B", si);  d->setCursor(x2, y);  d->print(a);  yadd(12);

		//  int.funct keys used
		si = 0;
		for (i = K_Fun0; i < K_FunLast; ++i)
		{
			bool u = false;
			for (l=0; l < KC_MaxLayers; ++l)
				for (k=0; k < kc.set.nkeys(); ++k)
					if (kc.set.key[l][k] == i)
						u = true;
			if (u)  ++si;
		}

		//  count layers, keys
		s = 0;  t = 0;
		for (l=0; l < KC_MaxLayers; ++l)
		{
			bool u = false;
			for (k=0; k < kc.set.nkeys(); ++k)
				if (kc.set.key[l][k] != KEY_NONE)
				{	++t;  u = true;  }
			if (u)  ++s;
		}

		d->setClr(21,25,29);
		sprintf(a,"Layers:");  PrintR(a, x1, y);
		sprintf(a,"%d  of %d", s, KC_MaxLayers);
		d->setCursor(x2, y);  d->print(a);  yadd(12);

		sprintf(a,"Keys:");    PrintR(a, x1, y);
		sprintf(a,"%d", t);  d->setCursor(x2, y);  d->print(a);  yadd(10);
		d->setClr(15,21,25);
		sprintf(a,"Internal:");  PrintR(a, x1, y);
		sprintf(a,"%d", si);   d->setCursor(x2, y);  d->print(a);  yadd(12);

		d->setClr(25,25,29);
		sprintf(a,"Total:");  PrintR(a, x1, y);
		sprintf(a,"%d B", kc.memSize);
		d->setCursor(x2, y);  d->print(a);  yadd(12);


		//  usb const  --
	#if 0
		d->setClr(19,19,22);
		d->setCursor(0, y);  d->print(" USB const");  yadd(9);
		d->setClr(15,15,18);

		sprintf(a,"All %d  Ext %d  Md %d", KEYS_ALL, KEYS_ALL_EXT, K_F24+1);
		d->setCursor(0, y);  d->print(a);  yadd(8);

		sprintf(a,"Lay %d  Fun %d  Pw %d", K_Layer1, K_Fun0, KS_POWER_DOWN);
		d->setCursor(0, y);  d->print(a);  yadd(10);
	#endif

	}	break;
	}
}
