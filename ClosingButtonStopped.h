/*
 * ClosingButtonStopped.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef CLOSINGBUTTONSTOPPED_H_
#define CLOSINGBUTTONSTOPPED_H_
#include "Transition.h"
#include "GarageDoorController.h"

class ClosingButtonStopped: public Transition {
public:
	ClosingButtonStopped(std::queue<char>* inQueue);
	virtual ~ClosingButtonStopped();
	bool accept(char* ev);
	void event(GarageDoorController* GDC);
};

#endif /* CLOSINGBUTTONSTOPPED_H_ */
