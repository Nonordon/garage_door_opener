/*
 * Opening.h
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#ifndef OPENING_H_
#define OPENING_H_
#include "State.h"
#include <pthread.h>

class Opening: public State {
public:
	Opening();
	virtual ~Opening();
	void entry();
	void reaction(void* GDC);
	void exit();
	pthread_t timer;
	static bool exited;
};

#endif /* OPENING_H_ */
