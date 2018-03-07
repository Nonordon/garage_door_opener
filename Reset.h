/*
 * Reset.h
 *
 *  Created on: Mar 5, 2018
 *      Author: Nonordon
 */

#ifndef RESET_H_
#define RESET_H_
#include "Transition.h"

class Reset: public Transition  {
public:
	Reset(std::queue<char>* inQueue);
	virtual ~Reset();
	bool accept(char* ev);
	void event();
};

#endif /* RESET_H_ */
