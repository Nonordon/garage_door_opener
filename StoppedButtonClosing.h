/*
 * StoppedButtonClosing.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef STOPPEDBUTTONCLOSING_H_
#define STOPPEDBUTTONCLOSING_H_
#include "Transition.h"

class StoppedButtonClosing: public Transition {
public:
	StoppedButtonClosing();
	virtual ~StoppedButtonClosing();
	bool guard();
	bool accept();
};

#endif /* STOPPEDBUTTONCLOSING_H_ */
