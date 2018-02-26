/*
 * OpeningFullopenOpen.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpeningFullopenOpen.h"

OpeningFullopenOpen::OpeningFullopenOpen() {
	// TODO Auto-generated constructor stub

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
    if (InputScanner::FULLOPEN == true){
        InputScanner::FULLOPEN = false;
        return true;
    }
    else
        return false;
}*/
