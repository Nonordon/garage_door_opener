/*
 * StoppedButtonOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "StoppedButtonOpening.h"

StoppedButtonOpening::StoppedButtonOpening() {
	// TODO Auto-generated constructor stub
	nextState = 3; //Opening

}

StoppedButtonOpening::~StoppedButtonOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool StoppedButtonOpening::guard()
{
	// If direction set to 1 (previously Closing) return true
	if (GarageDoorController::direction == 1)
		return true;
	else
		return false;
}

bool StoppedButtonOpening::accept(){
	bool accepted = false;
    if(InputScanner::MUTEX == false){
        // Set MUTEX to True to lock the shared resources temporarily
        MUTEX = true;
        if (InputScanner::BUTTON == true){
            InputScanner::BUTTON = false;
            accepted = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        MUTEX = false;
    }
    return accepted;
}
