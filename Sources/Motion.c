/*
 * Motion.c
 *
 *  Created on: 6 cze 2015
 *      Author: Maciej
 */
#include "WAIT1.h"
#include "LEDR.h"
#include "PwmLdd1.h"
#include "LEDL.h"
#include "PwmLdd2.h"
#include "I_BL.h"
#include "BitIoLdd1.h"
#include "FR1.h"
#include "BitIoLdd2.h"
#include "FR2.h"
#include "BitIoLdd3.h"
#include "TU1.h"
#include "FRE.h"
#include "BitIoLdd4.h"
#include "MOTFR.h"
#include "PwmLdd3.h"
#include "TU2.h"
#include "MOTRR.h"
#include "PwmLdd4.h"
#include "MOTFL.h"
#include "PwmLdd5.h"
#include "MOTRL.h"
#include "PwmLdd6.h"
#include "RR1.h"
#include "BitIoLdd5.h"
#include "RR2.h"
#include "BitIoLdd6.h"
#include "RRE.h"
#include "BitIoLdd7.h"
#include "FL1.h"
#include "BitIoLdd8.h"
#include "FL2.h"
#include "BitIoLdd9.h"
#include "FLE.h"
#include "BitIoLdd10.h"
#include "RL1.h"
#include "BitIoLdd11.h"
#include "RL2.h"
#include "BitIoLdd12.h"
#include "RLE.h"
#include "BitIoLdd13.h"
#include "FAN.h"
#include "BitIoLdd14.h"

uint16_t moc_max; //wartosc aktualnie ustalonej przez uzytkownika predkosci
uint16_t drive_direction;	//0-stop; 12-tyl; 21-przod;
uint16_t l_diff;	//uchyb mocy lewej strony, od max, procentowo
uint16_t r_diff;	//uchyb mocy prawej strony, od max, procentowo
//***************************************************************************************
void set_right(uint16_t input) {
	LEDR_SetRatio16((65535 / 100) * input);	//wywo³anie dla komponentu prawej strony
	MOTFR_SetRatio16(65535 - ((65535 / 100) * input));
	MOTRR_SetRatio16(65535 - ((65535 / 100) * input));
}
void set_left(uint16_t input) {
	LEDL_SetRatio16((65535 / 100) * input);	//wywo³anie dla komponentu lewej strony
	MOTFL_SetRatio16(65535 - ((65535 / 100) * input));
	MOTRL_SetRatio16(65535 - ((65535 / 100) * input));
}
//***************************************************************************************
void l_direction(uint16_t dir)	//ustawienie w pinów sterujacych ************
{
	if (dir == 0)				//stop
			{
		FL1_PutVal(0);
		FL2_PutVal(0);
		RL1_PutVal(0);
		RL2_PutVal(0);
	} else if (dir == 12)		//tyl
			{
		FL1_PutVal(1);
		FL2_PutVal(0);
		RL1_PutVal(1);
		RL2_PutVal(0);
	} else if (dir == 21)		//przod
			{
		FL1_PutVal(0);
		FL2_PutVal(1);
		RL1_PutVal(0);
		RL2_PutVal(1);
	}
}
void r_direction(uint16_t dir)	//ustawienie w pinów sterujacych ************
{
	if (dir == 0)				//stop
			{
		FR1_PutVal(0);
		FR2_PutVal(0);
		RR1_PutVal(0);
		RR2_PutVal(0);
	} else if (dir == 12)		//tyl
			{
		FR1_PutVal(1);
		FR2_PutVal(0);
		RR1_PutVal(1);
		RR2_PutVal(0);
	} else if (dir == 21)		//przod
			{
		FR1_PutVal(0);
		FR2_PutVal(1);
		RR1_PutVal(0);
		RR2_PutVal(1);
	}
}

