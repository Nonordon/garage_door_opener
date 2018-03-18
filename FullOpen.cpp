/*
 * FullOpen.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include "FullOpen.h"

FullOpen::FullOpen(std::queue<char>* inQueue) : Transition(inQueue){
	// TODO Auto-generated constructor stub

}

FullOpen::~FullOpen() {
	// TODO Auto-generated destructor stub
}

bool FullOpen::accept(char* ev)
{
	if (*ev == 'o')
	{
		return true;
	} else
	{
		return false;
	}
}

void FullOpen::event()
{
	ioqueue->push('o');
}
