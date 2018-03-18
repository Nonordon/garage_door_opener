/*
 * InfraredBeamTrip.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include "InfraredBeamTrip.h"

InfraredBeamTrip::InfraredBeamTrip(std::queue<char>* inQueue) : Transition(inQueue) {
	// TODO Auto-generated constructor stub
}

InfraredBeamTrip::~InfraredBeamTrip() {
	// TODO Auto-generated destructor stub
}

bool InfraredBeamTrip::accept(char* ev)
{
	if (*ev == 'i')
	{
		return true;
	} else
	{
		return false;
	}
}
void InfraredBeamTrip::event()
{
	ioqueue->push('i');
}

