/*
 * OpeningButtonStopped.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpeningButtonStopped.h"
#include "InputScanner.h"
#include "GarageDoorController.h"

OpeningButtonStopped::OpeningButtonStopped() {
	// TODO Auto-generated constructor stub
	nextState = 4; //Stopped

}

OpeningButtonStopped::~OpeningButtonStopped() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool OpeningButtonStopped::accept(){
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

void OpeningButtonStopped::event()
{
    // set direction to 'previously opening' (0)
	GarageDoorController::direction = 0;
}
