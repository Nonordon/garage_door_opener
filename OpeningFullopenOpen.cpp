/*
 * OpeningFullopenOpen.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpeningFullopenOpen.h"
#include "GarageDoorController.h"
#include "Output.h"

OpeningFullopenOpen::OpeningFullopenOpen(std::queue<char>* inQueue) : Transition(inQueue) {
	// TODO Auto-generated constructor stub
	nextState = 2; //Open

}

OpeningFullopenOpen::~OpeningFullopenOpen() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool OpeningFullopenOpen::accept(char* ev)
{
	if (!Output::simulation)
	{
		if (*ev == 'o')
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

bool OpeningFullopenOpen::guard(void* GDC)
{
    // If position set to 10 (open) return true
	if (Output::simulation)
	{
		if (((GarageDoorController*)GDC)->position == 10)
			return true;
		else
			return false;
	} else
	{
		return true;
	}
}
