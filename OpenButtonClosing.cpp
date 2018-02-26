/*
 * OpenButtonClosing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpenButtonClosing.h"
#include "InputScanner.h"
OpenButtonClosing::OpenButtonClosing() {
	// TODO Auto-generated constructor stub
	nextState = 1; //Closing

}

OpenButtonClosing::~OpenButtonClosing() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool OpenButtonClosing::accept(){
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
