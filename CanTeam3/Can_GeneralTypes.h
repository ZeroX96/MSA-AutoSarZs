/***************************************************************
* Module:      Can controller  
* File Name:   Can_GeneralTypes.h
* Description: Header file for Can controller Module, 
*              implementation is based on AUTOSAR specfications.
* Author:      Abdulmaguid Eissa, Team(3) Sokara
* Date:        Sept 13, 2019
****************************************************************/

#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

/* Module Version 1.0.0 */
#define CAN_GENERAL_TYPES_SW_MAJOR_VERSION                   (1U)
#define CAN_GENERAL_TYPES_SW_MINOR_VERSION                   (0U)
#define CAN_GENERAL_TYPES_SW_PATCH_VERSION                   (0U)

/* AUTOSAR Version 4.3.1 */
#define CAN_GENERAL_TYPES_AR_RELEASE_MAJOR_VERSION           (4U)
#define CAN_GENERAL_TYPES_AR_RELEASE_MINOR_VERSION           (3U)
#define CAN_GENERAL_TYPES_AR_RELEASE_PATCH_VERSION           (1U)

/* The current state/mode of the Can controller.
   Modes such as:
		initialization,
		bus error,
		test,
		normal,
		loopback,
		silent/bus monitor and basic mode */
typedef uint8 Can_ControllerStateType; 




#endif /* CAN_GENERAL_TYPES_H */
