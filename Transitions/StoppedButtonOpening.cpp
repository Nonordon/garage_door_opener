/*
 * StoppedButtonOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "StoppedButtonOpening.h"

StoppedButtonOpening::StoppedButtonOpening() {
	// TODO Auto-generated constructor stub

}

StoppedButtonOpening::~StoppedButtonOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool guard()
{
	// If direction set to 1 (previously Closing) return true
	if (GarageDoorController::direction == 1)
		return true;
	else
		return false;
}

bool accept(){
    if (InputScanner::BUTTON == true){
        InputScanner::BUTTON = false;
        return true;
    }
    else
        return false;
}
