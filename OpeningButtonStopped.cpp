/*
 * OpeningButtonStopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include "OpeningButtonStopped.h"
#include "InputScanner.h"

OpeningButtonStopped::OpeningButtonStopped(std::queue<char>* inQueue) : Transition(inQueue){
	// TODO Auto-generated constructor stub
	nextState = 4; //Stopped

}

OpeningButtonStopped::~OpeningButtonStopped() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool OpeningButtonStopped::accept(char* ev)
{
	if (*ev == 'r')
	{
		return true;
	} else
	{
		return false;
	}
}

void OpeningButtonStopped::event(void* GDC)
{
    // set direction to 'previously opening' (0)
	((GarageDoorController*)GDC)->direction = 0;
}
