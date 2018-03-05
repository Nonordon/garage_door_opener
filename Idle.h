/*
 * Idle.h
 *
 *  Created on: Feb 27, 2018
 *      Author: Nonordon
 */

#ifndef IDLE_H_
#define IDLE_H_
#include "State.h"

class Idle: public State {
public:
	Idle(void* inOutput);
	virtual ~Idle();
};

#endif /* IDLE_H_ */
