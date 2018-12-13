/* 
 * File:   sys_tasks.h
 * Author: Cristian T. A.
 *
 * Created on August 17, 2018, 1:26 PM
 */

#include "general.h"
#include "sys_tasks.h"
#include "mcal_init.h"
#include "m_asw.h"





void TASK_Inits()
{
    MCAL_vInit();
    GPIO_u8SetPortPin(PORT_A, 10, DIGITAL, OUTPUT);	
	RTE_vEngineInit();
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
	vFollowLine();
}

void TASK_500ms()
{ 

}

void TASK_1000ms()
{

}