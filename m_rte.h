#ifndef M_RTE_H
#define	M_RTE_H


#include "motor.h"
#include "servomotor.h"
#include "linefollower.h"
#include "m_bat.h"
#include "m_qei.h"
#include "m_obstacle.h"
#include "hal_nRF.h"

#define RTE_vLineFollowerInit(a)	vLineFollowerInit(a)
#define RTE_vSetLineFolowerPin(a)	vSetLineFolowerPin(a)
#define RTE_vReadLineFollowerPin()	vReadLineFollowerPin()
#define RTE_vServoPosition(a)		vServoPosition(a)
#define RTE_vEngineInit()			vEngineInit()
#define RTE_vSetEngineDir(a)		vSetEngineDir(a)
#define RTE_vSetEngineSpeed(a)		vSetEngineSpeed(a)
#define RTE_vBatteryPercent()		vBatteryPercent()
#define RTE_vReactToObstacle()		vReactToObstacle()
#define RTE_RF_vCheckIRQ()          RF_vCheckIRQ()
#define RTE_RF_vBeginTransmit(a)    RF_vBeginTransmit(a)
#define RTE_RF_vBeginReceive()      RF_vBeginReceive()


#endif	/* M_RTE_H */