/*
 * PushButton.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include "Transition.h"
#include "StateTable.h"

class PushButton: public Transition {
public:
	PushButton(std::queue<char>* inQueue);
	virtual ~PushButton();
	bool accept(char* ev);
	void event();
};


#endif /* PUSHBUTTON_H_ */
