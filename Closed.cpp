/*
 * Closed.cpp
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#include "Closed.h"
#include "Output.h"

Closed::Closed(){
	// TODO Auto-generated constructor stub
}

Closed::~Closed() {
	// TODO Auto-generated destructor stub
}

// entry, exit, reaction

void Closed::entry()
{
	Output::fullClose();
}
