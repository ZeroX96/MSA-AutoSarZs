/*
 * GPIO.h
 *
 *  Created on: 9 Oct 2018
 *      Author: Mahmoud
 */

#ifndef GPIO_H_
#define GPIO_H_
/* REQ
 * All software modules shall provide version and identification information
 * Std_Types V0.0.0
 * AUTOSAR   V4.3.1
 */
/******************module******************/
#define GPIO_MAJOR_VERSION   0
#define GPIO_MINOR_VERSION   0
#define GPIO_PATCH_VERSION   0
/******************autosar******************/
#define GPIO_AR_MAJOR_VERSION   4
#define GPIO_AR_MINOR_VERSION   3
#define GPIO_AR_PATCH_VERSION   1

#include "HW_TYPES.h"
#include "HW_GPIO.h"
#include "Sys.h"
#define GPIO_ERRORS_BASE 50

typedef enum
{
    NO_GPIO_ERRORS =GPIO_ERRORS_BASE,
    INVALID_GPIO_PARAMS,
    INVALID_GPIO_PIN,
}gpio_errors_t;

typedef enum
{
    INPUT=0x00,
    OUTPUT=0xff,
}gpio_data_dir_t;
typedef enum
{
    LOW,
    HIGH,
}gpio_data_val_t;

typedef enum
{
    PULL_UP_RES=GPIO_PULL_UP_SEL_OFFSET,
    PULL_DWN_RES=GPIO_PULL_DOWN_SEL_OFFSET,
    OPNDRAIN_RES=GPIO_OPEN_DRAIN_SEL_OFFSET,
}gpio_res_t;            //

typedef enum
{
    CURRENT_EQU_2MA=GPIO_2_MA_DRIVE_SEL_OFFSET,
    CURRENT_EQU_4MA=GPIO_4_MA_DRIVE_SEL_OFFSET,
    CURRENT_EQU_8MA=GPIO_8_MA_DRIVE_SEL_OFFSET,
}gpio_current_val_t;    //GPIO Current Drive Select
typedef enum
{
    SLR_OFF,
    SLR_ON,
}gpio_SLR_select_t;     //GPIO Slew Rate Control Select but note it's for 8mA only!!!!

typedef enum
{
    AFSELECT_OFF=0x00,
    AFSELECT_ON=0xff,
}gpio_AF_select_t;     //GPIO alternative function Select and note there are more regs need to be ctrled:D

typedef enum
{
    PIN_ZERO,
    PIN_ONE,
    PIN_TWO,
    PIN_THREE,
    PIN_FOUR,
    PIN_FIVE,
    PIN_SIX,
    PIN_SEVEN,
}gpio_module_pin_no_t;

typedef enum
{
    ANALOG_EN=GPIO_ANALOG_MODE_SEL_OFFSET,
    DIGITAL_EN=GPIO_DIGITAL_EN_OFFSET,
}gpio_signal_mode_t;     //GPIO DIGITAL OR ANALOG.

typedef struct
{
    gpio_bases_t        obj_base;
    gpio_SLR_select_t   obj_slr_select;
    gpio_current_val_t  obj_current_value;
    gpio_data_dir_t     obj_data_direction;
    gpio_res_t          obj_res_type;
    gpio_AF_select_t    obj_af_select;
    gpio_signal_mode_t  obj_sig_mode;
}gpio_module_cfg_t;

gpio_errors_t InitGpioPort(gpio_module_cfg_t* module_obj);
gpio_errors_t InitGpioPin(gpio_module_cfg_t* module_obj,gpio_module_pin_no_t module_pin_numb);
gpio_errors_t InitGpiochannels(gpio_module_cfg_t* module_obj,uint8_t channels_val);
/*gpio_errors_t ReInitGpioPort(specific_configs_and_the_unchanged_put_Zero);
gpio_errors_t ReInitGpioPin(specific_configs_and_the_unchanged_put_Zero);*/
gpio_errors_t Write2GpioPort(gpio_module_cfg_t* module_obj,uint8_t value);
gpio_errors_t Write2GpioPin(gpio_module_cfg_t* module_obj,gpio_module_pin_no_t module_pin_numb,gpio_data_val_t value);
gpio_errors_t Read4mGpioPort(gpio_module_cfg_t* module_obj,uint32_t *data_in);
gpio_errors_t Read4mGpioPin(gpio_module_cfg_t* module_obj,gpio_module_pin_no_t module_pin_numb,uint32_t *data_in);
gpio_errors_t DeInitGpioPort(gpio_module_cfg_t* module_obj);



#endif /* GPIO_H_ */
