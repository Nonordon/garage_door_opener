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

bool accept(){
    if (InputScanner::BUTTON == true){
        InputScanner::BUTTON = false;
        return true;
    }
    else
        return false;
}

void event()
{
    // set direction to 'previously closing' (direction = 1)
    GarageDoorController::direction = 1;
}
