/***************************************************************
* Module:      Can controller
* File Name:   SchM_Can.h
* Description: 
* Author:      Abdulmaguid Eissa, Team(3) Sokara
* Date:        Sept 14, 2019
****************************************************************/

#ifndef SCHM_CAN_H
#define SCHM_CAN_H

/* Module Version 1.0.0 */
#define SCHM_CAN_SW_MAJOR_VERSION (1U)
#define SCHM_CAN_SW_MINOR_VERSION (0U)
#define SCHM_CAN_SW_PATCH_VERSION (0U)

void DisableInterrupts(void);
void EnableInterrupts(void);

#define ENTER_CRITICAL_SECTION()   DisableInterrupts()
#define EXIT_CRITICAL_SECTION()    EnableInterrupts()

#endif /* SCHM_CAN_H */