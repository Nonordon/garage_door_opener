/*
 * OpeningButtonStopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpeningButtonStopped.h"

OpeningButtonStopped::OpeningButtonStopped() {
	// TODO Auto-generated constructor stub

}

OpeningButtonStopped::~OpeningButtonStopped() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

void event()
{
    // set direction to 'previously opening' (0)
	GarageDoorController::direction = 0;
}
