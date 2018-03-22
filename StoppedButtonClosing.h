/*
 * StoppedButtonClosing.h
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#ifndef STOPPEDBUTTONCLOSING_H_
#define STOPPEDBUTTONCLOSING_H_
#include "Transition.h"

class StoppedButtonClosing: public Transition {
public:
	StoppedButtonClosing(std::queue<char>* inQueue);
	virtual ~StoppedButtonClosing();
	bool guard(void* GDC);
	bool accept(char* ev);
};

#endif /* STOPPEDBUTTONCLOSING_H_ */
