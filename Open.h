/*
 * Open.h
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#ifndef OPEN_H_
#define OPEN_H_
#include "State.h"

class Open: public State {
public:
	Open();
	virtual ~Open();
	void entry();
};

#endif /* OPEN_H_ */
