/*
 * Det.h
 *
 *  Created on: Aug 25, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */
#ifndef DET_H_
#define DET_H_

/*
 * Det Software Module Version 0.0.0
 */
#define DET_MAJOR_VERSION          0
#define DET_MINOR_VERSION          0
#define DET_PATCH_VERSION          0

/*
 * AUTOSAR Version 4.3.1
 */
#define DET_AR_MAJOR_VERSION          4
#define DET_AR_MINOR_VERSION          3
#define DET_AR_PATCH_VERSION          1

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Det Modules */
#if ((DET_AR_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

void Det_ReportError( uint8 ModuleId,uint8 InstanceId,uint8 ErrorId );


#endif /* DET_H_ */
