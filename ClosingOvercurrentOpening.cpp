/*
 * ClosingOvercurrentOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingOvercurrentOpening.h"
#include "InputScanner.h"

ClosingOvercurrentOpening::ClosingOvercurrentOpening(std::queue<char>* inQueue) : Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 3; //Opening

}

ClosingOvercurrentOpening::~ClosingOvercurrentOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosingOvercurrentOpening::accept(char* ev)
{
	if (*ev == 'm')
	{
		return true;
	} else
	{
		return false;
	}
}
