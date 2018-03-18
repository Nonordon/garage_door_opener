/*
 * FullClose.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#ifndef FULLCLOSE_H_
#define FULLCLOSE_H_
#include "Transition.h"
#include "StateTable.h"

class FullClose: public Transition {
public:
	FullClose(std::queue<char>* inQueue);
	virtual ~FullClose();
	bool accept(char* ev);
	void event();
};

#endif /* FULLCLOSE_H_ */
