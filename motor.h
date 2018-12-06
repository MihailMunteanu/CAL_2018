#ifndef MOTOR_H
#define	MOTOR_H

#define FORWARD (0)
#define BACKWARD (1)

void vEngineInit(void);
void vSetEngineDir(BOOL bDir);
void vSetEngineSpeed(T_U8 u8Speed);


#endif	/* MOTOR_H */