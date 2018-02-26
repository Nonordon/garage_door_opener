/*
 * InfraredBeamTrip.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#include "InfraredBeamTrip.h"

InfraredBeamTrip::InfraredBeamTrip() {
	// TODO Auto-generated constructor stub

}

InfraredBeamTrip::~InfraredBeamTrip() {
	// TODO Auto-generated destructor stub
}

bool InfraredBeamTrip::getEvent(unsigned char* event)
{
	if (*event == 'i')
	{
		return true;
	} else
	{
		return false;
	}
}
