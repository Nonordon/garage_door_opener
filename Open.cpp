/*
 * Open.cpp
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#include "Open.h"
#include "Output.h"

Open::Open() {
	// TODO Auto-generated constructor stub
}

Open::~Open() {
	// TODO Auto-generated destructor stub
}

// entry, exit, reaction
void Open::entry()
{
	Output::fullOpen();
}
