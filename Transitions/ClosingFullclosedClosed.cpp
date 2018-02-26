/*
 * ClosingFullclosedClosed.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingFullclosedClosed.h"

ClosingFullclosedClosed::ClosingFullclosedClosed() {
	// TODO Auto-generated constructor stub

}

ClosingFullclosedClosed::~ClosingFullclosedClosed() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool guard()
{
    // If position set to 0 (closed) return true
    if (GarageDoorController::position == 0)
        return true;
    else
        return false;
}

/*
bool accept(){
    if (InputScanner::FULLCLOSED == true){
        InputScanner::FULLCLOSED = false;
        return true;
    }
    else
        return false;
}*/
