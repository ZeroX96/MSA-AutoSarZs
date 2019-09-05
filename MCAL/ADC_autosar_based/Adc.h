/*
 * Adc.h
 *
 *  Date    : Aug 25, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 *  https://open.spotify.com/track/0qInJsghBH20hwv1yQkaUr?si=xctXXe0tRhGGomzIMfU7Pw <3 ;)
 */
#ifndef ADC_H_
#define ADC_H_
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

/******************includes*****************/
#include "Adc_Cfg.h"    //
#include "Std_Types.h"  //
#include "Adc_MemMap.h" //
#include "Det.h"
#include "SchM_Adc.h"
#include "HW_TYPES.h"
#include "Sys.h"
#include "GPIO.h"

/* REQ
 * All Basic SW Modules shall perform a pre-processor check
 * of the versions of all imported include files
 */
/*checking the autosar version*/
#if((ADC_AR_MAJOR_VERSION != DET_AR_MAJOR_VERSION)||\
    (ADC_AR_MINOR_VERSION != DET_AR_MINOR_VERSION)||\
    (ADC_AR_PATCH_VERSION != DET_AR_PATCH_VERSION))
  #error "The AR version of ADC.h differ than det.h"
#endif
/*checking the autosar version*/
#if((ADC_AR_MAJOR_VERSION != ADC_MEMAP_AR_MAJOR_VERSION)||\
    (ADC_AR_MINOR_VERSION != ADC_MEMAP_AR_MINOR_VERSION)||\
    (ADC_AR_PATCH_VERSION != ADC_MEMAP_AR_PATCH_VERSION))
  #error "The AR version of ADC.h differ than Adc_MemMap.h"
#endif
/*checking the autosar version*/
#if((ADC_AR_MAJOR_VERSION != COMPILER_AR_MAJOR_VERSION)||\
    (ADC_AR_MINOR_VERSION != COMPILER_AR_MINOR_VERSION)||\
    (ADC_AR_PATCH_VERSION != COMPILER_AR_PATCH_VERSION))
  #error "The AR version of ADC.h differ than compiler.h"
#endif
/*checking the autosar version*/
#if((ADC_AR_MAJOR_VERSION != STD_TYPES_AR_MAJOR_VERSION)||\
    (ADC_AR_MINOR_VERSION != STD_TYPES_AR_MINOR_VERSION)||\
    (ADC_AR_PATCH_VERSION != STD_TYPES_AR_PATCH_VERSION))
  #error "The AR version of Std_Types.h differ than std_types.h"
#endif

/*checking the autosar version*/
#if((ADC_AR_MAJOR_VERSION != ADC_CFG_AR_MAJOR_VERSION)||
    (ADC_AR_MINOR_VERSION != ADC_CFG_AR_MINOR_VERSION)||
    (ADC_AR_PATCH_VERSION != ADC_CFG_AR_PATCH_VERSION)
   )
#endif
 /*checking the software module version*/   /*since these two files are relted to each other*/

#if((ADC_MAJOR_VERSION != ADC_CFG_MAJOR_VERSION)||
    (ADC_MINOR_VERSION != ADC_CFG_MINOR_VERSION)||
    (ADC_PATCH_VERSION != ADC_CFG_PATCH_VERSION)
   )
#endif

#define ADC_IDLE                0u          //No result is available.
#define ADC_BUSY                1u          //So far no result is available.
#define ADC_COMPLETED           2u          //A result is available for all channels of the group.
#define ADC_STREAM_COMPLETED    3u          //The result buffer is completely filled

#define ADC_STATUSTYPE ADC_IDLE             //this macro shall be defined by one of the previous four.

#define ADC_TRIGG_SRC_SW        0u          //Group is triggered by a software API call.
#define ADC_TRIGG_SRC_HW        1u          //Group is triggered by a hardware event.
#define ADC_TRIGGERSOURCETYPE               //this macro shall be defined by one of the previous two.

#define ADC_CONV_MODE_ONESHOT       0u
#define ADC_CONV_MODE_CONTINUOUS    1u
#define ADC_GROUPCONVMODETYPE   ADC_CONV_MODE_ONESHOT   //this macro shall be defined by one of the previous two.

#define ADC_STREAM_BUFFER_LINEAR    0u
#define ADC_STREAM_BUFFER_CIRCULAR  1u
#define ADC_STREAMBUFFERMODETYPE    ADC_STREAM_BUFFER_LINEAR

#define Adc_GroupAccessModeType
#define ADC_ACCESS_MODE_SINGLE      0u
#define ADC_ACCESS_MODE_STREAMING   1u

#define Adc_HwTriggerSignalType
#define ADC_HW_TRIG_RISING_EDGE     0u
#define ADC_HW_TRIG_FALLING_EDGE    1u
#define ADC_HW_TRIG_BOTH_EDGES      2u


#define Adc_PriorityImplementationType
#define ADC_PRIORITY_NONE           0u
#define ADC_PRIORITY_HW             1u
#define ADC_PRIORITY_HW_SW          2u


#define ADC_GROUP_REPL_ABORT_RESTART    0u
#define ADC_GROUP_REPL_SUSPEND_RESUME   1u
#define Adc_GroupReplacementType

