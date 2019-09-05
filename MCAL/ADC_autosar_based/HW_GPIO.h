/*
 * HW_GPIO.h
 *
 *  Created on: 9 Oct 2018
 *      Author: Mahmoud
 */

#ifndef HW_GPIO_H_
#define HW_GPIO_H_
//#include "TYPES.h"
#include <stdint.h>

//if U wanna use the AHBUS DO_NOTHING otherwise, wanna use APBUS COMMENT the next line
//#define ADVANCED_H_SPEED_BUS

#ifdef ADVANCED_H_SPEED_BUS
//GPIO_AHB_REG_BASES
typedef enum
{
 BASE_A =0x40058000,
 BASE_B =0x40059000,
 BASE_C =0x4005A000,
 BASE_D =0x4005B000,
 BASE_E =0x4005C000,
 BASE_F =0x4005D000,
}gpio_bases_t;
#else
//GPIO_APB_REGS
typedef enum
{
 BASE_A =0x40004000,
 BASE_B =0x40005000,
 BASE_C =0x40006000,
 BASE_D =0x40007000,
 BASE_E =0x40024000,
 BASE_F =0x40025000,
}gpio_bases_t;
#endif

#define GPIO_DATA_OFFSET                   0x3FC
#define GPIO_DIRECTION_OFFSET              0x400
#define GPIO_INTERRUPT_SENSE_OFFSET        0x404
#define GPIO_INTERRUPT_BOTH_EDGE_OFFSET    0x408
#define GPIO_INTERRUPT_EVENT_OFFSET        0x40C
#define GPIO_INTERRUPT_MASK_OFFSET         0x410
#define GPIO_RAW_INTERRUPT_STATUS_OFFSET   0x414
#define GPIO_MASK_INTERRUPT_STATUS_OFFSET  0x418
#define GPIO_INTERRUPT_CLEAR_OFFSET        0x41C
#define GPIO_ALTERNATE_FUNC_SEL_OFFSET     0x420
#define GPIO_2_MA_DRIVE_SEL_OFFSET         0x500
#define GPIO_4_MA_DRIVE_SEL_OFFSET         0x504
#define GPIO_8_MA_DRIVE_SEL_OFFSET         0x508
#define GPIO_OPEN_DRAIN_SEL_OFFSET         0x50C
#define GPIO_PULL_UP_SEL_OFFSET            0x510
#define GPIO_PULL_DOWN_SEL_OFFSET          0x514
#define GPIO_SLEW_RATE_CONTROL_SEL_OFFSET  0x518
#define GPIO_DIGITAL_EN_OFFSET             0x51C
#define GPIO_LOCK_OFFSET                   0x520
#define GPIO_COMMIT_OFFSET                 0x524
#define GPIO_ANALOG_MODE_SEL_OFFSET        0x528
#define GPIO_PORT_CONTROL_OFFSET           0x52C
#define GPIO_ADC_CONTROL_OFFSET            0x530
#define GPIO_DMA_CONTROL_OFFSET            0x534
#define GPIO_PERIPHRAL_ID_4_OFFSET         0xFD0
#define GPIO_PERIPHRAL_ID_5_OFFSET         0xFD4
#define GPIO_PERIPHRAL_ID_6_OFFSET         0xFD8
#define GPIO_PERIPHRAL_ID_7_OFFSET         0xFDC
#define GPIO_PERIPHRAL_ID_0_OFFSET         0xFE0
#define GPIO_PERIPHRAL_ID_1_OFFSET         0xFE4
#define GPIO_PERIPHRAL_ID_2_OFFSET         0xFE8
#define GPIO_PERIPHRAL_ID_3_OFFSET         0xFEC
#define GPIO_PRIMECELL_ID_0_OFFSET         0xFF0
#define GPIO_PRIMECELL_ID_1_OFFSET         0xFF4
#define GPIO_PRIMECELL_ID_2_OFFSET         0xFF8
#define GPIO_PRIMECELL_ID_3_OFFSET         0xFFC


#define HW_WRITE_
#endif /* HW_GPIO_H_ */
