/*
 * ClosingButtonStopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingButtonStopped.h"

ClosingButtonStopped::ClosingButtonStopped(std::queue<char>* inQueue): Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 4; //Stopped

}

ClosingButtonStopped::~ClosingButtonStopped() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosingButtonStopped::accept(char* ev)
{
	if (*ev == 'r')
	{
		return true;
	} else
	{
		return false;
	}
}

void ClosingButtonStopped::event(void* GDC)
{
    // set direction to 'previously closing' (direction = 1)
	((GarageDoorController*)GDC)->direction = 1;
}
