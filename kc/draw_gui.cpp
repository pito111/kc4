#include "gui.h"
#include "ILI9341_t3n.h"


//  Draw  main
//....................................................................................
void Gui::NextDemo()
{
	++yy;
	if (yy >= D_All)
		yy = 0;
}

void Gui::Draw()
{
	//yy = D_Hedrons;  //D_CK_Logo;  // test

	//  Clear
	bool no = (yy == D_Rain || yy == D_Plasma || yy == D_Wave || yy == D_Fire);
	if (!no)  //  if not full screen demo
		d->fillScreen(ILI9341_BLACK);
		//memset(d->getFrameBuffer(), 0, sizeof());
		//d->fillScreenHGradient(RGB(0,0,0), RGB(2,5,8));

	//  Demos
	//------------------------------------------------------
	switch (yy)
	{
	#ifdef DEMOS_PLASMA
		case D_Plasma:   demos.Plasma();  break;
	#endif
		case D_Wave:     demos.Wave();  break;
		case D_Fire:     demos.Fire();  break;
		case D_CK_Logo:  demos.CK_logo();  break;
	#ifdef DEMOS_3D
		case D_Hedrons:  demos.Hedrons();  break;
	#endif
	#ifdef DEMOS_OLD_PAR
		case D_Fonts:	 demos.Fonts();  break;
		case D_Ngons:    demos.Ngons();  break;

		case D_Fountain: demos.Fountain();  break;
		case D_Balls:    demos.Balls();  break;
		case D_Space:    demos.Space();  break;
	#endif
		case D_Rain:     demos.Rain();  break;
	}

}
