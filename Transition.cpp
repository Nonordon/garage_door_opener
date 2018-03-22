/*
 * Transition.cpp
 *
 *  Created on: Feb 20, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#include "Transition.h"

Transition::Transition(std::queue<char>* inQueue) {
    // TODO Auto-generated constructor stub
	ioqueue = inQueue;
	nextState = 0;
}

Transition::~Transition() {
    // TODO Auto-generated destructor stub
}
