/*
 * Open.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Open.h"

Open::Open(Output* inOutput) {
	// TODO Auto-generated constructor stub
	output = *inOutput;
}

Open::~Open() {
	// TODO Auto-generated destructor stub
}

// entry, exit, reaction
void Open::entry()
{
	output.fullOpen();
}