#define Adc_ChannelRangeSelectType
#define ADC_RANGE_UNDER_LOW         0
#define ADC_RANGE_BETWEEN           1
#define ADC_RANGE_OVER_HIGH         2
#define ADC_RANGE_ALWAYS            3
#define ADC_RANGE_NOT_UNDER_LOW     4
#define ADC_RANGE_NOT_BETWEEN       5
#define ADC_RANGE_NOT_OVER_HIGH     6


#define Adc_ResultAlignmentType
#define ADC_ALIGN_LEFT      0u
#define ADC_ALIGN_RIGHT     1u


#define Adc_PowerStateType      //any val is acceptable 1:255
#define ADC_FULL_POWER  0


#define Adc_PowerStateRequestResultType
#define ADC_SERVICE_ACCEPTED    0u
#define ADC_NOT_INIT            1u
#define ADC_SEQUENCE_ERROR      2u
#define ADC_HW_FAILURE          3u
#define ADC_POWER_STATE_NOT_SUPP    4u
#define ADC_TRANS_NOT_POSSIBLE      5u





typedef uint16  Adc_ChannelType;
typedef uint16  Adc_GroupType;
typedef uint16  Adc_ValueGroupType;
typedef uint32  Adc_PrescaleType;           //dnt know yet :(
typedef uint32  Adc_ConversionTimeType;     //dnt know yet :(
typedef uint32  Adc_SamplingTimeType;       //dnt know yet :(
typedef uint8   Adc_ResolutionType;
typedef uint8   Adc_GroupPriorityType;
typedef uint8   Adc_GroupDefType;           //wrong ask for this?????
typedef uint8   Adc_StreamNumSampleType;    //wrong ask for this?????
typedef uint8   Adc_HwTriggerTimerType;     //wrong ask for this?????

typedef enum
{
    PRIO_HIGHEST=0x00,
    PRIO_HIGH   =0x01,
    PRIO_LOW    =0x02,
    PRIO_LOWEST =0x03,
}adc_ss_prio_select_t;
typedef struct
{
    uint8 sample_seq_0_priority;
    uint8 sample_seq_1_priority;
    uint8 sample_seq_2_priority;
    uint8 sample_seq_3_priority;
}adc_ss_priority_cfg_t;
typedef enum
{
    ADC_SAMPLE_SEQ_0,
    ADC_SAMPLE_SEQ_1,
    ADC_SAMPLE_SEQ_2,
    ADC_SAMPLE_SEQ_3,
}adc_ss_select_t;
typedef enum
{

    PROCESSOR=0x00,//The trigger is initiated by setting the SSn bit in the ADCPSSI register
    ANALOG_COMPARATOR_0=0x01,//This trigger is configured by the Analog Comparator Control0(ACCTL0) register
    ANALOG_COMPARATOR_1=0x02,//This trigger is configured by the Analog Comparator Control1(ACCTL1) register
    EXTERNAL_GPIO_PINS=0x04,//This trigger is connected to the GPIO interrupt for the corresponding GPIO
                            //Note: GPIOs that have AINx signals as alternate functions can be used to trigger the ADC.
                            //However,the pin cannot be used as both a GPIO and an analog input.
    TIMER=0x05,//In addition, the trigger must be enabled with the TnOTE bit in the GPTMCTL register
    PWM_GENERATOR_0=0x06,   //The PWM generator 0 trigger can be configured with the
                            //PWM0 Interrupt and Trigger Enable (PWM0INTEN) register
    PWM_GENERATOR_1=0x07,   //The PWM generator 1 trigger can be configured with the PWM1INTEN register
    PWM_GENERATOR_2=0x08,   //The PWM generator 2 trigger can be configured with the PWM2INTEN register
    PWM_GENERATOR_3=0x09,   //The PWM generator 3 trigger can be configured with the PWM3INTEN register
    CONTINUOUSLY_SAMPLING=0x0f,
}adc_ss_event_select_t;

typedef enum
{
    PWM_MODULE_0,
    PWM_MODULE_1,
}adc_ss_event_pwm_module_t;
typedef struct
{
    boolean                 adc_ss_priority_edit_obj;   //if set TRUE,Will Configure the Priorities,NOTE>>NO REPEATED PRIORITY VALUE CAN BE USED
    adc_ss_priority_cfg_t   adc_ss_priority_obj;
    module_numb_t           adc_module_numb_obj;
    adc_ss_select_t         adc_ss_select_obj;
    adc_ss_event_select_t   adc_ss_event_select_obj;
    adc_ss_event_pwm_module_t    adc_ss_event_pwm_module_obj;
}Adc_ConfigType;



void Adc_Init(const Adc_ConfigType* ConfigPtr);
void Adc_DeInit(void);

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define ADC_INIT_SID           0x00

/* Service ID for DIO write Channel */
#define ADC_DEINIT_SID         0x01

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/*
 * ADC driver and hardware already initialized.
 */
#define ADC_E_ALREADY_INITIALIZED             0x05

/*
 * ADC initialization API called with incorrect configuration pointer
 */
#define ADC_E_PARAM_POINTER                   0x06

/*
 * Function called prior to initialization.
 */
#define ADC_E_UNINIT                          0x07

/* ADC Module Id */
#define ADC_MODULE_ID    (120U)

/* ADC Instance Id */
#define ADC_INSTANCE_ID  (1U)


#endif /* ADC_H_ */
