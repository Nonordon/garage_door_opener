/*
 * MotorOvercurrent.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#include "MotorOvercurrent.h"

MotorOvercurrent::MotorOvercurrent() {
	// TODO Auto-generated constructor stub

}

MotorOvercurrent::~MotorOvercurrent() {
	// TODO Auto-generated destructor stub
}

bool MotorOvercurrent::getEvent(unsigned char* event)
{
	if (*event == 'm')
	{
		return true;
	} else
	{
		return false;
	}

}
