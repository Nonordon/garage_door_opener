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

bool FullClose::accept(char* ev)
{
	if (*ev == 'c')
	{
		return true;
	}
	return false;
}

void FullClose::event()
{

}