static void info(bool powodzenie)	//funkcja wyprowadzajaca informacje diod¹
{
	if (powodzenie == 1) {
		I_BL_PutVal(0);
		WAIT1_Waitms(5);
		I_BL_PutVal(1);
		WAIT1_Waitms(5);
		I_BL_PutVal(0);
		WAIT1_Waitms(5);
		I_BL_PutVal(1);
	} else {
		I_BL_PutVal(0);
		WAIT1_Waitms(5);
		I_BL_PutVal(1);
	}
}
void set_l_diff(uint16_t input)	//stopniowe ustawienie procentowej wartosci uchybu lewego
{
	uint16_t temp = l_diff;
	if (input != 100)
		l_direction(drive_direction);
	if (input > l_diff) {
		for (l_diff; l_diff < input && l_diff != temp + 6;) {
			l_diff++;
			set_left(moc_max - (moc_max * l_diff) / 100);
			set_right(moc_max - (moc_max * r_diff) / 100);
			WAIT1_Waitms(moc_max / 18);	//dla wiekszej max mocy kazdy procent diff to wieksza roznica
		}
	}
	if (input < l_diff) {
		for (l_diff; l_diff > input && l_diff != temp - 3;) {
			l_diff--;
			set_left(moc_max - (moc_max * l_diff) / 100);
			set_right(moc_max - (moc_max * r_diff) / 100);
			WAIT1_Waitms(moc_max / 12);	//dla wiekszej max mocy kazdy procent diff to wieksza roznica
		}
	}
	if (l_diff == 100)
		l_direction(0);
}
void set_r_diff(uint16_t input)	//stopniowe ustawienie procentowej wartosci uchybu prawego
{
	uint16_t temp = r_diff;
	if (input != 100)
		r_direction(drive_direction);
	if (input > r_diff) {
		for (r_diff; r_diff < input && r_diff != temp + 6;) {
			r_diff++;
			set_left(moc_max - (moc_max * l_diff) / 100);
			set_right(moc_max - (moc_max * r_diff) / 100);
			WAIT1_Waitms(moc_max / 18);	//dla wiekszej max mocy kazdy procent diff to wieksza roznica
		}
	}
	if (input < r_diff) {
		for (r_diff; r_diff > input && r_diff != temp - 3;) {
			r_diff--;
			set_left(moc_max - (moc_max * l_diff) / 100);
			set_right(moc_max - (moc_max * r_diff) / 100);
			WAIT1_Waitms(moc_max / 12);	//dla wiekszej max mocy kazdy procent diff to wieksza roznica
		}
	}
	if (r_diff == 100)
		r_direction(0);
}
void set_moc_max(uint16_t input)//stopniowe ustawienie mocy granicznej na zadana
{
	//r_direction(drive_direction);	//ustawienie kierunku innego niz stop
	//l_direction(drive_direction);	//ustawienie kierunku innego niz stop
	uint16_t temp = moc_max;
	if (input > moc_max) {
		for (moc_max; moc_max < input && moc_max != temp + 2;) {
			moc_max++;
			set_left(moc_max - (moc_max * l_diff) / 100);
			set_right(moc_max - (moc_max * r_diff) / 100);
			WAIT1_Waitms(25 - (moc_max / 5));
		}
	}
	if (input < moc_max) {
		for (moc_max; moc_max > input && (moc_max != temp - 4 || input == 0);) {
			moc_max--;
			set_left(moc_max - (moc_max * l_diff) / 100);
			set_right(moc_max - (moc_max * r_diff) / 100);
			WAIT1_Waitms(7 - (moc_max / 20));
		}
	}
	if (moc_max == 0) {
		r_direction(0); //ustawienie pinów steruj¹cych na hamowanie
		r_direction(0); //ustawienie pinów steruj¹cych na hamowanie
	}
}
void driveByVars(uint16_t mocIn, uint16_t ldiffIn, uint16_t rdiffIn, uint16_t dirIn) {
	for (int rep = 0; rep < 5 || (mocIn == 0 && moc_max != 0); rep++) {
		if (moc_max == 0) {
			drive_direction = dirIn;
			info(0);
		}
		set_moc_max(mocIn);
		set_l_diff(ldiffIn);
		set_r_diff(rdiffIn);
	}
}
