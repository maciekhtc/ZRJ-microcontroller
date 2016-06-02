/*
 * Application.c
 *
 *      Author: Maciej
 */
#include "CLS1.h"
#include "WAIT1.h"
#include "Shell.h"
#include "UTIL1.h"
#include "ESP8266.h"
#include "AS2.h"
#include "LEDR.h"
#include "Motion.h"
#include "FAN.h"
#include "FRE.h"
#include "FLE.h"
#include "RRE.h"
#include "RLE.h"

//static uint8_t APP_EspMsgBuf[512]; /* buffer for messages from ESP8266 */

uint8_t mojBufor[100];

uint8_t licznik = 0;
uint8_t moc, ldiff, rdiff, dir;

static void WebProcess(void) {

	const CLS1_StdIOType *io;

	while (AS2_GetCharsInRxBuf() > 0) {
		uint8_t ch;

		(void) AS2_RecvChar(&ch);
		mojBufor[licznik] = ch;
		CLS1_SendChar(ch);
		licznik++;

		if (licznik > 2 && mojBufor[licznik - 2] == 44
				&& mojBufor[licznik - 1] == 67) {
			driveByVars(0, 0, 0, 0);//zatrzymanie pojazdu poprzed podanie parametrów 0	//connection closed (s³abe)*****
			licznik = 0;			//jakos sygnalizowac do metody sprawdzajacej na timerze?
		}

		if (licznik > 18 && mojBufor[licznik - 3] == 43				//data input
		&& mojBufor[licznik - 2] == 43 && mojBufor[licznik - 1] == 43) {
			AS2_ClearRxBuf();
			parserDanych(licznik);
			licznik = 0;
		}

		if (licznik == 99)
			licznik = 0;
	}

}
void parserDanych(uint8_t licz) {
	uint8_t mocStr[3], ldiffStr[3], rdiffStr[3], dirStr[3];
	memcpy(&mocStr, &mojBufor[licz - 18], 3);
	moc = atoi(mocStr);
	memcpy(&ldiffStr, &mojBufor[licz - 14], 3);
	ldiff = atoi(ldiffStr);
	memcpy(&rdiffStr, &mojBufor[licz - 10], 3);
	rdiff = atoi(rdiffStr);
	memcpy(&dirStr, &mojBufor[licz - 6], 3);
	dir = atoi(dirStr);
	driveByVars(moc, ldiff, rdiff, dir);//przekazanie zmiennych sterujacych modu³owi jazdy
}

void APP_Run(void) {
	CLS1_ConstStdIOType *io;
	WAIT1_Waitms(1000);
	ESP_Init();
	SHELL_Init();
	io = CLS1_GetStdio();
	CLS1_SendStr("\r\n-------------------\r\n", io->stdOut);
	CLS1_SendStr("ZRJ Project Startup\r\n", io->stdOut);
	CLS1_SendStr("-------------------\r\n", io->stdOut);
	CLS1_PrintPrompt(io);
	WAIT1_Waitms(3000);
	ESP_WebStarter(io);
	moc_max = 0; //wartosc aktualnie ustalonej przez uzytkownika predkosci
	drive_direction = 0;	//0-stop; 12-cw; 21-ccw;
	l_diff = 0;	//uchyb mocy lewej strony, roznica od max, procentowo
	r_diff = 0;	//uchyb mocy prawej strony, roznica od max, procentowo
	FRE_PutVal(1);	//zalaczenie driverow silnikow
	FLE_PutVal(1);
	RRE_PutVal(1);
	RLE_PutVal(1);
	FAN_PutVal(1); //wiatrak zalacz
	for (;;) {
		WebProcess();
		SHELL_Parse();
		WAIT1_Waitms(10);
	}
}
