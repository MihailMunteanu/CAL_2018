#include"general.h"
#include"mcal_pwm.h"
#include"servomotor.h"


void vServoPosition(T_U8 u8Angle)
{
	T_F16 fDuty = 7.5;
	if (u8Angle < 60)
	{
		u8Angle = 60;
	}
	if (u8Angle > 120)
	{
		u8Angle = 120;
	}
	fDuty = offsetServoFill + resolution * (u8Angle - offsetServoAngle);
	PWM1_vSetDuty(fDuty,1);
}