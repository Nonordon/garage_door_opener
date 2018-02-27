/*
 * PushButton.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include "Input.h"

class PushButton: public Input {
public:
	PushButton();
	virtual ~PushButton();
	bool getEvent(unsigned char* event);
};

#endif /* PUSHBUTTON_H_ */
