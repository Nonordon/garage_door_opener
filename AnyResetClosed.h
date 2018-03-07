/*
 * AnyResetClosed.h
 *
 *  Created on: Mar 5, 2018
 *      Author: Nonordon
 */

#ifndef ANYRESETCLOSED_H_
#define ANYRESETCLOSED_H_
#include "Transition.h"

class AnyResetClosed: public Transition  {
public:
	AnyResetClosed(std::queue<char>* inQueue);
	virtual ~AnyResetClosed();
	bool accept(char* ev);
	void event(void* GDC);
};

#endif /* ANYRESETCLOSED_H_ */
