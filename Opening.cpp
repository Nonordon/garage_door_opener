/*
 * Opening.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: Nonordon
 */

#include "Opening.h"
#include "GarageDoorController.h"

void Opening::reaction()
{
	GarageDoorController::position++;
}
