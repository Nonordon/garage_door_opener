/*
 * MotorOvercurrent.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#include "MotorOvercurrent.h"

MotorOvercurrent::MotorOvercurrent(std::queue<char>* inQueue) : Transition(inQueue){
	// TODO Auto-generated constructor stub

}

MotorOvercurrent::~MotorOvercurrent() {
	// TODO Auto-generated destructor stub
}

bool MotorOvercurrent::accept(char* ev)
{
	if (*ev == 'm')
	{
		return true;
	} else
	{
		return false;
	}

}
void MotorOvercurrent::event()
{
	ioqueue.push('m');
}
