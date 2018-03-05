/*
 * Closed.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Closed.h"

Closed::Closed(void* inOutput) : State(inOutput){
	// TODO Auto-generated constructor stub
}

Closed::~Closed() {
	// TODO Auto-generated destructor stub
}

// entry, exit, reaction

void Closed::entry()
{
	output->setMotorOff();
	output->turnOffBeam();
	output->fullClose();
}
