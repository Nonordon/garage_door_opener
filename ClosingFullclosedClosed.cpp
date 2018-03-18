/*
 * ClosingFullclosedClosed.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include "ClosingFullclosedClosed.h"

ClosingFullclosedClosed::ClosingFullclosedClosed(std::queue<char>* inQueue) : Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 0; //Closed

}

ClosingFullclosedClosed::~ClosingFullclosedClosed() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosingFullclosedClosed::guard(void* GDC)
{
    // If position set to 0 (closed) return true
    if (((GarageDoorController*)GDC)->position == 0)
        return true;
    else
        return false;
}
