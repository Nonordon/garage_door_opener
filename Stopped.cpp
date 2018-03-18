/*
 * Stopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include "Stopped.h"

Stopped::Stopped(Output* inOutput) : State(inOutput){
	// TODO Auto-generated constructor stub

}

Stopped::~Stopped() {
	// TODO Auto-generated destructor stub
}

// entry, exit, reaction

void Stopped::entry()
{
	output->setMotorOff();
}
