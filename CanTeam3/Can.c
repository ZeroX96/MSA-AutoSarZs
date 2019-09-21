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
STATIC void CanMainFunctionTxProcessing(void);

/***************************************************************/
/*            Private Globals Declarations                     */
/***************************************************************/
STATIC uint8 CanModes[CAN_CONTROLLER_ID] = {CAN_CS_UNINIT,
											CAN_CS_UNINIT};
/* Global flag to inform of sucessful transmission from the 
   Can_MainFunction_Write. */
STATIC boolean CanMainFunctionTxSuccessFlag = FALSE;
/*
	Array holds the Can message objects that is configured 
	to be Polling or Mixed CanTxProcessing. 
	Shall be filled with the 32 message numbers.
*/
STATIC uint8 MessageObjects[CAN_MSG_OBJECT_NUM];
/*
	Global for assigning the current operating controller.
*/
STATIC uint8 OperatingController = CAN_CONTROLLER_0;

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
	volatile uint32 *CanIfCrqReg = NULL_PTR;        /* Can interface cmd request */
	volatile uint32 *CanIfCmskReg = NULL_PTR;       /* Can interface cmd mask */
	volatile uint32 *CanIfMctlReg = NULL_PTR;       /* Can interface message control */
	uint8 mesg_num = CAN_MSG_OBJECT_BEG;
	uint8 mesg_index = 0;

	switch (OperatingController)
	{
		case CAN_CONTROLLER_0:
			CanIfCrqReg = &(CAN0_IF1CRQ_R);
			CanIfCmskReg = &(CAN0_IF1CMSK_R);
			CanIfMctlReg = &(CAN0_IF1MCTL_R);
			break;
		case CAN_CONTROLLER_1:
			CanIfCrqReg = &(CAN1_IF1CRQ_R);
			CanIfCmskReg = &(CAN1_IF1CMSK_R);
			CanIfMctlReg = &(CAN1_IF1MCTL_R);
			break;
		default:
			CanIfCrqReg = &(CAN0_IF1CRQ_R);
			CanIfCmskReg = &(CAN0_IF1CMSK_R);
			CanIfMctlReg = &(CAN0_IF1MCTL_R);
		break;
	}

	switch (CAN_TX_PROCESSING)
	{
		case POLLING:   /* Poll on the whole message objects */
			CLEAR_BIT(*CanIfMctlReg, WRNRD);
			CLEAR_BIT(*CanIfCmskReg, TXRQST_BUF);

			for (mesg_num = CAN_MSG_OBJECT_BEG; mesg_num <= CAN_MSG_OBJECT_END; mesg_num++)
			{
				SET_VAL(*CanIfCrqReg, mesg_num);
				if (BIT_IS_CLEAR(*CanIfMctlReg, TXRQST))
				{
					ENTER_CRITICAL_SECTION();
					CanMainFunctionTxSuccessFlag = TRUE;
					EXIT_CRITICAL_SECTION();
				}
				else
				{
					ENTER_CRITICAL_SECTION();
					CanMainFunctionTxSuccessFlag = FALSE;
					EXIT_CRITICAL_SECTION();
				}
			}
			break;
		case MIXED: /* Poll on the user specified message object */
			CLEAR_BIT(*CanIfMctlReg, WRNRD);
			CLEAR_BIT(*CanIfCmskReg, TXRQST_BUF);

			for(mesg_index = 0; mesg_index < CAN_MSG_OBJECT_NUM; mesg_index++)
			{
				if (MessageObjects[mesg_index])   
				{
					SET_VAL(*CanIfCrqReg, MessageObjects[mesg_index]);
					if (BIT_IS_CLEAR(*CanIfMctlReg, TXRQST))
					{
						ENTER_CRITICAL_SECTION();
						CanMainFunctionTxSuccessFlag = TRUE;
						EXIT_CRITICAL_SECTION();
					}
					else
					{
						ENTER_CRITICAL_SECTION();
						CanMainFunctionTxSuccessFlag = FALSE;
						EXIT_CRITICAL_SECTION();
					}	
				}
			}
			break;
		default: /* Defined neither POLLING nor MIXED. */
			CanMainFunctionWriteDef();
			break;
	}
}
/*
	Polling on the transmission successfulness. 
*/




