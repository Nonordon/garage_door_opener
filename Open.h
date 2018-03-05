/*
 * Open.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef OPEN_H_
#define OPEN_H_
#include "State.h"

class Open: public State {
public:
	Open(void* inOutput);
	virtual ~Open();
	void entry();
};

#endif /* OPEN_H_ */
