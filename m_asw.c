#include "m_asw.h"

static BOOL bStopExecution = 0;

void vFollowLine(void)
{
    if ( 0 == bStopExecution )
    {
        static T_U8 u8Speed = 30;           //initial speed
        static T_U8 u8lineFollowerBits = 0; //sensor output on 6bits
        static T_U8 u8Direction = 90;       //straight
        static BOOL bLastTapeSeen = 1;      //has 1-seen/0-not seen tape
        
        static T_U8 u8RoadID = 0;           //track ID that has to be sent to all the cars
        static BOOL bIsOnRoad = 0;          //car IS on road has to be sent to all the cars
        static T_S16 u8LineFollowed = 1;    //car direction: 0-right/1-straight/3-left
        //                                  /* thru means UNKNOWN yet*/
        
        T_S16 s16Corection = 2 * (1 - bIsOnRoad) * (1 - u8LineFollowed);
        u8lineFollowerBits = RTE_vReadLineFollowerPin();
        //if it encountered an empty space before AND at least one pin from 3 or 4 is on tape now
        if ( !bLastTapeSeen && (12 & u8lineFollowerBits) ) 
        {
            u8RoadID++;
        }
        if ( 12 & u8lineFollowerBits )
        {
            if ( 60 >= u8Speed ) //ERR - check unsigned value
            {
                u8Speed += 2;
            }
        }
        else
        {
            bLastTapeSeen = 0;
        }
        if ( (2 & u8lineFollowerBits) && (115 >= u8Direction) )
        {
            u8Direction = u8Direction + 2 + s16Corection;
            u8Speed -= 1;
        }
        if ( (16 & u8lineFollowerBits) && (65 <= u8Direction))
        {
            u8Direction = u8Direction - 2 + s16Corection;
            u8Speed -= 1;
        }
        if ( !bIsOnRoad && (30 & u8lineFollowerBits) )
        {
            bIsOnRoad = 1;
        }
        else
            if ( bIsOnRoad && (30 & u8lineFollowerBits) )
            {
                vRun20Cm();
                bIsOnRoad = 0;
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