/*
 * ClosingFullclosedClosed.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef CLOSINGFULLCLOSEDCLOSED_H_
#define CLOSINGFULLCLOSEDCLOSED_H_
#include "Transition.h"

class ClosingFullclosedClosed: public Transition {
public:
	ClosingFullclosedClosed();
	virtual ~ClosingFullclosedClosed();
	bool guard();
};

#endif /* CLOSINGFULLCLOSEDCLOSED_H_ */
