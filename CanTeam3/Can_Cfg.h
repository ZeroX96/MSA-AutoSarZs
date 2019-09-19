/***************************************************************
* Module:      Can controller
* File Name:   Can_Cfg.h
* Description: Header file for Can controller Module,
*              implementation is based on AUTOSAR specfications.
* Author:      Abdulmaguid Eissa, Team(3) Sokara
* Date:        Sept 14, 2019
****************************************************************/

#ifndef CAN_CFG_H
#define CAN_CFG_H

/*
* SW Module Version is 1.0.0
*/
#define CAN_CFG_SW_MAJOR_VERSION          (1U)
#define CAN_CFG_SW_MINOR_VERSION          (0U)
#define CAN_CFG_SW_PATCH_VERSION          (0U)

/*
* AUTOSAR Version is 4.3.1 compatible
*/
#define CAN_CFG_AR_RELEASE_MAJOR_VERSION  (4U)
#define CAN_CFG_AR_RELEASE_MINOR_VERSION  (3U)
#define CAN_CFG_AR_RELEASE_PATCH_VERSION  (1U)

/* Precompile option for Development Error Detect */
#define CAN_DEV_ERROR_DETECT              (STD_ON)

/* Precompile user configuration */
#define CAN_MAIN_FUNCTION_WRITE_PERIOD    (PERIOD_10)

/* Can transmission processing type */
#define CAN_TX_PROCESSING                 (POLLING)

/* Can controller Id, if multiple controllers are supported by 
   the used hardware */
#define CAN_CONTROLLER_ID                 (2U)

/* Enables polling of this hardware object. */
#if (CAN_TX_PROCESSING == MIXED)
#define CAN_HARDWARE_OBJECT_USES_POLLING (TRUE)
#endif

#endif /* CAN_CFG_H */