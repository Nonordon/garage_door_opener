/*
 * FullOpen.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#include "FullOpen.h"

FullOpen::FullOpen() {
	// TODO Auto-generated constructor stub

}

FullOpen::~FullOpen() {
	// TODO Auto-generated destructor stub
}

bool FullOpen::getEvent(unsigned char* event)
{
	if (*event == 'o')
	{
		return true;
	} else
	{
		return false;
	}
}
