/*
 * StoppedButtonOpening.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef STOPPEDBUTTONOPENING_H_
#define STOPPEDBUTTONOPENING_H_
#include "Transition.h"
#include "GarageDoorController.h"

class StoppedButtonOpening: public Transition {
public:
	StoppedButtonOpening(std::queue<char>* inQueue);
	virtual ~StoppedButtonOpening();
	bool guard(GarageDoorController* GDC);
	bool accept(char* ev);
};

#endif /* STOPPEDBUTTONOPENING_H_ */
