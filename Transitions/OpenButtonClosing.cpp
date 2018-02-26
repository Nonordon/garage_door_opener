/*
 * OpenButtonClosing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "OpenButtonClosing.h"

OpenButtonClosing::OpenButtonClosing() {
	// TODO Auto-generated constructor stub

}

OpenButtonClosing::~OpenButtonClosing() {
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
