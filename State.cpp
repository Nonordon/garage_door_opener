/*
 * State.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#include "State.h"

State::State(void* inOutput) {
    // TODO Auto-generated constructor stub
	if (!inOutput)
	{
		output = (Output*)inOutput;
	}
}

State::~State() {
    // TODO Auto-generated destructor stub
}
