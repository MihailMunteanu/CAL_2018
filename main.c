#include "general.h"
#include "motor.h"
#include "servomotor.h"
#include "sys_tasks.h"
int main()
{
	TASK_Inits();
	TASK_vSchedule();
////#for engine#
//	vSetEngineDir(FORWARD);
//	vSetEngineSpeed(50);
//	T_U8 i = 1;
//
//		if( 10 < i)
//		{
//			i = 1;
//		}
//        vSetEngineSpeed(10*i);
//		__delay_ms(300);
//		i++;
//
//   // }
//
////#for servomotor
//		for (i=60; i<=120; i++)
//		{
//	        vServoPosition(i);
//			__delay_ms(50);
//		}	
//		for (i=120; i>=60; i--)
//		{
//	        vServoPosition(i);
//			__delay_ms(50);
//		}
//
    return 0;
}