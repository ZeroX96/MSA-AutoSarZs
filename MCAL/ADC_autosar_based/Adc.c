/*
 * Adc.c
 *
 *  Created on: Aug 25, 2019
 *      Author: msams
 */
/* REQ
 * All software modules shall provide version and identification information
 * Std_Types V0.0.0
 * AUTOSAR   V4.3.1
 */
/******************module******************/
#define ADC_MAJOR_VERSION   0
#define ADC_MINOR_VERSION   0
#define ADC_PATCH_VERSION   0
/******************autosar******************/
#define ADC_AR_MAJOR_VERSION   4
#define ADC_AR_MINOR_VERSION   3
#define ADC_AR_PATCH_VERSION   1

#include "Adc.h"
/*
 * internal defines needed in this file only
 */
#define SS0 0
#define SS1 4
#define SS2 8
#define SS3 12

#define EM0 0
#define EM1 4
#define EM2 8
#define EM3 12

#define ASEN0 0
#define ASEN1 1
#define ASEN2 2
#define ASEN3 3

#define PS0 4
#define PS1 12
#define PS2 20
#define PS3 28

/*  AUTOSAR_STD
 * Service ID[hex]:  0x00
 * Sync/Async:  Synchronous
 * Reentrancy:  Non Reentrant
 * Parameters (in):
 * ConfigPtr  Pointer to configuration set in Variant PB
 * (Variant PC requires a NULL_PTR).
 * Parameters (in): None
 * Parameters (out):  None
 * Return value:  None
 * Description:  Initializes the ADC hardware units and driver.
 */
