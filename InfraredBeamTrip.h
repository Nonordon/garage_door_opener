/*
 * InfraredBeamTrip.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#ifndef INFRAREDBEAMTRIP_H_
#define INFRAREDBEAMTRIP_H_
#include "Transition.h"
#include "StateTable.h"

class InfraredBeamTrip: public Transition {
public:
	InfraredBeamTrip(std::queue<char>* inQueue);
	virtual ~InfraredBeamTrip();
	bool accept(char* ev);
	void event();
};

#endif /* INFRAREDBEAMTRIP_H_ */
