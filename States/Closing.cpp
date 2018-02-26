/*
 * Closing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Closing.h"

Closing::Closing() {
	// TODO Auto-generated constructor stub

}

Closing::~Closing() {
	// TODO Auto-generated destructor stub
}

void entry()
{
    // Turn ON Beam
	Output::turnOnBeam();
}

void exit()
{
    // Turn OFF Beam
	Output::turnOffBeam();
}

void reaction()
{
    // Decrement position once per second (until position == 0)
	while (GarageDoorController::position > 0){
		usleep(1000);
		GarageDoorController::position--;
	}
}
