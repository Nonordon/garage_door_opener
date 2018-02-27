/*
 * ClosingOvercurrentOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingOvercurrentOpening.h"
#include "InputScanner.h"

ClosingOvercurrentOpening::ClosingOvercurrentOpening() {
	// TODO Auto-generated constructor stub
	nextState = 3; //Opening

}

ClosingOvercurrentOpening::~ClosingOvercurrentOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosingOvercurrentOpening::accept(){
	bool accepted = false;
    if(InputScanner::MUTEX == false){
        // Set MUTEX to True to lock the shared resources temporarily
    	InputScanner::MUTEX = true;
        if (InputScanner::OVERCURRENT == true){
        	InputScanner::InputScanner::OVERCURRENT = false;
            accepted = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        InputScanner::MUTEX = false;
    }
    return accepted;
}
