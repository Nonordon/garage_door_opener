/*
 * StoppedButtonClosing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "StoppedButtonClosing.h"
#include "InputScanner.h"
#include "GarageDoorController.h"

StoppedButtonClosing::StoppedButtonClosing() {
    // TODO Auto-generated constructor stub
	nextState = 1; //Closing

}

StoppedButtonClosing::~StoppedButtonClosing() {
    // TODO Auto-generated destructor stub
}

// guard, accept, event

bool StoppedButtonClosing::guard()
{
	// If direction set to 0 (previously Opening) return true
	if (GarageDoorController::direction == 0)
		return true;
	else
		return false;
}

bool StoppedButtonClosing::accept(){
	bool accepted = false;
    if(InputScanner::MUTEX == false){
        // Set MUTEX to True to lock the shared resources temporarily
    	InputScanner::MUTEX = true;
        if (InputScanner::BUTTON == true){
            InputScanner::BUTTON = false;
            accepted = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        InputScanner::MUTEX = false;
    }
    return accepted;
}