static gpio_module_cfg_t gpio_temp_cfgs;
static uint8 gpio_channel_val_temp;
void Adc_Init(const Adc_ConfigType* ConfigPtr)
{
    if(NULL_PTR == ConfigPtr)
    {
        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,ADC_E_PARAM_POINTER);
    }
    else
    {
        /*Enable the ADC clock using the RCGCADC register*/
            //sys_init();     //enables the adc using sys module
            sys_enable_module(ADC, ConfigPtr->adc_module_numb_obj);

            //gpio_init();  //all the adc concerned io pins
                            //Set the GPIO AFSEL bits for the ADCpins and the AINx signals to
                            //be analog inputs and Disable the analog isolation circuit
            //we have B{4,5},D{0,1,2,3},E{0,1,2,3,4,5}
            //FOR PORT_B
            gpio_temp_cfgs={BASE_B,SLR_OFF,CURRENT_EQU_2MA,INPUT,OPNDRAIN_RES,AFSELECT_ON,ANALOG_EN};
            gpio_channel_val_temp=(1<<4)|(1<<5);
            InitGpiochannels(&gpio_temp_cfgs, gpio_channel_val_temp);
            //FOR PORT_D
            gpio_temp_cfgs.obj_base=BASE_D;
            gpio_channel_val_temp=(1<<0)|(1<<1)|(1<<2)|(1<<3);
            InitGpiochannels(&gpio_temp_cfgs, gpio_channel_val_temp);
            //FOR PORT_E
            gpio_temp_cfgs.obj_base=BASE_E;
            gpio_channel_val_temp=(1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
            InitGpiochannels(&gpio_temp_cfgs, gpio_channel_val_temp);
            //ss_init();      //Ensure that the sample sequencer is disabled by clearing
                            //the corresponding ASENn bit in the
            if(ADC_ZERO == ConfigPtr->adc_module_numb_obj)
            {
                if(ADC_SAMPLE_SEQ_0 == ConfigPtr->adc_ss_select_obj)
                {
                    HW_CLR_REG_BIT((BASE_ADC0 + ADC_ACTIVE_SAMPLE_SEQUENCER_OFFSET),ASEN0);    //disabling the adc0 sequencer selected
                    HW_WRITE_ORING_REG(BASE_ADC0 + ADC_EVENT_MULTIPLEXER_SELECT_OFFSET,(ConfigPtr->adc_ss_event_select_obj)<<EM0);
                }
                else if(ADC_SAMPLE_SEQ_1 == ConfigPtr->adc_ss_select_obj)
                {
                    HW_CLR_REG_BIT((BASE_ADC0 + ADC_ACTIVE_SAMPLE_SEQUENCER_OFFSET),ASEN1);    //disabling the adc1 sequencer selected
                    HW_WRITE_ORING_REG(BASE_ADC0 + ADC_EVENT_MULTIPLEXER_SELECT_OFFSET,(ConfigPtr->adc_ss_event_select_obj)<<EM1);
                }
                else if(ADC_SAMPLE_SEQ_2 == ConfigPtr->adc_ss_select_obj)
                {
                    HW_CLR_REG_BIT((BASE_ADC0 + ADC_ACTIVE_SAMPLE_SEQUENCER_OFFSET),ASEN2);    //disabling the adc2 sequencer selected
                    HW_WRITE_ORING_REG(BASE_ADC0 + ADC_EVENT_MULTIPLEXER_SELECT_OFFSET,(ConfigPtr->adc_ss_event_select_obj)<<EM2);
                }
                else if(ADC_SAMPLE_SEQ_3 == ConfigPtr->adc_ss_select_obj)
                {
                    HW_CLR_REG_BIT((BASE_ADC0 + ADC_ACTIVE_SAMPLE_SEQUENCER_OFFSET),ASEN3);    //disabling the adc3 sequencer selected
                    HW_WRITE_ORING_REG(BASE_ADC0 + ADC_EVENT_MULTIPLEXER_SELECT_OFFSET,(ConfigPtr->adc_ss_event_select_obj)<<EM3);
                }
                else//report error
                {
                    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,ADC_E_PARAM_POINTER);
                }

                if( (ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_0)||
                    (ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_1)||
                    (ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_2)||
                    (ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_3))
                {
                    if(ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_0)
                        HW_WRITE_ORING_REG(BASE_ADC0 + ADC_TRIGGER_SOURCE_SELECT_OFFSET,(ConfigPtr->adc_ss_event_pwm_module_obj)<<PS0);
                    else if(ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_1)
                        HW_WRITE_ORING_REG(BASE_ADC0 + ADC_TRIGGER_SOURCE_SELECT_OFFSET,(ConfigPtr->adc_ss_event_pwm_module_obj)<<PS1);
                    else if(ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_2)
                        HW_WRITE_ORING_REG(BASE_ADC0 + ADC_TRIGGER_SOURCE_SELECT_OFFSET,(ConfigPtr->adc_ss_event_pwm_module_obj)<<PS2);
                    else if(ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_3)
                        HW_WRITE_ORING_REG(BASE_ADC0 + ADC_TRIGGER_SOURCE_SELECT_OFFSET,(ConfigPtr->adc_ss_event_pwm_module_obj)<<PS3);
                    else//report error
                    {
                        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,ADC_E_PARAM_POINTER);
                    }
                }
            }
            else if(ADC_ONE == ConfigPtr->adc_module_numb_obj)
            {
                if(ADC_SAMPLE_SEQ_0 == ConfigPtr->adc_ss_select_obj)
                {
                    HW_CLR_REG_BIT((BASE_ADC1 + ADC_ACTIVE_SAMPLE_SEQUENCER_OFFSET),ASEN0);    //disabling the adc0 sequencer selected
                    HW_WRITE_ORING_REG(BASE_ADC1 + ADC_EVENT_MULTIPLEXER_SELECT_OFFSET,(ConfigPtr->adc_ss_event_select_obj)<<EM0);
                }
                else if(ADC_SAMPLE_SEQ_1 == ConfigPtr->adc_ss_select_obj)
                {
                    HW_CLR_REG_BIT((BASE_ADC1 + ADC_ACTIVE_SAMPLE_SEQUENCER_OFFSET),ASEN1);    //disabling the adc1 sequencer selected
                    HW_WRITE_ORING_REG(BASE_ADC1 + ADC_EVENT_MULTIPLEXER_SELECT_OFFSET,(ConfigPtr->adc_ss_event_select_obj)<<EM1);
                }
                else if(ADC_SAMPLE_SEQ_2 == ConfigPtr->adc_ss_select_obj)
                {
                    HW_CLR_REG_BIT((BASE_ADC1 + ADC_ACTIVE_SAMPLE_SEQUENCER_OFFSET),ASEN2);    //disabling the adc2 sequencer selected
                    HW_WRITE_ORING_REG(BASE_ADC1 + ADC_EVENT_MULTIPLEXER_SELECT_OFFSET,(ConfigPtr->adc_ss_event_select_obj)<<EM2);
                }
                else if(ADC_SAMPLE_SEQ_3 == ConfigPtr->adc_ss_select_obj)
                {
                    HW_CLR_REG_BIT((BASE_ADC1 + ADC_ACTIVE_SAMPLE_SEQUENCER_OFFSET),ASEN3);    //disabling the adc3 sequencer selected
                    HW_WRITE_ORING_REG(BASE_ADC1 + ADC_EVENT_MULTIPLEXER_SELECT_OFFSET,(ConfigPtr->adc_ss_event_select_obj)<<EM3);
                }
                else//report error
                {
                    Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,ADC_E_PARAM_POINTER);
                }

                if( (ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_0)||
                    (ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_1)||
                    (ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_2)||
                    (ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_3))
                {
                    if(ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_0)
                        {HW_WRITE_ORING_REG(BASE_ADC1 + ADC_TRIGGER_SOURCE_SELECT_OFFSET,(ConfigPtr->adc_ss_event_pwm_module_obj)<<PS0);}
                    else if(ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_1)
                        {HW_WRITE_ORING_REG(BASE_ADC1 + ADC_TRIGGER_SOURCE_SELECT_OFFSET,(ConfigPtr->adc_ss_event_pwm_module_obj)<<PS1);}
                    else if(ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_2)
                        {HW_WRITE_ORING_REG(BASE_ADC1 + ADC_TRIGGER_SOURCE_SELECT_OFFSET,(ConfigPtr->adc_ss_event_pwm_module_obj)<<PS2);}
                    else if(ConfigPtr->adc_ss_event_select_obj == PWM_GENERATOR_3)
                        {HW_WRITE_ORING_REG(BASE_ADC1 + ADC_TRIGGER_SOURCE_SELECT_OFFSET,(ConfigPtr->adc_ss_event_pwm_module_obj)<<PS3);}
                    else//report error
                    {
                        Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,ADC_E_PARAM_POINTER);
                    }
                }
            }
            else//report error
            {
                Det_ReportError(ADC_MODULE_ID, ADC_INSTANCE_ID,ADC_E_PARAM_POINTER);
            }
    }

}
/*
Service ID[hex]   :  0x01
Sync/Async        :  Synchronous
Reentrancy        :  Non Reentrant
Parameters (in)   :  None
Parameters (inout):  None
Parameters (out)  :  None
Return value      :  None
Description       :  Returns all ADC HW Units to a state comparable to their power on reset state.*/

