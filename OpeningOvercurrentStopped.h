/*
 * OpeningOvercurrentStopped.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef OPENINGOVERCURRENTSTOPPED_H_
#define OPENINGOVERCURRENTSTOPPED_H_
#include "Transition.h"

class OpeningOvercurrentStopped: public Transition {
public:
	OpeningOvercurrentStopped();
	virtual ~OpeningOvercurrentStopped();
	bool accept();
	void event();
};

#endif /* OPENINGOVERCURRENTSTOPPED_H_ */
