/*
 * Platform_Types.h
 *
 *  Created on: Aug 25, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */
#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


/* REQ
 * All software modules shall provide version and identification information
 * pLATFORM_Types V0.0.0
 * AUTOSAR   V4.3.1
 */
/******************module******************/
#define PLATFORM_TYPES_MAJOR_VERSION   0
#define PLATFORM_TYPES_MINOR_VERSION   0
#define PLATFORM_TYPES_PATCH_VERSION   0
/******************autosar******************/
#define PLATFORM_TYPES_AR_MAJOR_VERSION   4
#define PLATFORM_TYPES_AR_MINOR_VERSION   3
#define PLATFORM_TYPES_AR_PATCH_VERSION   1

////////************************************************************************************************************************************
/*According to the register width of the CPU used,
 * CPU_TYPE shall be assigned to one of the symbols CPU_TYPE_8, CPU_TYPE_16,
 * CPU_TYPE_32 or CPU_TYPE_64.*/
#define CPU_TYPE_8      8u
#define CPU_TYPE_16     16u
#define CPU_TYPE_32     32u
#define CPU_TYPE_64     64u

/*
 * In case of big endian bit ordering CPU_BIT_ORDER shall
 * be assigned to MSB_FIRST in the platform types header file.
 * else little endian >> LSB_FIRST
 */
#define MSB_FIRST   0u
#define LSB_FIRST   1u

/*
 * In case of big endian byte ordering CPU_BYTE_ORDER shall
 * be assigned to HIGH_BYTE_FIRST in the platform types header file.
 * else little endian >> LOW_BYTE_FIRST
 */
#define HIGH_BYTE_FIRST   0u
#define LOW_BYTE_FIRST    1u
/*For each platform the register width of the CPU used
 * shall be indicated by defining CPU_TYPE.*/
#define CPU_TYPE    CPU_TYPE_32     //according to tiva-c

/*For each platform the appropriate bit order on register level
 * shall be indicated in the platform types header file using the symbol
 * CPU_BIT_ORDER.*/
#define CPU_BIT_ORDER   LSB_FIRST

/*For each platform the appropriate byte order on memory
 * level shall be indicated in the platform types header file using the symbol
 * CPU_BYTE_ORDER. */
#define CPU_BYTE_ORDER  LOW_BYTE_FIRST

/*The standard AUTOSAR type boolean shall be implemented as an unsigned integer
 *  with a bit length that is the shortest one natively supported by the platform
 *  (in general 8 bits)*/
typedef unsigned char boolean;

typedef unsigned char   uint8;
typedef signed   char   sint8;
typedef unsigned short  uint16;
typedef signed   short  sint16;
typedef unsigned int    uint32;
typedef signed   int    sint32;
typedef unsigned long   uint64;
typedef signed   long   sint64;


typedef unsigned char   uint8_least;
typedef signed   char   sint8_least;
typedef unsigned short  uint16_least;
typedef signed   short  sint16_least;
typedef unsigned int    uint32_least;
typedef signed   int    sint32_least;
typedef unsigned long   uint64_least;
typedef signed   long   sint64_least;


typedef          float  float32;
typedef          double float64;

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#endif /* PLATFORM_TYPES_H_ */
