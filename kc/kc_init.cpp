#include "kc_data.h"
#include "kbd_layout.h"
#include "usb_keyboard.h"
#include "matrix.h"
#include "keys_usb.h"
#include "kc_params.h"
#include "WProgram.h"  // rtc, Mouse


#ifdef LED_LAMP
void KC_Main::LedUpdate()
{
	analogWrite(LED_LAMP, ledOn ?
		min(4095, par.ledBright * par.ledBright) : 0);
}
#endif

//------------------------------------------------
void KC_Main::SeqModClear()
{
	//  clear modif
	for (int i=0; i <= K_ModLast; ++i)
		seqMod[i] = 0;
}

//  ctor  Main
//------------------------------------------------
KC_Main::KC_Main()
{
	err = E_ok;  memSize = 0;
	setBright = 1;
	SeqModClear();

	Mouse.screenSize(1920,1200);  //?

	//  rtc set
	/*unsigned long t = rtc_get();

	int yr = t/3600/24/365;
	if (yr == 0)  // set date if none
	{
		//  whatever in 2020
		t = 20 * 365 + 7 * 30;  t *= 24 * 3600;
		t += 16 * 3600;
		rtc_set(t);
	}*/
	ResetStats(true);

	memset(grPMin, 0, sizeof(grPMin));


	//  init matrixVis  :::
	uint c,r;
	for (c=0; c < KC_MaxCols; ++c)
	for (r=0; r < KC_MaxRows; ++r)
	{
		int sc = NumCols * r + c;
		matrixVis[sc] = 0;

		int i = 0;
		bool ok = true;
		while (ok && i < nDrawKeys)
		{
			const DrawKey& k = drawKeys[i];
			++i;
			if (k.sc == sc)  // found key with scan id
			{
				matrixVis[sc] = 1;
				ok = false;
			}
		}
	}
}

//  Reset stats, rtc, times
//------------------------------------------------
void KC_Main::ResetStats(bool rtc)
{
	// rtc
	unsigned long t = rtc_get();
	if (rtc)
		tm_on = t;

	tm_key = tm_keyOld = tm_keyAct = t;
	//  ms
	uint32_t ms = millis();
	msMin1 = msKeyLay = ms;

	//  cnt
	tInactSum = tInact1 = tInact2 = 0;
	min1_Keys = 0;

	cnt_press = 0;  // matrix.h
	cnt_press1min = 0;
}


//  clear evth
//------------------------------------------------
void KC_Setup::Clear()
{
	//  header  ver
	h1 ='k';  h2 = 'c';  ver = 6;  //+ up on changes

	//  default  matrix
	rows = NumRows;  cols = NumCols;
	scanKeys = rows * cols;
	seqSlots = KC_MaxSeqs;

	int i,l;
	for (l=0; l < KC_MaxLayers; ++l)
	for (i=0; i < KC_MaxRows * KC_MaxCols; ++i)
		key[l][i] = KEY_NONE;

	//  const size
	for (i=0; i < KC_MaxSeqs; ++i)
	{	seqs[i].data.clear();
		seqs[i].data.shrink_to_fit();  // free ram
	}
}

//  ctor  Setup
//------------------------------------------------
KC_Setup::KC_Setup()
{
	//Clear();
	InitCK();
}

