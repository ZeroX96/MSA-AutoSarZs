/*
 * Sys.c
 *
 *  Date	: Aug 30, 2019
 *  Author  : MahmoudSaad.ZeroX-86
 *  Email   : msammamsa10@gmail.com
 *  Github  : github.com/zerox-86
 *  LinkedIn: www.linkedin.com/in/zerox86
 *  FaceBook: www.facebook.com/ZeroX86.MSA
 */

#include "Sys.h"


system_errors_t  sys_enable_module(module_name_t module_name ,module_numb_t module_numb)
{
    system_errors_t ret_val=NO_SYS_ERROR;
    if( ( (module_name >= LOWEST_MODULE_NAME_VAL) && (module_name <= HIGHEST_MODULE_NAME_VAL) ) &&\
        ( ( module_numb >= LOWEST_MODULE_NUMB_VAL ) && ( module_numb <= HIGHEST_MODULE_NUMB_VAL ) )
       ) {
                switch (module_name) {
                case GPIO:
                    HW_SET_REG_BIT(CGC_GPIO_REG,module_numb);
                    break;
                case ADC:
                    HW_SET_REG_BIT(CGC_ADC_REG,module_numb);
                    break;
                case UDMA:
                    //donothing_till_now:D
                    break;
                default: //do_nothing :D
                    break;
                }

            }
    else
        {
            ret_val=SYS_ERROR_INV_PARAMS;
        }
    return ret_val;
}

system_errors_t  sys_disable_module(module_name_t module_name ,module_numb_t module_numb)
{
    system_errors_t ret_val=NO_SYS_ERROR;
    if( ( (module_name >= LOWEST_MODULE_NAME_VAL) && (module_name <= HIGHEST_MODULE_NAME_VAL) ) &&
        ( ( module_numb >= LOWEST_MODULE_NUMB_VAL ) && ( module_numb <= HIGHEST_MODULE_NUMB_VAL ) )
       )
            {
                switch (module_name) {
                case GPIO:
                    HW_CLR_REG_BIT(CGC_GPIO_REG,module_numb);
                    break;
                case ADC:
                    HW_CLR_REG_BIT(CGC_ADC_REG,module_numb);
                    break;
                case UDMA:
                    //donothing_till_now:D
                    break;
                default: //do_nothing :D
                    break;
                }

            }
    else
        {
            ret_val=SYS_ERROR_INV_PARAMS;
        }
    return ret_val;
}
