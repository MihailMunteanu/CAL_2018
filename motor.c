#include"general.h"
#include"mcal_pwm.h"
#include"mcal_gpio.h"
#include"motor.h"

void vEngineInit(void)
{
	GPIO_u8SetPortPin(PORT_A,9,DIGITAL,FORWARD);
}
void vSetEngineDir(BOOL bDir)
{
	GPIO_u8WritePortPin(PORT_A,9,bDir);
}
void vSetEngineSpeed(T_U8 u8Speed)
{
	if ( 100 < u8Speed )
	{
		u8Speed = 100;
	}
	if ( 0 > u8Speed )
	{
		u8Speed = 0;
	}
	PWM1_vSetDuty(u8Speed,2);
}