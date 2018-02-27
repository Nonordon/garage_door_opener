/*
 * OpeningButtonStopped.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef OPENINGBUTTONSTOPPED_H_
#define OPENINGBUTTONSTOPPED_H_
#include "Transition.h"

class OpeningButtonStopped: public Transition {
public:
	OpeningButtonStopped();
	virtual ~OpeningButtonStopped();
	bool accept();
	void event();
};

#endif /* OPENINGBUTTONSTOPPED_H_ */
