#include "m_battery.h"



T_F16 vBatteryPercent(void)
{
	static T_F16 f16BatteryTable[2][4] = {{8.3,7,6.5,6},{100,20,10,0}};
	T_U16 i = 0;
	BOOL bWhileFlag = TRUE;
	T_F16 f16Resolution = 0;
	T_F16 f16ChargeValue = 0;
	//read value
	T_F16 f16VoltageRead = 0;
	f16VoltageRead = (f16ReferenceVoltage / u16MaxValueRaw * ADC_u16Read(0)) * 4;
	
	//check interval
	while ( bWhileFlag )
	{
		i++;
		if( f16BatteryTable[0][i] > f16VoltageRead)
		{
			bWhileFlag = FALSE;
		}
	}
	//calculate percent
	f16Resolution = ( f16BatteryTable[1][i-1] - f16BatteryTable[1][i] ) / ( f16BatteryTable[0][i-1] - f16BatteryTable[0][i] );
	f16ChargeValue = ( f16VoltageRead - f16BatteryTable[0][i]) * f16Resolution + f16BatteryTable[1][i];
	return f16ChargeValue;
}