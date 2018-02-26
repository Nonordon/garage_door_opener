/*
 * ClosingButtonStopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingButtonStopped.h"

ClosingButtonStopped::ClosingButtonStopped() {
	// TODO Auto-generated constructor stub

}

ClosingButtonStopped::~ClosingButtonStopped() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

void event()
{
    // set direction to 'previously closing' (direction = 1)
    GarageDoorController::direction = 1;
}
