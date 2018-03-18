/*
 * OpenButtonClosing.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#ifndef OPENBUTTONCLOSING_H_
#define OPENBUTTONCLOSING_H_
#include "Transition.h"

class OpenButtonClosing: public Transition {
public:
	OpenButtonClosing(std::queue<char>* inQueue);
	virtual ~OpenButtonClosing();
	bool accept(char* ev);
};

#endif /* OPENBUTTONCLOSING_H_ */
