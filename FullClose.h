/*
 * FullClose.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#ifndef FULLCLOSE_H_
#define FULLCLOSE_H_
#include "Input.h"
#include "Transition.h"
#include <queue>

class FullClose: public Transition {
public:
	FullClose();
	virtual ~FullClose();
	bool getEvent(unsigned char* event);
	bool accept(char* ev);
	void event();
};

#endif /* FULLCLOSE_H_ */
