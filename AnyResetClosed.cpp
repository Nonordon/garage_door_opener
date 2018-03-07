/*
 * AnyResetClosed.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Nonordon
 */

#include "AnyResetClosed.h"
#include "GarageDoorController.h"

AnyResetClosed::AnyResetClosed(std::queue<char>* inQueue): Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 0;
}

AnyResetClosed::~AnyResetClosed() {
	// TODO Auto-generated destructor stub
}

bool AnyResetClosed::accept(char* ev)
{
	if (*ev == 's')
	{
		return true;
	} else
	{
		return false;
	}
}

void AnyResetClosed::event(void* GDC)
{
	//((GarageDoorController*)GDC)->Output::reset();
}
