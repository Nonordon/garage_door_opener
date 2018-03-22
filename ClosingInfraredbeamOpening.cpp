/*
 * ClosingInfraredbeamOpening.cpp
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#include "ClosingInfraredbeamOpening.h"

ClosingInfraredbeamOpening::ClosingInfraredbeamOpening(std::queue<char>* inQueue) : Transition(inQueue){
	// TODO Auto-generated constructor stub
	nextState = 3; //Opening

}

ClosingInfraredbeamOpening::~ClosingInfraredbeamOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosingInfraredbeamOpening::accept(char* ev)
{
	if (*ev == 'i')
	{
		return true;
	} else
	{
		return false;
	}
}
