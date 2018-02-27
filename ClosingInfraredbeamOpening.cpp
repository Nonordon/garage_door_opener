/*
 * ClosingInfraredbeamOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingInfraredbeamOpening.h"
#include "InputScanner.h"

ClosingInfraredbeamOpening::ClosingInfraredbeamOpening() {
	// TODO Auto-generated constructor stub
	nextState = 3; //Opening

}

ClosingInfraredbeamOpening::~ClosingInfraredbeamOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool ClosingInfraredbeamOpening::accept(){
	bool accepted = false;
    if(InputScanner::MUTEX == false){
        // Set MUTEX to True to lock the shared resources temporarily
    	InputScanner::MUTEX = true;
        if (InputScanner::IRBEAMTRIP == true){
            InputScanner::IRBEAMTRIP = false;
            accepted = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        InputScanner::MUTEX = false;
    }
    return accepted;
}
