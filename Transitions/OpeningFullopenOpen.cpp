/*
 * OpeningFullopenOpen.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpeningFullopenOpen.h"

OpeningFullopenOpen::OpeningFullopenOpen() {
	// TODO Auto-generated constructor stub
	nextState = 2; //Open

}

OpeningFullopenOpen::~OpeningFullopenOpen() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool guard()
{
    // If position set to 10 (open) return true
    if (GarageDoorController::position == 10)
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
        if (InputScanner::FULLOPEN == true){
            InputScanner::FULLOPEN = false;
            accepted = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        MUTEX = false;
    }
    return accepted;
}*/
