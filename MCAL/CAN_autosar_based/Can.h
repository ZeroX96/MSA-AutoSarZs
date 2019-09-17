/*
 * Can.h
 *
 *  Date	: Sep 15, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */
#ifndef CAN_H_
#define CAN_H_

/* REQ
 * All software modules shall provide version and identification information
 * ComStack_Types   V0.0.0
 * AUTOSAR          V4.3.1
 */
/******************module******************/
#define CAN_MAJOR_VERSION   0
#define CAN_MINOR_VERSION   0
#define CAN_PATCH_VERSION   0
/******************autosar******************/
#define CAN_AR_MAJOR_VERSION   4
#define CAN_AR_MINOR_VERSION   3
#define CAN_AR_PATCH_VERSION   1

#include "Can_Cfg.h"
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
/* REQ
 * All Basic SW Modules shall perform a pre-processor check
 * of the versions of all imported include files
 */
/*checking the autosar Can_Cfg version*/
#if((CAN_AR_MAJOR_VERSION != CAN_CFG_AR_MAJOR_VERSION)||\
    (CAN_AR_MINOR_VERSION != CAN_CFG_AR_MINOR_VERSION)||\
    (CAN_AR_PATCH_VERSION != CAN_CFG_AR_PATCH_VERSION))
  #error "The AR version of Can.h differ than Can_Cfg.h"
#endif
/*checking the autosar ComStack_Types version*/
#if((CAN_AR_MAJOR_VERSION != COMSTACK_TYPES_AR_MAJOR_VERSION)||\
    (CAN_AR_MINOR_VERSION != COMSTACK_TYPES_AR_MINOR_VERSION)||\
    (CAN_AR_PATCH_VERSION != COMSTACK_TYPES_AR_PATCH_VERSION))
  #error "The AR version of Can.h differ than ComStack_Types.h"
#endif
/*checking the autosar Can_GeneralTypes version*/
#if((CAN_AR_MAJOR_VERSION != CAN_GENERALTYPES_AR_MAJOR_VERSION)||\
    (CAN_AR_MINOR_VERSION != CAN_GENERALTYPES_AR_MINOR_VERSION)||\
    (CAN_AR_PATCH_VERSION != CAN_GENERALTYPES_AR_PATCH_VERSION))
  #error "The AR version of Can.h differ than Can_GeneralTypes.h"
#endif

#define CAN_CONTROLLERS_NUMB 2
//can module id
#define CAN_MODULE_ID               080U
/* CAN Driver Development Errors */


#define CAN_E_PARAM_POINTER         0x01
#define CAN_E_PARAM_HANDLE          0x02
#define CAN_E_PARAM_DATA_LENGTH     0x03
#define CAN_E_PARAM_CONTROLLER      0x04
#define CAN_E_UNINIT                0x05
#define CAN_E_TRANSITION            0x06
#define CAN_E_PARAM_BAUDRATE        0x07
#define CAN_E_ICOM_CONFIG_INVALID   0x08
#define CAN_E_INIT_FAILED           0x09

#define CAN_GET_CONTROLLER_MODE     0x12

/*CanTxProcessing
 *Enables / disables API Can_MainFunction_Write() for handling PDU transmission events in polling mode.
 * Range   INTERRUPT   Interrupt Mode of operation.
 * MIXED   Mixed Mode of operation
 * POLLING   Polling Mode of operation.
 * */
#define CanTxProcessing INTERRUPT
#define INTERRUPT 0x00
#define MIXED     0x01
#define POLLING   0x02

/*
 * Service name:  Can_MainFunction_Write
 * Service ID[hex]:  0x01
 * Description:  This function performs the polling of TX confirmation when
 * CAN_TX_PROCESSING is set to POLLING.
 * This function is directly called by the Basic Software Scheduler.
 */
void Can_MainFunction_Write(void,uint8);
/*
 * Service name:  Can_GetControllerMode
 * Service ID[hex]:  0x12
 * Sync/Async:  Synchronous
 * Reentrancy:  Non Reentrant
 * Parameters (in):   Controller  CAN controller for which the status shall be requested.
 * Parameters(inout): None
 * Parameters (out):  ControllerModePtr  Pointer to a memory location, where the current
 *                    mode of the CAN controller will be stored.
 * Return value:Std_ReturnType  E_OK: Controller mode request has been accepted.
 *                              E_NOT_OK: Controller mode request has not been accepted.
 * Description:This service reports about the current status of the requested CAN controller.
 * DevErrorTypes: CAN_E_PARAM_CONTROLLER
 *                CAN_E_UNINIT
*/
Std_ReturnType Can_GetControllerMode(uint8 Controller,Can_ControllerStateType* ControllerModePtr);

#endif /* CAN_H_ */
