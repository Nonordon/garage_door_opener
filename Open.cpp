/*
 * Open.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Open.h"

Open::Open(void* inOutput) : State(inOutput) {
	// TODO Auto-generated constructor stub
}

Open::~Open() {
	// TODO Auto-generated destructor stub
}

// entry, exit, reaction
void Open::entry()
{
	output->fullOpen();
}
