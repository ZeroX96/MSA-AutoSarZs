/*
 * Can_Irq.c
 *
 *  Date	: Sep 15, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */

/* REQ
 * All software modules shall provide version and identification information
 * Can_Irq   V0.0.0
 * AUTOSAR   V4.3.1
 */
/******************module******************/
#define CAN_IRQ_MAJOR_VERSION   0
#define CAN_IRQ_MINOR_VERSION   0
#define CAN_IRQ_PATCH_VERSION   0
/******************autosar******************/
#define CAN_IRQ_AR_MAJOR_VERSION   4
#define CAN_IRQ_AR_MINOR_VERSION   3
#define CAN_IRQ_AR_PATCH_VERSION   1

#include "Os.h"

/* REQ
 * All Basic SW Modules shall perform a pre-processor check
 * of the versions of all imported include files
 */
/*checking the autosar version*/
#if((CAN_IRQ_AR_MAJOR_VERSION != OS_AR_MAJOR_VERSION)||\
    (CAN_IRQ_AR_MINOR_VERSION != OS_AR_MINOR_VERSION)||\
    (CAN_IRQ_AR_PATCH_VERSION != OS_AR_PATCH_VERSION))
  #error "The AR version of Can_Irq.h differ than Os.h"

#endif
