/*
 * Std_Types.h
 *
 *  Created on: Aug 25, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* REQ
 * All software modules shall provide version and identification information
 * Std_Types V0.0.0
 * AUTOSAR   V4.3.1
 */
/******************module******************/
#define STD_TYPES_MAJOR_VERSION   0
#define STD_TYPES_MINOR_VERSION   0
#define STD_TYPES_PATCH_VERSION   0
/******************autosar******************/
#define STD_TYPES_AR_MAJOR_VERSION   4
#define STD_TYPES_AR_MINOR_VERSION   3
#define STD_TYPES_AR_PATCH_VERSION   1

#include "Compiler.h"
#include "Platform_Types.h"

/* REQ
 * All Basic SW Modules shall perform a pre-processor check
 * of the versions of all imported include files
 */
/*checking the autosar version*/
#if((STD_TYPES_AR_MAJOR_VERSION != COMPILER_AR_MAJOR_VERSION)||\
    (STD_TYPES_AR_MINOR_VERSION != COMPILER_AR_MINOR_VERSION)||\
    (STD_TYPES_AR_PATCH_VERSION != COMPILER_AR_PATCH_VERSION))
  #error "The AR version of Std_Types.h differ than compiler.h"
#endif
/*checking the autosar version*/
#if((STD_TYPES_AR_MAJOR_VERSION != PLATFORM_TYPES_AR_MAJOR_VERSION)||\
    (STD_TYPES_AR_MINOR_VERSION != PLATFORM_TYPES_AR_MINOR_VERSION)||\
    (STD_TYPES_AR_PATCH_VERSION != PLATFORM_TYPES_AR_PATCH_VERSION))
  #error "The AR version of Std_Types.h differ than platform_types.h"
#endif


/*
 * This type can be used as standard API return type
 * which is shared between the RTE and the BSW modules.
 * E_OK       0  see 8.2.1, SWS_Std_00006
 * E_NOT_OK   1  see 8.2.1, SWS_Std_00006
 * 0x02-0x3F  2  Available to user specific errors
 */
typedef uint8 Std_ReturnType;
/*
 * This type shall be used to request the version of a BSW module
 * using the <Module name>_GetVersionInfo() function.
 */
typedef struct
{
    uint16  vendorID;
    uint16  moduleID;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
}Std_VersionInfoType;

/*
 * E_OK is already defined within OSEK, the symbol E_OK has to be
 * shared. To avoid name clashes and redefinition problems, the symbols
 * have to be defined in the following way.
*/
#ifndef E_OK
#define E_OK 0x00u;
#endif

#define E_NOT_OK 0x01u;

#define STD_HIGH 0x01u      /* Physical state 5V or 3.3V */
#define STD_LOW  0x00u      /* Physical state 0V */

#define STD_ACTIVE 0x01u    /* Logical state active */
#define STD_IDLE 0x00u      /* Logical state idle */

#define STD_ON 0x01u
#define STD_OFF 0x00u
#endif /* STD_TYPES_H_ */
