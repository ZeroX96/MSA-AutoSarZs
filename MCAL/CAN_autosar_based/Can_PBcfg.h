/*
 * Can_PBcfg.h
 *
 *  Date	: Sep 15, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */
#ifndef CAN_PBCFG_H_
#define CAN_PBCFG_H_
/* REQ
 * All software modules shall provide version and identification information
 * ComStack_Types   V0.0.0
 * AUTOSAR          V4.3.1
 */
/******************module******************/
#define CAN_PBCFG_MAJOR_VERSION   0
#define CAN_PBCFG_MINOR_VERSION   0
#define CAN_PBCFG_PATCH_VERSION   0
/******************autosar******************/
#define CAN_PBCFG_AR_MAJOR_VERSION   4
#define CAN_PBCFG_AR_MINOR_VERSION   3
#define CAN_PBCFG_AR_PATCH_VERSION   1

#include "Can_Cfg.h"

/* REQ
 * All Basic SW Modules shall perform a pre-processor check
 * of the versions of all imported include files
 */
/*checking the autosar version*/
#if((CAN_PBCFG_AR_MAJOR_VERSION != CAN_CFG_AR_MAJOR_VERSION)||\
    (CAN_PBCFG_AR_MINOR_VERSION != CAN_CFG_AR_MINOR_VERSION)||\
    (CAN_PBCFG_AR_PATCH_VERSION != CAN_CFG_AR_PATCH_VERSION))
  #error "The AR version of Can_PBcfg.h differ than Can_Cfg.h"

#endif




#endif /* CAN_PBCFG_H_ */
