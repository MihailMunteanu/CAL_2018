#ifndef SERVOMOTOR_H
#define	SERVOMOTOR_H

#define offsetServoAngle 10
#define offsetServoFill 4
#define resolution 0.04375 //(7 / 160)
#define maxAngle 170

void vServoPosition(T_U8 u8Angle);


#endif	/* SERVOMOTOR_H */