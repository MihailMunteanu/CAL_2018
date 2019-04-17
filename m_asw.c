#include "m_asw.h"

static BOOL bStopExecution = 0;

void vFollowLine(void){
    if ( 0 == bStopExecution )
    {
        static T_U8 u8Speed = 20;
        static T_U8 u8lineFollowerBits = 0;
        static T_U8 u8Direction = 90;
        u8lineFollowerBits = RTE_vReadLineFollowerPin();
        if ( (4 & u8lineFollowerBits) && (8 & u8lineFollowerBits) )
        {
    /*
            if ( (10 <= u8Speed) && (20 >= u8Speed) ) //ERR - check unsigned value
            {
                u8Speed =  u8Speed + 5;
            }
    */
        }
        if ( (2 & u8lineFollowerBits) && (115 >= u8Direction) )
        {
            u8Direction +=5;
        }
        if ( (16 & u8lineFollowerBits) && (65 <= u8Direction))
        {
            u8Direction -=5;
        }

        RTE_vServoPosition(u8Direction);
        RTE_vSetEngineDir(FORWARD);
        RTE_vSetEngineSpeed(u8Speed);	
    }
}

void vCheckBattery (void)
{
	if ( 30 >= RTE_vBatteryPercent())
	{
        bStopExecution = 1;
		RTE_vSetEngineSpeed(0);//stop car
	}
	
}
void vRun20Cm(void)
{
    if ( 0 == bStopExecution )
    {
        static T_F16 f16totalCmDriven = 0;
        f16totalCmDriven = f16totalCmDriven + QEI_s16getElapsed();
        if ( 20 <= f16totalCmDriven )
        {
            vFollowLine();
        }
        else
        {
            bStopExecution = 1;
            RTE_vSetEngineSpeed(0);
        }
    }
}