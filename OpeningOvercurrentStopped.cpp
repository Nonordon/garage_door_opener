/*
 * OpeningOvercurrentStopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpeningOvercurrentStopped.h"
#include "GarageDoorController.h"

OpeningOvercurrentStopped::OpeningOvercurrentStopped(std::queue<char>* inQueue) : Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 4; //Stopped

}

OpeningOvercurrentStopped::~OpeningOvercurrentStopped() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool OpeningOvercurrentStopped::accept(char* ev)
{
	if (*ev == 'm')
	{
		return true;
	} else
	{
		return false;
	}
}

void OpeningOvercurrentStopped::event(void* GDC)
{
    // set direction to 'previously opening' (0)
    ((GarageDoorController*)GDC)->direction = 0;
}
