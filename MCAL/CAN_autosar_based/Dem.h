/*
 * Dem.h
 *
 *  Date	: Sep 15, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */
#ifndef DEM_H_
#define DEM_H_

/* REQ
 * All software modules shall provide version and identification information
 * Dem_IntErrorId       V0.0.0
 * AUTOSAR              V4.3.1
 */
/******************module******************/
#define DEM_MAJOR_VERSION   0
#define DEM_MINOR_VERSION   0
#define DEM_PATCH_VERSION   0
/******************autosar******************/
#define DEM_AR_MAJOR_VERSION   4
#define DEM_AR_MINOR_VERSION   3
#define DEM_AR_PATCH_VERSION   1

/* Standard AUTOSAR types */
#include "Dem_IntErrorId.h"

/* AUTOSAR checking between Std Types and Det Modules */
#if ((DEM_AR_MAJOR_VERSION != DEM_INTERRORID_AR_MAJOR_VERSION)\
 || (DEM_AR_MINOR_VERSION !=  DEM_INTERRORID_AR_MINOR_VERSION)\
 || (DEM_AR_PATCH_VERSION !=  DEM_INTERRORID_AR_PATCH_VERSION))
  #error "The AR version of Det.h differ than Std_Types.h"
#endif



#endif /* DEM_H_ */
