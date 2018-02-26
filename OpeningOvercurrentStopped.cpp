/*
 * OpeningOvercurrentStopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpeningOvercurrentStopped.h"

OpeningOvercurrentStopped::OpeningOvercurrentStopped() {
	// TODO Auto-generated constructor stub
	nextState = 4; //Stopped

}

OpeningOvercurrentStopped::~OpeningOvercurrentStopped() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool OpeningOvercurrentStopped::accept(){
	bool accepted = false;
    if(InputScanner::MUTEX == false){
        // Set MUTEX to True to lock the shared resources temporarily
        MUTEX = true;
        if (InputScanner::OVERCURRENT == true){
            InputScanner::OVERCURRENT = false;
            accepted = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        MUTEX = false;
    }
    return accepted;
}

void OpeningOvercurrentStopped::event()
{
    // set direction to 'previously opening' (0)
    GarageDoorController::direction = 0;
}
