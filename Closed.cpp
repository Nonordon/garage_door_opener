/*
 * Closed.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Closed.h"
#include <iostream>

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
