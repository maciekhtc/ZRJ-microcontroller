/* ###################################################################
**     Filename    : main.c
**     Project     : ZRJ1
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-06-03, 15:40, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  APP_Run();
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
