/*
 * MotorOvercurrent.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#ifndef MOTOROVERCURRENT_H_
#define MOTOROVERCURRENT_H_
#include "Input.h"

class MotorOvercurrent: public Input {
public:
	MotorOvercurrent();
	virtual ~MotorOvercurrent();
	bool getEvent(unsigned char* event);
};

#endif /* MOTOROVERCURRENT_H_ */
