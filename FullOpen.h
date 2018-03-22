/*
 * FullOpen.h
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#ifndef FULLOPEN_H_
#define FULLOPEN_H_
#include "Transition.h"

class FullOpen: public Transition {
public:
	FullOpen(std::queue<char>* inQueue);
	virtual ~FullOpen();
	bool accept(char* ev);
	void event();
};

#endif /* FULLOPEN_H_ */
