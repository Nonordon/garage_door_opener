/*
 * State.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#include "State.h"
#include <iostream>

State::State(Output* inOutput) {
    // TODO Auto-generated constructor stub
	if (!inOutput)
	{
		output = inOutput;
	}
}

State::~State() {
    // TODO Auto-generated destructor stub
}
