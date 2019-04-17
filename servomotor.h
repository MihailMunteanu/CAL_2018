#ifndef SERVOMOTOR_H
#define	SERVOMOTOR_H

#include"general.h"
#include"mcal_pwm.h"

#define offsetServoAngle 10
#define offsetServoFill 4
#define resolution 0.04375 //(7 / 160)
#define maxAngle 170

void vServoPosition(T_U8 u8Angle);


#endif	/* SERVOMOTOR_H */