/*
 * FullClose.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#ifndef FULLCLOSE_H_
#define FULLCLOSE_H_
#include "Input.h"

class FullClose: public Input {
public:
	FullClose();
	virtual ~FullClose();
	bool getEvent(unsigned char* event);
};

#endif /* FULLCLOSE_H_ */
