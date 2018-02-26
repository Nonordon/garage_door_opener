/*
 * ClosedButtonOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosedButtonOpening.h"

ClosedButtonOpening::ClosedButtonOpening() {
	// TODO Auto-generated constructor stub
	nextState = 3; //Opening

}

ClosedButtonOpening::~ClosedButtonOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosedButtonOpening::accept(){
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
