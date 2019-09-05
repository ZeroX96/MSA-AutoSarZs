/*
 * HW_TYPES.h
 *
 *  Created on: 18 Oct 2018
 *      Author: Mahmoud
 */

#ifndef HW_TYPES_H_
#define HW_TYPES_H_
//#include "includes.h"
#include "Std_Types.h"

static inline void HW_WRITE_REG(uint32 add,uint8 val)
{
    ((*(volatile uint32 *)add)=val);
}
static inline void HW_WRITE_ORING_REG(uint32 add,uint8 val)
{
    ((*(volatile uint32 *)add)|=val);
}

static inline uint32 HW_READ_REG(uint32 add)
{
    return (*(volatile uint32 *)add);
}


static inline void HW_SET_REG_BIT(uint32 add,uint8 bit)
{
    ((*(volatile uint32 *)add) |= (1<<bit));
}

static inline void HW_CLR_REG_BIT(uint32 add,uint8 bit)
{
    ((*(volatile uint32 *)add) &=~(1<<bit));
}


static inline uint8 HW_READ_REG_BIT(uint32 add,uint8 bit)
{
    return ((*(volatile uint32 *)add) & (1<<bit));
}

#endif /* HW_TYPES_H_ */
