/*
 * StoppedButtonClosing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "StoppedButtonClosing.h"

StoppedButtonClosing::StoppedButtonClosing() {
    // TODO Auto-generated constructor stub
	nextState = null;
}

StoppedButtonClosing::~StoppedButtonClosing() {
    // TODO Auto-generated destructor stub
}

// guard, accept, event

bool guard()
{
	// If direction set to 0 (previously Opening) return true
	if (GarageDoorController::direction == 0)
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