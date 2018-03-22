/*
 * StoppedButtonOpening.h
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#ifndef STOPPEDBUTTONOPENING_H_
#define STOPPEDBUTTONOPENING_H_
#include "Transition.h"

class StoppedButtonOpening: public Transition {
public:
	StoppedButtonOpening(std::queue<char>* inQueue);
	virtual ~StoppedButtonOpening();
	bool guard(void* GDC);
	bool accept(char* ev);
};

#endif /* STOPPEDBUTTONOPENING_H_ */
