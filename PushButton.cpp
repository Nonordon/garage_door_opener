/*
 * PushButton.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#include "PushButton.h"

PushButton::PushButton() {
	// TODO Auto-generated constructor stub

}

PushButton::~PushButton() {
	// TODO Auto-generated destructor stub
}

bool PushButton::getEvent(unsigned char* event)
{
	if (*event == 'r')
	{
		return true;
	} else
	{
		return false;
	}
}
