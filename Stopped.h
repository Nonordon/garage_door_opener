/*
 * Stopped.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#ifndef STOPPED_H_
#define STOPPED_H_
#include "State.h"

class Stopped: public State {
public:
	Stopped(Output* inOutput);
	virtual ~Stopped();
	void entry();
};

#endif /* STOPPED_H_ */
