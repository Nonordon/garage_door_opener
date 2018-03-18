/*
 * FullClose.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include "FullClose.h"
#include <iostream>

FullClose::FullClose(std::queue<char>* inQueue) : Transition(inQueue) {
	// TODO Auto-generated constructor stub

}

FullClose::~FullClose() {
	// TODO Auto-generated destructor stub
}

bool FullClose::accept(char* ev)
{
	if (*ev == 'c')
	{
		return true;
	}
	return false;
}
void FullClose::event()
{
	ioqueue->push('c');
}
