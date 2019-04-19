/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuLED4.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : LED
**     Version     : Component 01.076, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-02-16, 17:45, # CodeGen: 426
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : McuLED4
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            On/Off                                       : Enabled
**              Pin                                        : SDK_BitIO
**            PWM                                          : Disabled
**            High Value means ON                          : no
**          Shell                                          : Enabled
**            Shell                                        : McuShell
**            Utility                                      : McuUtility
**     Contents    :
**         On           - void McuLED4_On(void);
**         Off          - void McuLED4_Off(void);
**         Neg          - void McuLED4_Neg(void);
**         Get          - uint8_t McuLED4_Get(void);
**         Put          - void McuLED4_Put(uint8_t val);
**         SetRatio16   - void McuLED4_SetRatio16(uint16_t ratio);
**         ParseCommand - uint8_t McuLED4_ParseCommand(const unsigned char *cmd, bool *handled, const...
**         Deinit       - void McuLED4_Deinit(void);
**         Init         - void McuLED4_Init(void);
**
** * Copyright (c) 2013-2019, Erich Styger
**  * Web:         https://mcuoneclipse.com
**  * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**  * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**  * All rights reserved.
**  *
**  * Redistribution and use in source and binary forms, with or without modification,
**  * are permitted provided that the following conditions are met:
**  *
**  * - Redistributions of source code must retain the above copyright notice, this list
**  *   of conditions and the following disclaimer.
**  *
**  * - Redistributions in binary form must reproduce the above copyright notice, this
**  *   list of conditions and the following disclaimer in the documentation and/or
**  *   other materials provided with the distribution.
**  *
**  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**  * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuLED4.h
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup McuLED4_module McuLED4 module documentation
**  @{
*/         

/* MODULE McuLED4. */

#include "McuLED4.h"

static uint8_t PrintStatus(const McuShell_StdIOType *io) {
  McuShell_SendStatusStr((unsigned char*)"McuLED4", (unsigned char*)"\r\n", io->stdOut);
  if (McuLED4_Get()!=0) {
    McuShell_SendStatusStr((unsigned char*)"  on", (unsigned char*)"yes\r\n", io->stdOut);
  } else {
    McuShell_SendStatusStr((unsigned char*)"  on", (unsigned char*)"no\r\n", io->stdOut);
  }
  return ERR_OK;
}

static uint8_t PrintHelp(const McuShell_StdIOType *io) {
  McuShell_SendHelpStr((unsigned char*)"McuLED4", (unsigned char*)"Group of McuLED4 commands\r\n", io->stdOut);
  McuShell_SendHelpStr((unsigned char*)"  help|status", (unsigned char*)"Print help or status information\r\n", io->stdOut);
  McuShell_SendHelpStr((unsigned char*)"  on|off|neg", (unsigned char*)"Turns it on, off or toggle it\r\n", io->stdOut);
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  ParseCommand (component LED)
**
**     Description :
**         Shell Command Line parser. This method is enabled/disabled
**         depending on if you have the Shell enabled/disabled in the
**         properties.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * cmd             - Pointer to command string
**       * handled         - Pointer to variable which tells if
**                           the command has been handled or not
**       * io              - Pointer to I/O structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t McuLED4_ParseCommand(const unsigned char *cmd, bool *handled, const McuShell_StdIOType *io)
{
  if (McuUtility_strcmp((char*)cmd, McuShell_CMD_HELP)==0 || McuUtility_strcmp((char*)cmd, "McuLED4 help")==0) {
    *handled = TRUE;
    return PrintHelp(io);
  } else if ((McuUtility_strcmp((char*)cmd, McuShell_CMD_STATUS)==0) || (McuUtility_strcmp((char*)cmd, "McuLED4 status")==0)) {
    *handled = TRUE;
    return PrintStatus(io);
  } else if (McuUtility_strcmp((char*)cmd, "McuLED4 on")==0) {
    *handled = TRUE;
    McuLED4_On();
    return ERR_OK;
  } else if (McuUtility_strcmp((char*)cmd, "McuLED4 off")==0) {
    *handled = TRUE;
    McuLED4_Off();
    return ERR_OK;
  } else if (McuUtility_strcmp((char*)cmd, "McuLED4 neg")==0) {
    *handled = TRUE;
    McuLED4_Neg();
    return ERR_OK;
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  On (component LED)
**
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void McuLED4_On(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  Off (component LED)
**
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void McuLED4_Off(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  Neg (component LED)
**
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void McuLED4_Neg(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  Get (component LED)
**
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/
/*
uint8_t McuLED4_Get(void)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  Put (component LED)
**
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/
/*
void McuLED4_Put(uint8_t val)
{
  *** This method is implemented as macro in the header file
}
*/

/*
** ===================================================================
**     Method      :  Init (component LED)
**
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuLED4_Init(void)
{
#if McuLib_CONFIG_SDK_VERSION_USED != McuLib_CONFIG_SDK_PROCESSOR_EXPERT
  LEDpin4_Init();
#endif
  McuLED4_Off();
}

/*
** ===================================================================
**     Method      :  Deinit (component LED)
**
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void McuLED4_Deinit(void)
{
#if McuLib_CONFIG_SDK_VERSION_USED != McuLib_CONFIG_SDK_PROCESSOR_EXPERT
  LEDpin4_Deinit();
#endif
}

/*
** ===================================================================
**     Method      :  SetRatio16 (component LED)
**
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/
void McuLED4_SetRatio16(uint16_t ratio)
{
  /* on/off LED: binary on or off */
  if (ratio<(0xffff/2)) {
    McuLED4_Off();
  } else {
    McuLED4_On();
  }
}

/* END McuLED4. */

/*!
** @}
*/
