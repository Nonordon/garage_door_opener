/*
 * Closed.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Closed.h"

Closed::Closed(Output* inOutput) {
	// TODO Auto-generated constructor stub
	output = *inOutput;
}

Closed::~Closed() {
	// TODO Auto-generated destructor stub
}

// entry, exit, reaction

void Closed::entry()
{
	output.fullClose();
}
