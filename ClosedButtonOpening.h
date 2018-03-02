/*
 * ClosedButtonOpening.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef CLOSEDBUTTONOPENING_H_
#define CLOSEDBUTTONOPENING_H_
#include "Transition.h"

class ClosedButtonOpening: public Transition {
public:
	ClosedButtonOpening(std::queue<char>* inQueue);
	virtual ~ClosedButtonOpening();
	bool accept(char* ev);
	std::queue<char>* ioqueue;

};

#endif /* CLOSEDBUTTONOPENING_H_ */
