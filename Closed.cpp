/*
 * Closed.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Closed.h"
#include <iostream>

Closed::Closed(void* inOutput) : State(inOutput){
	// TODO Auto-generated constructor stub
}

Closed::~Closed() {
	// TODO Auto-generated destructor stub
}

// entry, exit, reaction

void Closed::entry()
{

	std::cout << "Setting Motor" << std::endl;
	output->setMotorOff();
	std::cout << "Motor Set" << std::endl;
	std::cout << "Setting Beam" << std::endl;
	output->turnOffBeam();
	std::cout << "Beam Set" << std::endl;
	std::cout << "Setting Close" << std::endl;
	output->fullClose();
	std::cout << "Close Set" << std::endl;
}
