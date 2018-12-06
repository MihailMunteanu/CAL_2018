/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"

#include "mcal_init.h"

void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL, OUTPUT);	
	vEngineInit();
}

void TASK_1ms()
{

}

void TASK_5ms()
{

}

void TASK_10ms()
{   

}

void TASK_100ms()
{ 
	static T_U8 i = 60;
	static T_S8 directie = 1;
    i=i+directie;
	vServoPosition(i);
	if (( 120 == i ) || ( 60 == i))
	{
		directie = directie * (-1);
	}
}

void TASK_500ms()
{ 

}

void TASK_1000ms()
{

}