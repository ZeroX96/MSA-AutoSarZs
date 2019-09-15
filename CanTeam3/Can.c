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

/***************************************************************/
/*           Private Functions Declarations                    */
/***************************************************************/
/*
	Local function to check on the TXOK bit for specified 
	period/time tick.
*/
STATIC void CanMainFunctionWrite(uint8 can_controller_id, 
	float32 period);

/***************************************************************/
/*            Private Globals Declarations                     */
/***************************************************************/


/***************************************************************
*                    Functions Definitions                     *
****************************************************************/
/*      Can_GetControllerMode Service definition               */
Std_ReturnType Can_GetControllerMode(uint8 Controller,
	Can_ControllerStateType* ControllerModePtr)
{

}

/**************************************************************/
/*       Can_MainFunction_Write Service definition            */
#if (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_0)
void Can_MainFunction_Write_0(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_0);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_1)
void Can_MainFunction_Write_1(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_1);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_2)
void Can_MainFunction_Write_2(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_2);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_3)
void Can_MainFunction_Write_3(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_3);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_4)
void Can_MainFunction_Write_4(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_4);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_5)
void Can_MainFunction_Write_5(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_5);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_6)
void Can_MainFunction_Write_6(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_6);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_7)
void Can_MainFunction_Write_7(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_7);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_8)
void Can_MainFunction_Write_8(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_8);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_9)
void Can_MainFunction_Write_9(void)
{
	CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_9);
}
#elif (CAN_MAIN_FUNCTION_WRITE_PERIOD == PERIOD_10)
void Can_MainFunction_Write_10(void)
{
	switch (CAN_TX_PROCESSING)
	{
		case POLLING:
			CanMainFunctionWrite(CAN_CONTROLLER_ID, PERIOD_10);
			break;
		case MIXED: /* TO BE IMPLEMENTED. */
			break;
		default:    /* Defined neither POLLING nor MIXED. */
			CanMainFunctionWriteDef();
			break;
	}
}
#else /* No period was defined. */
void Can_MainFunction_Write(void)
{

}
#endif /* CAN_MAIN_FUNCTION_WRITE_PERIOD. */


/**************************************************************/
/*           Private Functions Definitions                    */
/**************************************************************/
STATIC void CanMainFunctionWrite(uint8 can_controller_id, 
	float32 period)
{
	uint32 * CanControllerRegiser_Ptr = NULL_PTR;

	switch (can_controller_id)
	{
		case CAN_CONTROLLER_0:
			CanControllerRegiser_Ptr = &CAN0_STS_R;
			break;
		case CAN_CONTROLLER_1:
			CanControllerRegiser_Ptr = &CAN1_STS_R;
			break;
		default:
			CanControllerRegiser_Ptr = &CAN0_STS_R;
			break;
	}

	/* Wait until transmission is a success or period is timeout. */
	while (BIT_IS_CLEAR(*CanControllerRegiser_Ptr, CANSTS_TXOK) &&
		(period > 0))
	{
		period = period - 1;     /* TO BE EDITTED */
	}
}