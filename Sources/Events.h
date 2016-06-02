/* ###################################################################
**     Filename    : Events.h
**     Project     : ZRJ1
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-06-03, 15:40, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "WAIT1.h"
#include "UTIL1.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "CLS1.h"
#include "CS1.h"
#include "AS2.h"
#include "ASerialLdd2.h"
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
#include "FRE.h"
#include "BitIoLdd4.h"
#include "MOTFR.h"
#include "PwmLdd3.h"
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
#include "TU1.h"
#include "TU2.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.11]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
