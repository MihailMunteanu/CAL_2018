#include"general.h"
#include"mcal_pwm.h"
#include"mcal_gpio.h"
#include"motor.h"

void vEngineInit(void)
{
	GPIO_u8SetPortPin(PORT_A,9,DIGITAL,FORWARD);
	PWM1_vInit();
}
void vSetEngineDir(BOOL bDir)
{
	GPIO_u8WritePortPin(PORT_A,9,bDir);
}
void vSetEngineSpeed(T_U8 u8Speed)
{
	PWM1_vSetDuty(u8Speed,2);
}