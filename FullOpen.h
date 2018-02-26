/*
 * FullOpen.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#ifndef FULLOPEN_H_
#define FULLOPEN_H_
#include "Input.h"

class FullOpen: public Input {
public:
	FullOpen();
	virtual ~FullOpen();
	bool getEvent(unsigned char* event);
};

#endif /* FULLOPEN_H_ */
