#include "m_obstacle.h"


void vReactToObstacle(void)
{
    if ( TRUE == bObstDetected )
    {
        vSetEngineSpeed(0);
    }

}

