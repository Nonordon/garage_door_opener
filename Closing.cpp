/*
 * Closing.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: Nonordon
 */

#include "Closing.h"
#include "Output.h"
#include "GarageDoorController.h"

void Closing::entry()
{
	Output::turnOnBeam();
}

void Closing::exit()
{
	Output::turnOffBeam();
}

void Closing::reaction()
{
	GarageDoorController::position--;
}
