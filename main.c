#include "general.h"
#include "motor.h"
int main()
{
    vEngineInit();
	vSetEngineDir(FORWARD);
	vSetEngineSpeed(50);
	T_U8 i = 1;
    while(1)
    {

		if( 10 < i)
		{
			i = 1;
		}
        vSetEngineSpeed(10*i);
		__delay_ms(300);
		i++;

    }

    return 0;
}