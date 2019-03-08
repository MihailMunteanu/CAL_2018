/* 
 * File:   m_obstacle.h
 * Author: Mihail
 *
 * Created on 07 martie 2019, 18:31
 */

#ifndef M_OBSTACLE_H
#define	M_OBSTACLE_H

#include"general.h"
#include"mcal_gpio.h"
#include"mcal_interrupts.h"
#include"motor.h"

extern BOOL bObstDetected;

void vReactToObstacle(void);

#endif	/* M_OBSTACLE_H */

