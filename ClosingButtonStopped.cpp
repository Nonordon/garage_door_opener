/*
 * ClosingButtonStopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingButtonStopped.h"
#include "InputScanner.h"
#include "GarageDoorController.h"

ClosingButtonStopped::ClosingButtonStopped() {
	// TODO Auto-generated constructor stub
	nextState = 4; //Stopped

}

ClosingButtonStopped::~ClosingButtonStopped() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosingButtonStopped::accept(){
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

void ClosingButtonStopped::event()
{
    // set direction to 'previously closing' (direction = 1)
    GarageDoorController::direction = 1;
}
