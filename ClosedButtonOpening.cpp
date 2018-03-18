/*
 * ClosedButtonOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include "ClosedButtonOpening.h"
#include "InputScanner.h"

ClosedButtonOpening::ClosedButtonOpening(std::queue<char>* inQueue): Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 3; //Opening
	//ioqueue = inQueue;

}

ClosedButtonOpening::~ClosedButtonOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosedButtonOpening::accept(char* ev)
{
	if (*ev == 'r')
	{
		return true;
	} else
	{
		return false;
	}
}
