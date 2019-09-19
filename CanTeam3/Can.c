/***************************************************************
* Module:      Can controller
* File Name:   Can.c
* Description: Source file for Can controller Module implementations,
*              implementation is based on AUTOSAR specfications.
* Author:      Abdulmaguid Eissa, Team(3) Sokara
* Date:        Sept 15, 2019
****************************************************************/

#include "Can.h"

#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
/* AUTOSAR version checking */
#if ((DET_AR_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
 ||  (DET_AR_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
 ||  (DET_AR_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif /* AUTOSAR version checking */

/* SW module version checking */
#if ((DET_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
 ||  (DET_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
 ||  (DET_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif /* SW module version checking */
#endif /* (DET_DEV_ERROR_DETECT == STD_ON) */

#include "SchM_Can.h"

/***************************************************************/
/*           Private Functions Declarations                    */
/***************************************************************/
/*
	Local function to check on the TXOK bit for specified 
	period/time tick.
*/
STATIC void CanMainFunctionTxPolling(uint8 can_controller_id);
STATIC void CanMainFunctionTxProcessing(void);

/***************************************************************/
/*            Private Globals Declarations                     */
/***************************************************************/
STATIC uint32 * CanStatusRegister_Ptr = NULL_PTR;
STATIC uint32 * CanControlRegister_Ptr = NULL_PTR;
STATIC uint8 CanModes[CAN_CONTROLLER_ID] = {CAN_CS_UNINIT,
											CAN_CS_UNINIT};
/* Global flag to inform of sucessful transmission from the 
   Can_MainFunction_Write. */
STATIC boolean CanMainFunctionTxSucessFlag = FALSE;

/***************************************************************
*                    Functions Definitions                     *
****************************************************************/
/*      Can_GetControllerMode Service definition               */
Std_ReturnType
Can_GetControllerMode(uint8 Controller,
					  Can_ControllerStateType *ControllerModePtr)
{
#if (CAN_DEV_ERROR_DETECT == STD_ON)     /* Report errors */
	if (CAN_CS_UNINIT == CanModes[Controller])
	{
		Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
			CAN_GET_CONTROLLER_MODE_SID, CAN_E_UNINIT);
		return E_NOT_OK;
	}
	if (CAN_CONTROLLER_ID <= Controller)
	{
		Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
			CAN_GET_CONTROLLER_MODE_SID, CAN_E_PARAM_CONTROLLER);
	}
	if (NULL_PTR == ControllerModePtr)
	{
		Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID,
			CAN_GET_CONTROLLER_MODE_SID, CAN_E_PARAM_POINTER);
	}
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

	ENTER_CRITICAL_SECTION();
	ControllerModePtr = &CanModes[Controller];
	EXIT_CRITICAL_SECTION();
	return E_OK;
}

/**************************************************************/
/*       Can_MainFunction_Write Service definition            */
#if (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_0)
void Can_MainFunction_Write_0(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_1)
void Can_MainFunction_Write_1(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_2)
void Can_MainFunction_Write_2(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_3)
void Can_MainFunction_Write_3(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_4)
void Can_MainFunction_Write_4(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_5)
void Can_MainFunction_Write_5(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_6)
void Can_MainFunction_Write_6(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_7)
void Can_MainFunction_Write_7(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_8)
void Can_MainFunction_Write_8(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_9)
void Can_MainFunction_Write_9(void)
{
	CanMainFunctionTxProcessing();
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_10)
void Can_MainFunction_Write_10(void)
{
	CanMainFunctionTxProcessing();
}
#else /* No period was defined. */
void Can_MainFunction_Write(void)
{
	switch (CAN_CONTROLLER_ID)
	{
		case CAN_CONTROLLER_0:
			CanStatusRegister_Ptr = &CAN0_STS_R;
			break;
		case CAN_CONTROLLER_1:
			CanStatusRegister_Ptr = &CAN1_STS_R;
			break;
		default:
			CanStatusRegister_Ptr = &CAN0_STS_R;
			break;
	}

	while (BIT_IS_CLEAR(*CanStatusRegister_Ptr, CANSTS_TXOK)) 
	{
	};
}
#endif /* CAN_MAIN_FUNCTION_WRITE_PERIOD. */


/**************************************************************/
/*           Private Functions Definitions                    */
/**************************************************************/
/*
Processing the Can transmission:
polling, mixed or interrupt.
*/
STATIC void CanMainFunctionTxProcessing(void)
{
	switch (CAN_TX_PROCESSING)
	{
		case POLLING:
			CanMainFunctionTxPolling(CAN_CONTROLLER_0);
			break;
		case MIXED: /* TO BE IMPLEMENTED. */
			break;
		default:    /* Defined neither POLLING nor MIXED. */
			CanMainFunctionWriteDef();
			break;
	}
}
/*
	Polling on the transmission successfulness. 
*/
STATIC void CanMainFunctionTxPolling(uint8 can_controller_id)
{
	switch (can_controller_id)
	{
		case CAN_CONTROLLER_0:
			CanStatusRegister_Ptr = &CAN0_STS_R;
			break;
		case CAN_CONTROLLER_1:
			CanStatusRegister_Ptr = &CAN1_STS_R;
			break;
		default:
			CanStatusRegister_Ptr = &CAN0_STS_R;
			break;
	}

	if (BIT_IS_CLEAR(*CanStatusRegister_Ptr, CANSTS_TXOK)) /* TO BE EDITTED */
	{
		CanMainFunctionTxSucessFlag = TRUE;
	}
	else
	{
		CanMainFunctionTxSucessFlag = FALSE;
	}
}



