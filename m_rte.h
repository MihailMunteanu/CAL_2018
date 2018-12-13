#ifndef M_RTE_H
#define	M_RTE_H


//#ifndef MOTOR_H
#include "motor.h"
//#endif
//#ifndef SERVOMOTOR_H
#include "servomotor.h"
//#endif
//#ifndef  LINEFOLLOWER_H
#include "linefollower.h"
//#endif
//#ifndef  GENERAL_H
//#include "general.h"
//#endif

#define RTE_vLineFollowerInit(a)	vLineFollowerInit(a)
#define RTE_vSetLineFolowerPin(a)	vSetLineFolowerPin(a)
#define RTE_vReadLineFollowerPin()	vReadLineFollowerPin()
#define RTE_vServoPosition(a)		vServoPosition(a)
#define RTE_vEngineInit()			vEngineInit()
#define RTE_vSetEngineDir(a)		vSetEngineDir(a)
#define RTE_vSetEngineSpeed(a)		vSetEngineSpeed(a)


#endif	/* M_RTE_H */