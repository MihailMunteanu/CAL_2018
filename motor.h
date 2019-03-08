#ifndef MOTOR_H
#define	MOTOR_H

#include"general.h"
#include"mcal_pwm.h"
#include"mcal_gpio.h"

#define FORWARD (0)
#define BACKWARD (1)

void vEngineInit(void);
void vSetEngineDir(BOOL bDir);
void vSetEngineSpeed(T_U8 u8Speed);


#endif	/* MOTOR_H */