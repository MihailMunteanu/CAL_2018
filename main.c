#include "sys_tasks.h"
#include "sys_schedule.h"
#pragma config ICS = PGD2               // Comm Channel Select (Communicate on PGC2/EMUC2 and PGD2/EMUD2)
#pragma config JTAGEN = ON              // JTAG Port Enable (JTAG is Enabled)
int main()
{
	TASK_Inits();
	TASK_vSchedule(); //we need to comment THIS if we want to test in main

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

////for linefollower
//	T_U8 u8lineFollowerBits = 0;
//	while(1)
//	{
//	u8lineFollowerBits = vReadLineFollowerPin();
//		if ( 0 == u8lineFollowerBits )
//		{
//			vSetEngineDir(FORWARD);
//			vSetEngineSpeed(20);
//		}
//		else
//		{
//			vSetEngineDir(BACKWARD);
//			vSetEngineSpeed(20);
//		}
//	}

//for 


    return 0;
}