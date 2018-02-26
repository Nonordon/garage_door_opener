/*
 * ClosingOvercurrentOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingOvercurrentOpening.h"

ClosingOvercurrentOpening::ClosingOvercurrentOpening() {
	// TODO Auto-generated constructor stub

}

ClosingOvercurrentOpening::~ClosingOvercurrentOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool accept(){
    if (InputScanner::OVERCURRENT == true){
        InputScanner::OVERCURRENT = false;
        return true;
    }
    else
        return false;
}
