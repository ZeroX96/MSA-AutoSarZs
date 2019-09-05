/*
 * Compiler.h
 *
 *  Date    : Aug 25, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */

#ifndef COMPILER_H_
#define COMPILER_H_

/* REQ
 * All software modules shall provide version and identification information
 * Compiler V0.0.0
 * AUTOSAR V4.3.1
 */
/******************module******************/
#define COMPILER_MAJOR_VERSION   0
#define COMPILER_MINOR_VERSION   0
#define COMPILER_PATCH_VERSION   0
/******************autosar******************/
#define COMPILER_AR_MAJOR_VERSION   4
#define COMPILER_AR_MINOR_VERSION   3
#define COMPILER_AR_PATCH_VERSION   1

#include "Compiler_Cfg.h"

/* REQ
 * All Basic SW Modules shall perform a pre-processor check
 * of the versions of all imported include files
 */
/*checking the autosar version*/
#if ((COMPILER_AR_MAJOR_VERSION != COMPILER_CFG_AR_MAJOR_VERSION)||\
    (COMPILER_AR_MINOR_VERSION != COMPILER_CFG_AR_MINOR_VERSION)||\
    (COMPILER_AR_PATCH_VERSION != COMPILER_CFG_AR_PATCH_VERSION))
#endif
/*checking the software module version*/
#if((COMPILER_MAJOR_VERSION != COMPILER_CFG_MAJOR_VERSION)||\
    (COMPILER_MINOR_VERSION != COMPILER_CFG_MINOR_VERSION)||\
    (COMPILER_PATCH_VERSION != COMPILER_CFG_PATCH_VERSION))
#endif

#define _TEXAS_INSTRUMENTS_C_ARM_

/*
 * If a compiler does not require or support the usage of special keywords;
 *  the corresponding macros specified by this specification shall be
 *   provided as empty definitions or definitions without effect.
 */
/* The memory class AUTOMATIC shall be provided as empty definition*/
#define AUTOMATIC

/* The memory class TYPEDEF shall be provided as empty definition*/
#define TYPEDEF typedef

/*The NULL_PTR define with a void pointer to zero definition.*/
#define NULL_PTR ((void *)0)

/*he INLINE define for abstraction of the keyword inline.*/
#define INLINE inline

/* The compiler abstraction shall provide the LOCAL_INLINE define for abstraction
   of the keyword inline in functions with “static” scope.
 */
#define LOCAL_INLINE static inline

#endif /* COMPILER_H_ */