//  Init
//------------------------------------------------
void KC_Setup::InitCK()
{
#if 1
	Clear();

	//  from draw layout
	for (int i=0; i < nDrawKeys; ++i)
	{
		const DrawKey& dk = drawKeys[i];
		if (dk.sc != NO)
		{
			#define add(code, lay)  key[lay][dk.sc] = code
			add(dk.code, 0);

		//  CK1 override  --*
		/*#ifdef CK1
			if (dk.code == K_6)		add(K_Layer1, 0);
			if (dk.code == K_INS)	add(K_Layer2, 0);  else 
		#elif defined(CK6)  //3 new
			if (dk.code == K_F14)	add(K_Layer2, 0);
			if (dk.code == K_CAPS)	add(K_Layer2, 0);  else 
			if (dk.code == K_F15)	add(K_Layer3, 0);  else 
			if (dk.code == K_NON_US_NUM)  add(K_Layer1, 0);  else 
		#elif defined(CK7)  //4 old
			if (dk.code == K_MENU)	add(K_Layer1, 0);
			if (dk.code == K_CAPS)	add(K_Layer2, 0);  else */
		#ifdef CKtest
			if (dk.code == K_UP)    add(K_UP, 0);  else
			if (dk.code == K_DOWN)  add(K_DOWN, 0);  else
			if (dk.code == K_LEFT)  add(K_LEFT, 0);  else
			if (dk.code == K_RIGHT) add(K_RIGHT, 0);  else

			if (dk.code == K_ENT)   add(K_ENT, 0);  else
			if (dk.code == K_BACK)  add(K_BACK, 0);  else
			if (dk.code == K_ESC)  add(K_ESC, 0);  else
			if (dk.code == K_RIGHT) add(K_RIGHT, 0);
		#endif
		#ifdef CK8
			//  funct
			if (dk.code == K_MINUS)	add(KF_BriDn, 2);  else
			if (dk.code == K_EQUAL)	add(KF_BriUp, 2);  else
			if (dk.code == K_RSHIFT)  add(KF_GUI, 2);  else
			if (dk.code == K_F12)	add(KF_Reset, 2);  else
			//  mouse
			if (dk.code == K_UP)    add(KM_Up, 2);  else
			if (dk.code == K_DOWN)  add(KM_Down, 2);  else
			if (dk.code == K_LEFT)  add(KM_Left, 2);  else
			if (dk.code == K_RIGHT) add(KM_Right, 2);  else
			if (dk.code == K_HOME)  add(KM_LMB, 2);  else
			if (dk.code == K_PGUP)  add(KM_RMB, 2);  else
			if (dk.code == K_DEL)   add(KM_MMB, 2);  else
			if (dk.code == K_END)   add(KM_WhlUp, 2);  else
			if (dk.code == K_PGDN)  add(KM_WhlDown, 2);  else
			//  player
			if (dk.code == K_Q)   add(K_F14, 1);  else
			if (dk.code == K_W)   add(K_F15, 1);  else
			if (dk.code == K_A)   add(KM_PREV_TRACK, 1);  else
			if (dk.code == K_S)   add(KM_NEXT_TRACK, 1);  else
			if (dk.code == K_Z)   add(K_F13, 1);  else
			if (dk.code == K_X)   add(KM_PLAY_PAUSE, 1);  else
			//  seq
			if (dk.code == K_D)   add(K_Seq0, 1);
			if (dk.code == K_F)   add(K_S1, 1);
			if (dk.code == K_G)   add(K_S2, 1);
			if (dk.code == K_H)   add(K_S3, 1);
		#endif
			#undef add
	}	}

	#if 1  //  examples  --*
	KC_Sequence sq;
	sq.add(K_A);  sq.add(K_LSHIFT);
	sq.add(K_B);  sq.add(K_LSHIFT);  sq.add(K_C);
	seqs[0] = sq;  sq.data.clear();

	sq.add(K_RCTRL);  sq.add(K_RSHIFT);
	sq.add(K_LEFT);  sq.add(K_LEFT);  sq.add(K_LEFT);
	seqs[2] = sq;  sq.data.clear();
	#endif

#else  // import fix from old kc data

	uint8_t key2[KC_MaxLayers][KC_MaxRows * KC_MaxCols];
	KC_Sequence seqs2[KC_MaxSeqs];

	int i,l;
	for (l=0; l < KC_MaxLayers; ++l)
	for (i=0; i < KC_MaxRows * KC_MaxCols; ++i)
		key2[l][i] = KEY_NONE;

	for (i=0; i < KC_MaxSeqs; ++i)
		seqs2[i].data.clear();

	//  copy
	for (l=0; l < KC_MaxLayers; ++l)
	for (i=0; i < KC_MaxRows * KC_MaxCols; ++i)
		key2[l][i] = key[l][i];

	for (i=0; i < 60; ++i)
		seqs2[i] = seqs[i];

	Clear();

	//  set
	//  from draw layout
	for (l=0; l <= 4; ++l)  //par
	for (i=0; i < nDrawKeys; ++i)
	{
		const DrawKey& dk = drawKeys[i];
		if (dk.sc != NO)
		{
			key[l][dk.sc] = key2[l][dk.sc];
		}
	}

	for (i=0; i < 60; ++i)
		seqs[i] = seqs2[i];
#endif
}
