/*
 * ClosedButtonOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosedButtonOpening.h"

ClosedButtonOpening::ClosedButtonOpening() {
	// TODO Auto-generated constructor stub

}

ClosedButtonOpening::~ClosedButtonOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool accept(){
    if (InputScanner::BUTTON == true){
        InputScanner::BUTTON = false;
        return true;
    }
    else
        return false;
}
