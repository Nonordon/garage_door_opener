/*
 * ClosingFullclosedClosed.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingFullclosedClosed.h"

ClosingFullclosedClosed::ClosingFullclosedClosed() {
	// TODO Auto-generated constructor stub
	nextState = 0; //Closed

}

ClosingFullclosedClosed::~ClosingFullclosedClosed() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosingFullclosedClosed::guard()
{
    // If position set to 0 (closed) return true
    if (GarageDoorController::position == 0)
        return true;
    else
        return false;
}

/*
bool accept(){
	bool accepted = false;
    if(InputScanner::MUTEX == false){
        // Set MUTEX to True to lock the shared resources temporarily
        MUTEX = true;
        if (InputScanner::FULLCLOSED == true){
            InputScanner::FULLCLOSED = false;
            accepted = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        MUTEX = false;
    }
    return accepted;
}*/
