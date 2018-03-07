/*
 * ClosingFullclosedClosed.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingFullclosedClosed.h"
#include "GarageDoorController.h"
#include "Output.h"

ClosingFullclosedClosed::ClosingFullclosedClosed(std::queue<char>* inQueue) : Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 0; //Closed

}

ClosingFullclosedClosed::~ClosingFullclosedClosed() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosingFullclosedClosed::accept(char* ev)
{
	if (!Output::simulation)
	{
		if (*ev == 'c')
		{
			return true;
		} else
		{
			return false;
		}
	} else
	{
		return true;
	}
}

bool ClosingFullclosedClosed::guard(void* GDC)
{
    // If position set to 0 (closed) return true
	if (Output::simulation)
	{
		if (((GarageDoorController*)GDC)->position == 0)
			return true;
		else
			return false;
	} else
	{
		return true;
	}
}

