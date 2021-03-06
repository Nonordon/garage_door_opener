/*
 * ClosedButtonOpening.h
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#ifndef CLOSEDBUTTONOPENING_H_
#define CLOSEDBUTTONOPENING_H_
#include "Transition.h"

class ClosedButtonOpening: public Transition {
public:
	ClosedButtonOpening(std::queue<char>* inQueue);
	virtual ~ClosedButtonOpening();
	bool accept(char* ev);

};

#endif /* CLOSEDBUTTONOPENING_H_ */
