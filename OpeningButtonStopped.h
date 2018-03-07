/*
 * OpeningButtonStopped.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef OPENINGBUTTONSTOPPED_H_
#define OPENINGBUTTONSTOPPED_H_
#include "Transition.h"

class OpeningButtonStopped: public Transition {
public:
	OpeningButtonStopped(std::queue<char>* inQueue);
	virtual ~OpeningButtonStopped();
	bool accept(char* ev);
	void event(void* GDC);
};

#endif /* OPENINGBUTTONSTOPPED_H_ */
