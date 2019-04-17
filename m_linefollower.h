#ifndef M_LINEFOLLOWER_H
#define	M_LINEFOLLOWER_H

#include "general.h"
#include "mcal_gpio.h"

void vLineFollowerInit(BOOL INOUT);
void vSetLineFolowerPin(BOOL bValue);
T_U8 vReadLineFollowerPin();


#endif	/* M_LINEFOLLOWER_H */