/*
 * OpenButtonClosing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpenButtonClosing.h"
#include "InputScanner.h"
OpenButtonClosing::OpenButtonClosing(std::queue<char>* inQueue) : Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 1; //Closing

}

OpenButtonClosing::~OpenButtonClosing() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool OpenButtonClosing::accept(char* ev)
{
	if (*ev == 'r')
	{
		return true;
	} else
	{
		return false;
	}
}
