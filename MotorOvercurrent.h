/*
 * MotorOvercurrent.h
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#ifndef MOTOROVERCURRENT_H_
#define MOTOROVERCURRENT_H_
#include "Transition.h"

class MotorOvercurrent: public Transition {
public:
	MotorOvercurrent(std::queue<char>* inQueue);
	virtual ~MotorOvercurrent();
	bool accept(char* ev);
	void event();
};

#endif /* MOTOROVERCURRENT_H_ */