void Adc_DeInit(void)
{

    /*Enable the ADC clock using the RCGCADC register*/
    //sys_init();     //enables the adc using sys module
    sys_disable_module(ADC, ADC_ZERO);
    sys_disable_module(ADC, ADC_ONE);
    //de-init portB/Gpio port B
    gpio_temp_cfgs->obj_base=BASE_B;
    DeInitGpioPort(module_obj);
    //de-init portB/Gpio port D
    gpio_temp_cfgs->obj_base=BASE_D;
    DeInitGpioPort(module_obj);
    //de-init portB/Gpio port E
    gpio_temp_cfgs->obj_base=BASE_E;
    DeInitGpioPort(module_obj);

}

//have it's own function so moved from here
//ssprio_set();   //configure the sample sequencer priorities in the ADCSSPRI if needed
/* if(TRUE == ConfigPtr->adc_ss_priority_edit_obj)
{
    if(ADC_ZERO == ConfigPtr->adc_module_numb_obj)
    {
        HW_WRITE_ORING_REG((BASE_ADC0 + ADC_SAMPLE_SEQUENCER_PRIORITY_OFFSET),((ConfigPtr->adc_ss_priority_obj->sample_seq_0_priority)<<SS0));
        HW_WRITE_ORING_REG((BASE_ADC0 + ADC_SAMPLE_SEQUENCER_PRIORITY_OFFSET),((ConfigPtr->adc_ss_priority_obj->sample_seq_1_priority)<<SS1));
        HW_WRITE_ORING_REG((BASE_ADC0 + ADC_SAMPLE_SEQUENCER_PRIORITY_OFFSET),((ConfigPtr->adc_ss_priority_obj->sample_seq_2_priority)<<SS2));
        HW_WRITE_ORING_REG((BASE_ADC0 + ADC_SAMPLE_SEQUENCER_PRIORITY_OFFSET),((ConfigPtr->adc_ss_priority_obj->sample_seq_3_priority)<<SS3));
    }
    else if(ADC_ONE == ConfigPtr->adc_module_numb_obj)
    {
        HW_WRITE_ORING_REG((BASE_ADC1 + ADC_SAMPLE_SEQUENCER_PRIORITY_OFFSET),(ConfigPtr->adc_ss_priority_obj->sample_seq_0_priority<<SS0));
        HW_WRITE_ORING_REG((BASE_ADC1 + ADC_SAMPLE_SEQUENCER_PRIORITY_OFFSET),(ConfigPtr->adc_ss_priority_obj->sample_seq_1_priority<<SS1));
        HW_WRITE_ORING_REG((BASE_ADC1 + ADC_SAMPLE_SEQUENCER_PRIORITY_OFFSET),(ConfigPtr->adc_ss_priority_obj->sample_seq_2_priority<<SS2));
        HW_WRITE_ORING_REG((BASE_ADC1 + ADC_SAMPLE_SEQUENCER_PRIORITY_OFFSET),(ConfigPtr->adc_ss_priority_obj->sample_seq_3_priority<<SS3));

    }
    else
    {
        //report error
    }
}*/

