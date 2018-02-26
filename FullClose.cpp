/*
 * FullClose.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#include "FullClose.h"
#include <iostream>

FullClose::FullClose() {
	// TODO Auto-generated constructor stub

}

FullClose::~FullClose() {
	// TODO Auto-generated destructor stub
}

bool FullClose::getEvent(unsigned char* event)
{
	if (*event == 'c')
	{
		return true;
	} else
	{
		return false;
	}
}
