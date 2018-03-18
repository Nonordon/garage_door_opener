/*
 * ClosingOvercurrentOpening.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#ifndef CLOSINGOVERCURRENTOPENING_H_
#define CLOSINGOVERCURRENTOPENING_H_
#include "Transition.h"

class ClosingOvercurrentOpening: public Transition {
public:
	ClosingOvercurrentOpening(std::queue<char>* inQueue);
	virtual ~ClosingOvercurrentOpening();
	bool accept(char* ev);
};

#endif /* CLOSINGOVERCURRENTOPENING_H_ */
