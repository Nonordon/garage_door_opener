/*
 * PushButton.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#include "PushButton.h"

PushButton::PushButton(std::queue<char>* inQueue) : Transition(inQueue){
	// TODO Auto-generated constructor stub

}

PushButton::~PushButton() {
	// TODO Auto-generated destructor stub
}

bool PushButton::accept(char* ev)
{
	if (*ev == 'r')
	{
		return true;
	} else
	{
		return false;
	}
}
void PushButton::event()
{
	ioqueue->push('r');
}

