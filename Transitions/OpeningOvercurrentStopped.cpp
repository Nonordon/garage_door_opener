/*
 * OpeningOvercurrentStopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpeningOvercurrentStopped.h"

OpeningOvercurrentStopped::OpeningOvercurrentStopped() {
	// TODO Auto-generated constructor stub

}

OpeningOvercurrentStopped::~OpeningOvercurrentStopped() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

void event()
{
    // set direction to 'previously opening' (0)
    GarageDoorController::direction = 0;
}
