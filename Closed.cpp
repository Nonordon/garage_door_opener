/*
 * Closed.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include "Closed.h"

Closed::Closed(Output* inOutput) : State(inOutput){
	// TODO Auto-generated constructor stub
}

Closed::~Closed() {
	// TODO Auto-generated destructor stub
}

// entry, exit, reaction

void Closed::entry()
{
	output->fullClose();
}
