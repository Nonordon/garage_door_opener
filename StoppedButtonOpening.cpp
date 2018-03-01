/*
 * StoppedButtonOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "StoppedButtonOpening.h"
#include "InputScanner.h"

StoppedButtonOpening::StoppedButtonOpening(std::queue<char>* inQueue) : Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 3; //Opening

}

StoppedButtonOpening::~StoppedButtonOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool StoppedButtonOpening::guard(GarageDoorController* GDC)
{
	// If direction set to 1 (previously Closing) return true
	if (GDC->direction == 1)
		return true;
	else
		return false;
}

bool StoppedButtonOpening::accept(char* ev)
{
	if (*ev == 'r')
	{
		return true;
	} else
	{
		return false;
	}
}
