/*
 * ClosingInfraredbeamOpening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "ClosingInfraredbeamOpening.h"

ClosingInfraredbeamOpening::ClosingInfraredbeamOpening() {
	// TODO Auto-generated constructor stub

}

ClosingInfraredbeamOpening::~ClosingInfraredbeamOpening() {
	// TODO Auto-generated destructor stub
}

// guard, accept, event

bool accept(){
    if (InputScanner::IRBEAMTRIP == true){
        InputScanner::IRBEAMTRIP = false;
        return true;
    }
    else
        return false;
}
