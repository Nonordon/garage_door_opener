/*
 * Opening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Opening.h"

Opening::Opening() {
	// TODO Auto-generated constructor stub

}

Opening::~Opening() {
	// TODO Auto-generated destructor stub
}


void reaction()
{
    // Increment position once per second (until position == 10)
	while (GarageDoorController::position < 10){
		usleep(1000);
		GarageDoorController::position++;
	}
}
