/*
 * Can.c
 *
 *  Date	: Sep 16, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */

#include "Can.h"
#include "CanIf_Cbk.h"
#include "EcuM_Cbk.h"
#include "Os.h"
#include "Spi.h"
#include "SchM_Can.h"
#include "MemMap.h"
#include "Det.h"
#include "Dem.h"

uint8 CanControllerState[CAN_CONTROLLERS_NUMB];

Std_ReturnType Can_GetControllerMode(uint8 Controller,Can_ControllerStateType* ControllerModePtr)
{
#if (DEV_ERROR_DETECTION STD_ON)
    if(Controller >= CAN_CONTROLLERS_NUMB)
        Det_ReportError(CAN_MODULE_ID, CAN_GET_CONTROLLER_MODE, CAN_E_PARAM_CONTROLLER);
    if(ControllerModePtr == NULL_PTR)
        Det_ReportError(CAN_MODULE_ID, CAN_GET_CONTROLLER_MODE, CAN_E_PARAM_POINTER);
    return E_NOT_OK;
#endif

    *ControllerModePtr=CanControllerState[Controller];
    return E_OK;
}
