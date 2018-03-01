/*
 * ClosingFullclosedClosed.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef CLOSINGFULLCLOSEDCLOSED_H_
#define CLOSINGFULLCLOSEDCLOSED_H_
#include "Transition.h"
#include "GarageDoorController.h"

class ClosingFullclosedClosed: public Transition {
public:
	ClosingFullclosedClosed(std::queue<char>* inQueue);
	virtual ~ClosingFullclosedClosed();
	bool guard(GarageDoorController* GDC);
};

#endif /* CLOSINGFULLCLOSEDCLOSED_H_ */
