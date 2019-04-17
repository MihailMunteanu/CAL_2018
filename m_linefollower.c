#include"m_linefollower.h"

void vLineFollowerInit(BOOL INOUT) //initialize pin as input or output
{
	T_U16 i;
	for (i = 5; i >= 0; i--)
	{
		GPIO_u8SetPortPin(PORT_C,i,DIGITAL,INOUT);
	}
}

void vSetLineFolowerPin(BOOL bValue) //set pin value to logicall 1 or 0
{
	T_U16 i;
	for (i = 5; i >= 0; i--)
	{
		GPIO_u8WritePortPin(PORT_C,i,bValue);
	}
}

T_U8 vReadLineFollowerPin() //read pin value
{
	T_U16 u16PortValue = 0;
	vLineFollowerInit(OUTPUT);
	vSetLineFolowerPin(1);
	__delay_us(10);
	vLineFollowerInit(INPUT);
	__delay_us(250);
	u16PortValue = GPIO_u16ReadPort(PORT_C);
	u16PortValue = u16PortValue & 63; //63 = first 6 bits (LSB)
	//u8returnValue = u8returnValue | u16PortValue; 
	return 	(T_U8)u16PortValue;
}