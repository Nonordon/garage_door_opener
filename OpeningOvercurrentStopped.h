/*
 * OpeningOvercurrentStopped.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef OPENINGOVERCURRENTSTOPPED_H_
#define OPENINGOVERCURRENTSTOPPED_H_
#include "Transition.h"
#include "GarageDoorController.h"

class OpeningOvercurrentStopped: public Transition {
public:
	OpeningOvercurrentStopped(std::queue<char>* inQueue);
	virtual ~OpeningOvercurrentStopped();
	bool accept(char* ev);
	void event(GarageDoorController* GDC);
};

#endif /* OPENINGOVERCURRENTSTOPPED_H_ */
