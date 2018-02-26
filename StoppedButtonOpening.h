/*
 * StoppedButtonOpening.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef STOPPEDBUTTONOPENING_H_
#define STOPPEDBUTTONOPENING_H_
#include "Transition.h"

class StoppedButtonOpening: public Transition {
public:
	StoppedButtonOpening();
	virtual ~StoppedButtonOpening();
	bool guard();
	bool accept();
};

#endif /* STOPPEDBUTTONOPENING_H_ */
