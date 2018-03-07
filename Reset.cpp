/*
 * Reset.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Nonordon
 */

#include "Reset.h"

Reset::Reset(std::queue<char>* inQueue) : Transition(inQueue)  {
	// TODO Auto-generated constructor stub

}

Reset::~Reset() {
	// TODO Auto-generated destructor stub
}

bool Reset::accept(char* ev)
{
	if (*ev == 's')
	{
		return true;
	}
	return false;
}
void Reset::event()
{
	ioqueue->push('s');
}
