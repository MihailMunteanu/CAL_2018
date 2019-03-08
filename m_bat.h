#ifndef M_BAT_H
#define	M_BAT_H

#include"general.h"
#include"mcal_gpio.h"
#include "mcal_adc.h"

#define u16MaxValueRaw (4095)
#define f16ReferenceVoltage (3.07) 

T_F16 vBatteryPercent(void);

#endif	/* M_BAT_H */