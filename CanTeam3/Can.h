/***************************************************************
* Module:      Can controller
* File Name:   Can.h
* Description: Header file for Can controller Module,
*              implementation is based on AUTOSAR specfications.
* Author:      Abdulmaguid Eissa, Team(3) Sokara
* Date:        Sept 14, 2019
****************************************************************/

#ifndef CAN_H
#define CAN_H

/* Id for the company in the AUTOSAR */
#define CAN_VENDOR_ID                          (03U)

/* Module Id */ 
#define CAN_MODULE_ID                          (080U)

/* Module Version 1.0.0 */
#define CAN_SW_MAJOR_VERSION                   (1U)
#define CAN_SW_MINOR_VERSION                   (0U)
#define CAN_SW_PATCH_VERSION                   (0U)

/* AUTOSAR Version 4.3.1 */
#define CAN_AR_RELEASE_MAJOR_VERSION           (4U)
#define CAN_AR_RELEASE_MINOR_VERSION           (3U)
#define CAN_AR_RELEASE_PATCH_VERSION           (1U)

/* AUTOSAR files inclusion */
#include "Std_Types.h"
/* Check compatibility of Can.h AUTOSAR version with
* Std_Types AUTOSAR version. */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif

#include "Can_GeneralTypes.h"
#if ((CAN_GENERAL_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_GENERAL_TYPES_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_GENERAL_TYPES_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Can_GeneralTypes.h does not match the expected version"
#endif

/**************************************************************
*                     Non AUTOSAR files                      *
**************************************************************/
/*
* Microcontroller specific configurations */
#include "tm4c123gh6pm.h"

/* Macros for hardware initializations */
#include "Bit_Manipulation.h"

/***************************************************************
*            API Service ID Macros (task related)              *
****************************************************************/
/*
  Can main function write service ID */
#define CAN_MAIN_FUNCTION_WRITE_SID                   ((uint8)0x01)
/* Can get controller mode service ID */
#define CAN_GET_CONTROLLER_MODE_SID                   ((uint8)0x12)

/***************************************************************
*               DET Error Codes (task related)                 *
****************************************************************/
/*
 API  Service  called  with wrong parameter */
#define CAN_E_PARAM_POINTER                           ((uint8)0x01)
#define CAN_E_PARAM_HANDLE							  ((uint8)0x02)
#define CAN_E_PARAM_DATA_LENGTH						  ((uint8)0x03)
#define CAN_E_PARAM_CONTROLLER						  ((uint8)0x04)
/* API Service used without initialization */		   
#define CAN_E_UNINIT                                  ((uint8)0x05) 

/***************************************************************
*             Module Data Types (task relatd)                  *
****************************************************************/

/* CAN controller state UNINIT. */
#define CAN_CS_UNINIT                  ((Can_ControllerStateType)0x00)
/* CAN controller state STARTED. */
#define CAN_CS_STARTED                 ((Can_ControllerStateType)0x01)
/* CAN controller state STOPPED. */
#define CAN_CS_STOPPED                 ((Can_ControllerStateType)0x02)
/* CAN controller state SLEEP. */
#define CAN_CS_SLEEP                   ((Can_ControllerStateType)0x03)

/***************************************************************
*           Can Processing Macros (task relatd)                *
****************************************************************/
/* Values related to the precompile configurations of 
  the CanTxProcessing. 
  Interrupt Mode of operation. */
#define INTERRUPT                      ((uint8)0)
/* Polling Mode of operation. */
#define POLLING                        ((uint8)1)
/* Mixed Mode of operation. */
#define MIXED                          ((uint8)2)
/* Two Can contorllers supported by Tivac 
   Can controller 0 */
#define CAN_CONTROLLER0                ((uint8)0)
/* Can controller 1*/
#define CAN_CONTROLLER1                ((uint8)1)
/* Supported periods for the main function write */
#define PERIOD0                 (0)
#define PERIOD1                 (1)
#define PERIOD2                 (2)
#define PERIOD3                 (3)
#define PERIOD4                 (4)
#define PERIOD5                 (5)
#define PERIOD6                 (6)
#define PERIOD7                 (7)
#define PERIOD8                 (8)
#define PERIOD9                 (9)
#define PERIOD10                (10)
/* Can controller hardware bits related to the functions
   implementations.
   TXOK polling bit for sucessful transmission.
. */
#define CANSTS_TXOK             (3)
/* Tivac supported Can controller modes.
   Initialization mode bit.
   0 Normal operation.
   1 Initialization started. */
#define CANCTL_INIT             (0)
/* 0 The CAN controller is operating normally. 
   1 The CAN controller is in test mode. */
#define CANCTL_TEST             (7)
/* 0 Loopback mode is disabled. 
   1 Loopback mode is enabled. In loopback mode, the data
   from the transmitter is routed into the receiver. Any data
   on the receive input is ignored. */
#define CANTST_LBACK            (4)
/* 0 Silent mode is disabled. 
   1 Silent mode is enabled. In silent mode, the CAN controller
     does not transmit data but instead monitors the bus. This
     mode is also known as Bus Monitor mode. */
#define CANTST_SILENT           (3)
/* 0 Basic mode is disabled. 
   1 Basic mode is enabled. In basic mode, software should
   use the CANIF1 registers as the transmit buffer and use
   the CANIF2 registers as the receive buffer. */
#define CANTST_BASIC            (2)

#include "Can_Cfg.h"
/* Check compatibility of Can.h AUTOSAR version with
* Can_Cfg AUTOSAR version. */
#if ((CAN_CFG_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (CAN_CFG_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (CAN_CFG_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Can_Cfg.h does not match the expected version"
#endif

/***************************************************************
*          Functions Prototypes (task related)                 *
****************************************************************/
/* Empty definition of the main function write to be executed if
   the POLLING is not defined as CanTxProcessing. */
#define CanMainFunctionWriteDef()         {}

/***************************************************************
* Service Name:       Can_GetControllerMode 
* Service ID[hex]:    0x12
* Sync/Async:         Synchronous
* Reentrancy:         Non reentrant
* Parameters (in):    Controller CAN controller for which the status 
                      shall be requested. 
* Parameters (inout): None
* Parameters (out):   ControllerModePtr  Pointer to a memory location, 
                      where the current mode of the CAN controller 
					  will be stored.
* Return value:       Std_ReturnType  E_OK: Controller mode request has 
                                            been accepted. 
                                      E_NOT_OK: Controller mode 
									            request has not been
* Description:        This service reports about the current status
                      of the requested CAN controller. 
****************************************************************/
Std_ReturnType Can_GetControllerMode(uint8 Controller,
	Can_ControllerStateType* ControllerModePtr);

/***************************************************************
* Service Name:    Can_MainFunction_Write 
* Service ID[hex]: 0x01
* Description:     This function performs the polling of TX confirmation
                   when CAN_TX_PROCESSING is set to POLLING. 
* NOTE:            Calling this function is according to the required
                   period cycles, (0, 1, 2,...)
****************************************************************/
void Can_MainFunction_Write(void);
void Can_MainFunction_Write_0(void);
void Can_MainFunction_Write_1(void);
void Can_MainFunction_Write_2(void);
void Can_MainFunction_Write_3(void);
void Can_MainFunction_Write_4(void);
void Can_MainFunction_Write_5(void);
void Can_MainFunction_Write_6(void);
void Can_MainFunction_Write_7(void);
void Can_MainFunction_Write_8(void);
void Can_MainFunction_Write_9(void);
void Can_MainFunction_Write_10(void);


#endif /* CAN_H */