/*
 * InfraredBeamTrip.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#ifndef INFRAREDBEAMTRIP_H_
#define INFRAREDBEAMTRIP_H_
#include "Input.h"

class InfraredBeamTrip: public Input {
public:
	InfraredBeamTrip();
	virtual ~InfraredBeamTrip();
	bool getEvent(unsigned char* event);
};

#endif /* INFRAREDBEAMTRIP_H_ */
