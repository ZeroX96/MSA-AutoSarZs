/*
 * Adc_MemMap.h
 *
 *  Created on: Aug 25, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */

#ifndef ADC_MEMMAP_H_
#define ADC_MEMMAP_H_

/* REQ
 * All software modules shall provide version and identification information
 * Std_Types V0.0.0
 * AUTOSAR   V4.3.1
 */
/******************module******************/
#define ADC_MEMAP_MAJOR_VERSION   0
#define ADC_MEMAP_MINOR_VERSION   0
#define ADC_MEMAP_PATCH_VERSION   0
/******************autosar******************/
#define ADC_MEMAP_AR_MAJOR_VERSION   4
#define ADC_MEMAP_AR_MINOR_VERSION   3
#define ADC_MEMAP_AR_PATCH_VERSION   1
//ADC_MODULE_BASES
typedef enum
{
 BASE_ADC0 =0x40038000,
 BASE_ADC1 =0x40039000,
}adc_bases_t;

#define ADC_ACTIVE_SAMPLE_SEQUENCER_OFFSET                          0x000
#define ADC_RAW_INTERRUPT_STATUS_OFFSET                             0x004
#define ADC_INTERRUPT_MASK_OFFSET                                   0x008
#define ADC_INTERRUPT_STATUS_AND_CLEAR_OFFSET                       0x00C
#define ADC_OVERFLOW_STATUS_OFFSET                                  0x010
#define ADC_EVENT_MULTIPLEXER_SELECT_OFFSET                         0x014
#define ADC_UNDERFLOW_STATUS_OFFSET                                 0x018
#define ADC_TRIGGER_SOURCE_SELECT_OFFSET                            0x01C
#define ADC_SAMPLE_SEQUENCER_PRIORITY_OFFSET                        0x020
#define ADC_SAMPLE_PHASE_CONTROL_OFFSET                             0x024
#define ADC_PROCESSOR_SAMPLE_SEQUENCE_INITIATE_OFFSET               0x028
#define ADC_SAMPLE_AVERAGING_CONTROL_OFFSET                         0x030
#define ADC_DIGITAL_COMPARATOR_INTERRUPT_STATUS_AND_CLEAR_OFFSET    0x034
#define ADC_CONTROL_OFFSET                                          0x038
#define ADC_SAMPLE_SEQUENCE_INPUT_MULTIPLEXER_SELECT_0_OFFSET       0x040
#define ADC_SAMPLE_SEQUENCE_CONTROL_0_OFFSET                        0x044
#define ADC_SAMPLE_SEQUENCE_RESULT_FIFO_0_OFFSET                    0x048
#define ADC_SAMPLE_SEQUENCE_FIFO_0_STATUS_OFFSET                    0x04C
#define ADC_SAMPLE_SEQUENCE_0_OPERATION_OFFSET                      0x050
#define ADC_SAMPLE_SEQUENCE_0_DIGITAL_COMPARATOR_SELECT_OFFSET      0x054
#define ADC_SAMPLE_SEQUENCE_INPUT_MULTIPLEXER_SELECT_1_OFFSET       0x060
#define ADC_SAMPLE_SEQUENCE_CONTROL_1_OFFSET                        0x064
#define ADC_SAMPLE_SEQUENCE_RESULT_FIFO_1_OFFSET                    0x068
#define ADC_SAMPLE_SEQUENCE_FIFO_1_STATUS_OFFSET                    0x06C
#define ADC_SAMPLE_SEQUENCE_1_OPERATION_OFFSET                      0x070
#define ADC_SAMPLE_SEQUENCE_1_DIGITAL_COMPARATOR_SELECT_OFFSET      0x074
#define ADC_SAMPLE_SEQUENCE_INPUT_MULTIPLEXER_SELECT_2_OFFSET       0x080
#define ADC_SAMPLE_SEQUENCE_CONTROL_2_OFFSET                        0x084
#define ADC_SAMPLE_SEQUENCE_RESULT_FIFO_2_OFFSET                    0x088
#define ADC_SAMPLE_SEQUENCE_FIFO_2_STATUS_OFFSET                    0x08C
#define ADC_SAMPLE_SEQUENCE_2_OPERATION_OFFSET                      0x090
#define ADC_SAMPLE_SEQUENCE_2_DIGITAL_COMPARATOR_SELECT_OFFSET      0x094
#define ADC_SAMPLE_SEQUENCE_INPUT_MULTIPLEXER_SELECT_3_OFFSET       0x0A0
#define ADC_SAMPLE_SEQUENCE_CONTROL_3_OFFSET                        0x0A4
#define ADC_SAMPLE_SEQUENCE_RESULT_FIFO_3_OFFSET                    0x0A8
#define ADC_SAMPLE_SEQUENCE_FIFO_3_STATUS_OFFSET                    0x0AC
#define ADC_SAMPLE_SEQUENCE_3_OPERATION_OFFSET                      0x0B0
#define ADC_SAMPLE_SEQUENCE_3_DIGITAL_COMPARATOR_SELECT_OFFSET      0x0B4
#define ADC_DIGITAL_COMPARATOR_RESET_INITIAL_CONDITIONS_OFFSET      0xD00
#define ADC_DIGITAL_COMPARATOR_CONTROL_0_OFFSET                     0xE00
#define ADC_DIGITAL_COMPARATOR_CONTROL_1_OFFSET                     0xE04
#define ADC_DIGITAL_COMPARATOR_CONTROL_2_OFFSET                     0xE08
#define ADC_DIGITAL_COMPARATOR_CONTROL_3_OFFSET                     0xE0C
#define ADC_DIGITAL_COMPARATOR_CONTROL_4_OFFSET                     0xE10
#define ADC_DIGITAL_COMPARATOR_CONTROL_5_OFFSET                     0xE14
#define ADC_DIGITAL_COMPARATOR_CONTROL_6_OFFSET                     0xE18
#define ADC_DIGITAL_COMPARATOR_CONTROL_7_OFFSET                     0xE1C
#define ADC_DIGITAL_COMPARATOR_RANGE_0_OFFSET                       0xE40
#define ADC_DIGITAL_COMPARATOR_RANGE_1_OFFSET                       0xE44
#define ADC_DIGITAL_COMPARATOR_RANGE_2_OFFSET                       0xE48
#define ADC_DIGITAL_COMPARATOR_RANGE_3_OFFSET                       0xE4C
#define ADC_DIGITAL_COMPARATOR_RANGE_4_OFFSET                       0xE50
#define ADC_DIGITAL_COMPARATOR_RANGE_5_OFFSET                       0xE54
#define ADC_DIGITAL_COMPARATOR_RANGE_6_OFFSET                       0xE58
#define ADC_DIGITAL_COMPARATOR_RANGE_7_OFFSET                       0xE5C
#define ADC_PERIPHERAL_PROPERTIES_OFFSET                            0xFC0
#define ADC_PERIPHERAL_CONFIGURATION_OFFSET                         0xFC4
#define ADC_CLOCK_CONFIGURATION_OFFSET                              0xFC8

#endif /* ADC_MEMMAP_H_ */
