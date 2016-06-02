/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CLS1.h
**     Project     : ZRJ1
**     Processor   : MKL25Z128VLK4
**     Component   : Shell
**     Version     : Component 01.065, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-06-03, 16:08, # CodeGen: 1
**     Abstract    :
**
**     Settings    :
**          Component name                                 : CLS1
**          Echo                                           : no
**          Prompt                                         : "CMD> "
**          Project Name                                   : ESP8266 with FRDM-KL25Z
**          Silent Mode Prefix                             : #
**          Blocking Send                                  : Enabled
**            Wait                                         : WAIT1
**            Wait Time (ms)                               : 10
**            RTOS Wait                                    : yes
**          Status Colon Pos                               : 13
**          Help Semicolon Pos                             : 26
**          Multi Command                                  : Disabled
**          Utility                                        : UTIL1
**          Default Serial                                 : Enabled
**            Console Interface                            : AS1
**          Semaphore                                      : no
**          Critical Section                               : CS1
**          History                                        : no
**     Contents    :
**         PrintPrompt                  - void CLS1_PrintPrompt(CLS1_ConstStdIOType *io);
**         SendNum8u                    - void CLS1_SendNum8u(uint8_t val, CLS1_StdIO_OutErr_FctType io);
**         SendNum8s                    - void CLS1_SendNum8s(int8_t val, CLS1_StdIO_OutErr_FctType io);
**         SendNum16u                   - void CLS1_SendNum16u(uint16_t val, CLS1_StdIO_OutErr_FctType io);
**         SendNum16s                   - void CLS1_SendNum16s(int16_t val, CLS1_StdIO_OutErr_FctType io);
**         SendNum32u                   - void CLS1_SendNum32u(uint32_t val, CLS1_StdIO_OutErr_FctType io);
**         SendNum32s                   - void CLS1_SendNum32s(int32_t val, CLS1_StdIO_OutErr_FctType io);
**         SendStr                      - void CLS1_SendStr(const uint8_t *str, CLS1_StdIO_OutErr_FctType io);
**         SendData                     - void CLS1_SendData(const uint8_t *data, uint16_t dataSize,...
**         PrintStatus                  - uint8_t CLS1_PrintStatus(CLS1_ConstStdIOType *io);
**         ParseCommand                 - uint8_t CLS1_ParseCommand(const uint8_t *cmd, bool *handled,...
**         ReadLine                     - bool CLS1_ReadLine(uint8_t *bufStart, uint8_t *buf, size_t bufSize,...
**         PrintCommandFailed           - void CLS1_PrintCommandFailed(const uint8_t *cmd, CLS1_ConstStdIOType *io);
**         IterateTable                 - uint8_t CLS1_IterateTable(const uint8_t *cmd, bool *handled,...
**         SetStdio                     - uint8_t CLS1_SetStdio(CLS1_ConstStdIOTypePtr stdio);
**         GetStdio                     - CLS1_ConstStdIOTypePtr CLS1_GetStdio(void);
**         RequestSerial                - void CLS1_RequestSerial(void);
**         ReleaseSerial                - void CLS1_ReleaseSerial(void);
**         ReadAndParseWithCommandTable - uint8_t CLS1_ReadAndParseWithCommandTable(uint8_t *cmdBuf, size_t cmdBufSize,...
**         ParseWithCommandTable        - uint8_t CLS1_ParseWithCommandTable(const uint8_t *cmd, CLS1_ConstStdIOType...
**         GetSemaphore                 - void* CLS1_GetSemaphore(void);
**         SendStatusStr                - void CLS1_SendStatusStr(const uint8_t *strItem, const uint8_t *strStatus,...
**         SendHelpStr                  - void CLS1_SendHelpStr(const uint8_t *strCmd, const uint8_t *strHelp,...
**         ReadChar                     - void CLS1_ReadChar(uint8_t *c);
**         SendChar                     - void CLS1_SendChar(uint8_t ch);
**         KeyPressed                   - bool CLS1_KeyPressed(void);
**         Init                         - void CLS1_Init(void);
**         Deinit                       - void CLS1_Deinit(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2014, all rights reserved.
**     http      : http://www.mcuoneclipse.com
**     This an open source software implementing a command line shell with Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file CLS1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup CLS1_module CLS1 module documentation
**  @{
*/         


#ifndef __CLS1_H
#define __CLS1_H

/* MODULE CLS1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include "Cpu.h"
#include <stddef.h> /* for size_t */


#ifndef __BWUserType_CLS1_StdIO_OutErr_FctType
#define __BWUserType_CLS1_StdIO_OutErr_FctType
  typedef void (*CLS1_StdIO_OutErr_FctType)(uint8_t); /* Callback for an output or error I/O function */
#endif
#ifndef __BWUserType_CLS1_StdIO_In_FctType
#define __BWUserType_CLS1_StdIO_In_FctType
  typedef void (*CLS1_StdIO_In_FctType)(uint8_t *); /* Callback for an I/O input function. */
#endif
#ifndef __BWUserType_CLS1_StdIO_KeyPressed_FctType
#define __BWUserType_CLS1_StdIO_KeyPressed_FctType
  typedef bool (*CLS1_StdIO_KeyPressed_FctType)(void); /* Callback which returns true if a key has been pressed */
#endif
#ifndef __BWUserType_CLS1_StdIOType
#define __BWUserType_CLS1_StdIOType
  typedef struct {                     /* Record containing input, output and error callback (stdin, stdout, stderr). */
    CLS1_StdIO_In_FctType stdIn;       /* standard input */
    CLS1_StdIO_OutErr_FctType stdOut;  /* standard output */
    CLS1_StdIO_OutErr_FctType stdErr;  /* standard error */
    CLS1_StdIO_KeyPressed_FctType keyPressed; /* key pressed callback */
  } CLS1_StdIOType;
#endif
#ifndef __BWUserType_CLS1_ConstStdIOType
#define __BWUserType_CLS1_ConstStdIOType
  typedef const CLS1_StdIOType CLS1_ConstStdIOType; /* constant StdIOType */
#endif
#ifndef __BWUserType_CLS1_ParseCommandCallback
#define __BWUserType_CLS1_ParseCommandCallback
  typedef uint8_t (*CLS1_ParseCommandCallback)(const uint8_t *cmd, bool *handled, const CLS1_StdIOType *io); /* Callback for parsing a shell command */
#endif
#ifndef __BWUserType_CLS1_ConstStdIOTypePtr
#define __BWUserType_CLS1_ConstStdIOTypePtr
  typedef const CLS1_ConstStdIOType *CLS1_ConstStdIOTypePtr; /* Pointer to constant standard I/O descriptor */
#endif
#ifndef __BWUserType_CLS1_ConstParseCommandCallback
#define __BWUserType_CLS1_ConstParseCommandCallback
  typedef const CLS1_ParseCommandCallback CLS1_ConstParseCommandCallback; /* Callback for parsing a shell command */
#endif


/* settings for command line history */
#define CLS1_HISTORY_ENABLED  0        /* 1: enabled, 0: disabled */
#define CLS1_NOF_HISTORY      0        /* number of items in history */
#define CLS1_HIST_LEN         0        /* history buffer size */

/* settings for silent prefix char */
#define CLS1_SILENT_PREFIX_CHAR    '#' /* with this char as first character in the cmd, printing is silent. Use a space to disable it */
#define CLS1_NO_SILENT_PREFIX_CHAR ' ' /* used for no silent prefix char */
#define CLS1_SILENT_PREFIX_CHAR_ENABLED (CLS1_SILENT_PREFIX_CHAR != CLS1_NO_SILENT_PREFIX_CHAR)

/* multi command support */
#define CLS1_MULTI_CMD_ENABLED   0 /* 1: enabled, 0: disabled */
#define CLS1_MULTI_CMD_SIZE      0 /* max size of each command */
#define CLS1_MULTI_CMD_CHAR      ';' /* separation character */

/* settings for local echo */
#define CLS1_ECHO_ENABLED  0           /* 1: enabled, 0: disabled */

#define CLS1_DEFAULT_SERIAL  1 /* If set to 1, then the shell implements its own StdIO which is returned by CLS1_GetStdio(); */

#define CLS1_DASH_LINE "--------------------------------------------------------------"
/* predefined commands */
#define CLS1_CMD_HELP   "help"
#define CLS1_CMD_STATUS "status"
void CLS1_SendStr(const uint8_t *str, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendStr (component Shell)
**     Description :
**         Prints a string using an I/O function
**     Parameters  :
**         NAME            - DESCRIPTION
**       * str             - Pointer to string (zero terminated) to be
**                           printed.
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

uint8_t CLS1_ParseCommand(const uint8_t *cmd, bool *handled, CLS1_ConstStdIOType *io);
/*
** ===================================================================
**     Method      :  CLS1_ParseCommand (component Shell)
**     Description :
**         Parses a shell command. Use 'help' to get a list of
**         supported commands.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command string
**       * handled         - Pointer to variable to indicate if
**                           the command has been handled. The caller
**                           passes this variable to the command scanner
**                           to find out if the passed command has been
**                           handled. The variable is initialized by the
**                           caller.
**       * io              - Pointer to I/O callbacks
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void CLS1_SendNum32s(int32_t val, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendNum32s (component Shell)
**     Description :
**         Sends a 32bit signed number to the given I/O
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - number to print
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_SendNum16s(int16_t val, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendNum16s (component Shell)
**     Description :
**         Sends a 16bit signed number to the given I/O
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - number to print
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_PrintPrompt(CLS1_ConstStdIOType *io);
/*
** ===================================================================
**     Method      :  CLS1_PrintPrompt (component Shell)
**     Description :
**         Prints the prompt to the stdOut channel
**     Parameters  :
**         NAME            - DESCRIPTION
**       * io              - Pointer to IO to be used
**     Returns     : Nothing
** ===================================================================
*/

bool CLS1_ReadLine(uint8_t *bufStart, uint8_t *buf, size_t bufSize, CLS1_ConstStdIOType *io);
/*
** ===================================================================
**     Method      :  CLS1_ReadLine (component Shell)
**     Description :
**         Reads a line from stdIn and returns TRUE if we have a line,
**         FALSE otherwise.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * bufStart        - Pointer to start of buffer
**       * buf             - Pointer to buffer where to read in the
**                           information
**         bufSize         - size of buffer
**       * io              - Pointer to I/O callbacks
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t CLS1_PrintStatus(CLS1_ConstStdIOType *io);
/*
** ===================================================================
**     Method      :  CLS1_PrintStatus (component Shell)
**     Description :
**         Prints various available system status information
**     Parameters  :
**         NAME            - DESCRIPTION
**       * io              - Pointer to I/O callbacks
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void CLS1_PrintCommandFailed(const uint8_t *cmd, CLS1_ConstStdIOType *io);
/*
** ===================================================================
**     Method      :  CLS1_PrintCommandFailed (component Shell)
**     Description :
**         Prints a standard message for failed or unknown commands
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command which was failing
**       * io              - Pointer to I/O callbacks
**     Returns     : Nothing
** ===================================================================
*/

uint8_t CLS1_ParseWithCommandTable(const uint8_t *cmd, CLS1_ConstStdIOType *io, CLS1_ConstParseCommandCallback *parseCallback);
/*
** ===================================================================
**     Method      :  CLS1_ParseWithCommandTable (component Shell)
**     Description :
**         Parses a shell command. It handles first the internal
**         commands and will call the provided callback.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command string
**       * io              - Pointer to I/O callbacks
**       * parseCallback   - Pointer to callback
**                           which will be called to parse commands in
**                           the user application, or NULL if not used.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

CLS1_ConstStdIOTypePtr CLS1_GetStdio(void);
/*
** ===================================================================
**     Method      :  CLS1_GetStdio (component Shell)
**     Description :
**         Returns the default stdio channel. This method is only
**         available if a shell is enabled in the component properties.
**     Parameters  : None
**     Returns     :
**         ---             - Pointer to the stdio descriptor
** ===================================================================
*/

void CLS1_SendNum32u(uint32_t val, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendNum32u (component Shell)
**     Description :
**         Sends a 32bit unsigned number to the given I/O
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - number to print
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_SendNum16u(uint16_t val, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendNum16u (component Shell)
**     Description :
**         Sends a 16bit unsigned number to the given I/O
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - number to print
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_SendNum8u(uint8_t val, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendNum8u (component Shell)
**     Description :
**         Sends an 8bit unsigned number to the given I/O
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - number to print
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_SendNum8s(int8_t val, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendNum8s (component Shell)
**     Description :
**         Sends an 8bit signed number to the given I/O
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - number to print
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_Init(void);
/*
** ===================================================================
**     Method      :  CLS1_Init (component Shell)
**     Description :
**         Initializes the module, especially creates the mutex
**         semaphore if an RTOS is used.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_RequestSerial(void);
/*
** ===================================================================
**     Method      :  CLS1_RequestSerial (component Shell)
**     Description :
**         Used to get mutual access to the shell console. Only has an
**         effect if using an RTOS with semaphore for the console
**         access.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_ReleaseSerial(void);
/*
** ===================================================================
**     Method      :  CLS1_ReleaseSerial (component Shell)
**     Description :
**         Used to release mutual access to the shell console. Only has
**         an effect if using an RTOS with semaphore for the console
**         access.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_SendHelpStr(const uint8_t *strCmd, const uint8_t *strHelp, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendHelpStr (component Shell)
**     Description :
**         Prints a string using an I/O function, formated for the
**         'help' command
**     Parameters  :
**         NAME            - DESCRIPTION
**       * strCmd          - Pointer to string of the command
**       * strHelp         - Pointer to help text string
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_SendStatusStr(const uint8_t *strItem, const uint8_t *strStatus, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendStatusStr (component Shell)
**     Description :
**         Prints a status string using an I/O function, formated for
**         the 'status' command
**     Parameters  :
**         NAME            - DESCRIPTION
**       * strItem         - Pointer to string of the command
**       * strStatus       - Pointer to help text string
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_ReadChar(uint8_t *c);
/*
** ===================================================================
**     Method      :  CLS1_ReadChar (component Shell)
**     Description :
**         Reads a character (blocking)
**     Parameters  :
**         NAME            - DESCRIPTION
**       * c               - Pointer to character to be used to store the
**                           result
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_SendChar(uint8_t ch);
/*
** ===================================================================
**     Method      :  CLS1_SendChar (component Shell)
**     Description :
**         Sends a character (blocking)
**     Parameters  :
**         NAME            - DESCRIPTION
**         ch              - character to be sent
**     Returns     : Nothing
** ===================================================================
*/

bool CLS1_KeyPressed(void);
/*
** ===================================================================
**     Method      :  CLS1_KeyPressed (component Shell)
**     Description :
**         Checks if a key has been pressed (a character is present in
**         the input buffer)
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void CLS1_Deinit(void);
/*
** ===================================================================
**     Method      :  CLS1_Deinit (component Shell)
**     Description :
**         De-Initializes the module, especially frees the mutex
**         semaphore if an RTOS is used.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void* CLS1_GetSemaphore(void);
/*
** ===================================================================
**     Method      :  CLS1_GetSemaphore (component Shell)
**     Description :
**         Return the semaphore of the shell.
**     Parameters  : None
**     Returns     :
**         ---             - semaphore, or NULL if not used or not
**                           allocated.
** ===================================================================
*/

uint8_t CLS1_ReadAndParseWithCommandTable(uint8_t *cmdBuf, size_t cmdBufSize, CLS1_ConstStdIOType *io, CLS1_ConstParseCommandCallback *parseCallback);
/*
** ===================================================================
**     Method      :  CLS1_ReadAndParseWithCommandTable (component Shell)
**     Description :
**         Reads characters from the default input channel and appends
**         it to the buffer. Once a new line has been detected, the
**         line will be parsed using the handlers in the table.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmdBuf          - Pointer to buffer provided by the
**                           caller where to store the command to read
**                           in. Characters will be appended, so make
**                           sure string buffer is initialized with a
**                           zero byte at the beginning.
**         cmdBufSize      - Size of buffer
**       * io              - Pointer to I/O channels to be used
**       * parseCallback   - Pointer to callback
**                           table provided by the user application to
**                           parse commands. The table has a NULL
**                           sentinel.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t CLS1_IterateTable(const uint8_t *cmd, bool *handled, CLS1_ConstStdIOType *io, CLS1_ConstParseCommandCallback *parserTable);
/*
** ===================================================================
**     Method      :  CLS1_IterateTable (component Shell)
**     Description :
**         Parses a shell command. It handles first the internal
**         commands and will call the provided callback.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command string
**       * handled         - Pointer to boolean which is set to
**                           TRUE if a command parser has handled the
**                           command.
**       * io              - Pointer to I/O callbacks
**       * parserTable     - Pointer to callback which
**                           will be called to parse commands in the
**                           user application, or NULL if not used.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t CLS1_SetStdio(CLS1_ConstStdIOTypePtr stdio);
/*
** ===================================================================
**     Method      :  CLS1_SetStdio (component Shell)
**     Description :
**         Sets an StdIO structure which is returned by GetStdio()
**     Parameters  :
**         NAME            - DESCRIPTION
**         stdio           - New stdio structure to be used.
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

void CLS1_SendData(const uint8_t *data, uint16_t dataSize, CLS1_StdIO_OutErr_FctType io);
/*
** ===================================================================
**     Method      :  CLS1_SendData (component Shell)
**     Description :
**         Sends data using an I/O function. Unlike SendStr(), with
**         this method it is possible to send binary data, including
**         zero bytes.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * data            - Pointer to data to be sent
**         dataSize        - Number of bytes to be sent.
**         io              - I/O callbacks to be used for printing.
**     Returns     : Nothing
** ===================================================================
*/

/* END CLS1. */

#endif
/* ifndef __CLS1_H */
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
