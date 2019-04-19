/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuQuadCounter.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : QuadCounter
**     Version     : Component 01.031, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-01-12, 20:26, # CodeGen: 372
**     Abstract    :
**
This driver implements a quadrature encoder using two signals (C1 and C2) to generate position information.
**     Settings    :
**          Component name                                 : McuQuadCounter
**          C1 and C2 swapped                              : no
**          Counter Type                                   : 32bit
**          Method                                         : 
**            Sampling                                     : Enabled
**              Error Correction                           : no
**              C1                                         : SDK_BitIO
**              C2                                         : SDK_BitIO
**            Input Capture                                : Disabled
**          Shell                                          : Enabled
**            Shell                                        : McuShell
**            Utility                                      : McuUtility
**     Contents    :
**         GetPos       - McuQuadCounter_QuadCntrType McuQuadCounter_GetPos(void);
**         SetPos       - void McuQuadCounter_SetPos(McuQuadCounter_QuadCntrType pos);
**         GetVal       - uint8_t McuQuadCounter_GetVal(void);
**         Sample       - void McuQuadCounter_Sample(void);
**         Deinit       - void McuQuadCounter_Deinit(void);
**         Init         - void McuQuadCounter_Init(void);
**         ParseCommand - uint8_t McuQuadCounter_ParseCommand(const unsigned char *cmd, bool *handled,...
**
** License   :  Open Source (LGPL)
** Copyright : (c) Copyright Erich Styger, 2014, all rights reserved.
** 
** This an open source software using Processor Expert.
** This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
** * This is a free software and there is NO WARRANTY.
** * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
** * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file McuQuadCounter.h
** @version 01.00
** @brief
**
This driver implements a quadrature encoder using two signals (C1 and C2) to generate position information.
*/         
/*!
**  @addtogroup McuQuadCounter_module McuQuadCounter module documentation
**  @{
*/         

#ifndef __McuQuadCounter_H
#define __McuQuadCounter_H

/* MODULE McuQuadCounter. */
#include "McuLib.h" /* SDK and API used */
#include "McuQuadCounterconfig.h" /* configuration */

/* Include inherited components */
#include "C11.h"
#include "C21.h"
#include "McuShell.h"
#include "McuUtility.h"
#include "McuLib.h"


#define McuQuadCounter_SWAP_PINS  0 /* 1: C1 and C2 are swapped */
#define McuQuadCounter_SWAP_PINS_AT_RUNTIME  0 /* 1: C1 and C2 are swapped at runtime, if SwapPins() method is available */
#define McuQuadCounter_GET_C1_PIN()      (C11_GetVal())
#define McuQuadCounter_GET_C2_PIN()      (C21_GetVal())
#if McuQuadCounter_SWAP_PINS
  #define McuQuadCounter_GET_C1_C2_PINS()               ((McuQuadCounter_GET_C2_PIN()!=0?2:0)|(McuQuadCounter_GET_C1_PIN()!=0?1:0))
  #define McuQuadCounter_GET_C1_C2_PINS_SWAPPED()       ((McuQuadCounter_GET_C1_PIN()!=0?2:0)|(McuQuadCounter_GET_C2_PIN()!=0?1:0))
#else
  #define McuQuadCounter_GET_C1_C2_PINS()               ((McuQuadCounter_GET_C1_PIN()!=0?2:0)|(McuQuadCounter_GET_C2_PIN()!=0?1:0))
  #define McuQuadCounter_GET_C1_C2_PINS_SWAPPED()       ((McuQuadCounter_GET_C2_PIN()!=0?2:0)|(McuQuadCounter_GET_C1_PIN()!=0?1:0))
#endif

typedef uint32_t McuQuadCounter_QuadCntrType;
#define McuQuadCounter_CNTR_BITS  32
  /*!< Number of bits in counter */

#define McuQuadCounter_PARSE_COMMAND_ENABLED  1  /* set to 1 if method ParseCommand() is present, 0 otherwise */


void McuQuadCounter_SetPos(McuQuadCounter_QuadCntrType pos);
/*
** ===================================================================
**     Method      :  SetPos (component QuadCounter)
**
**     Description :
**         Sets the position information. Can be used as well to reset
**         the position information.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pos             - Position value to be set.
**     Returns     : Nothing
** ===================================================================
*/

McuQuadCounter_QuadCntrType McuQuadCounter_GetPos(void);
/*
** ===================================================================
**     Method      :  GetPos (component QuadCounter)
**
**     Description :
**         Returns the current position based on the encoder tracking.
**     Parameters  : None
**     Returns     :
**         ---             - position
** ===================================================================
*/

void McuQuadCounter_Sample(void);
/*
** ===================================================================
**     Method      :  Sample (component QuadCounter)
**
**     Description :
**         Call this method to periodically sample the signals.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuQuadCounter_Deinit(void);
/*
** ===================================================================
**     Method      :  Deinit (component QuadCounter)
**
**     Description :
**         Module de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void McuQuadCounter_Init(void);
/*
** ===================================================================
**     Method      :  Init (component QuadCounter)
**
**     Description :
**         Module initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

uint8_t McuQuadCounter_ParseCommand(const unsigned char *cmd, bool *handled, const McuShell_StdIOType *io);
/*
** ===================================================================
**     Method      :  ParseCommand (component QuadCounter)
**
**     Description :
**         Handler to process shell commands
**     Parameters  :
**         NAME            - DESCRIPTION
**         cmd             - Command string to be parsed
**       * handled         - Pointer to boolean. The handler
**                           sets this variable to TRUE if command was
**                           handled, otherwise let it untouched.
**         io              - Pointer to I/O structure
**     Returns     :
**         ---             - Error code
** ===================================================================
*/

uint8_t McuQuadCounter_GetVal(void);
/*
** ===================================================================
**     Method      :  GetVal (component QuadCounter)
**
**     Description :
**         Returns the quadrature value (0, 1, 2 or 3)
**     Parameters  : None
**     Returns     :
**         ---             - Quadrature value (0-3)
** ===================================================================
*/

/* END McuQuadCounter. */

#endif
/* ifndef __McuQuadCounter_H */
/*!
** @}
*/
