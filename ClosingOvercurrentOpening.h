/*
 * ClosingOvercurrentOpening.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef CLOSINGOVERCURRENTOPENING_H_
#define CLOSINGOVERCURRENTOPENING_H_
#include "Transition.h"

class ClosingOvercurrentOpening: public Transition {
public:
	ClosingOvercurrentOpening();
	virtual ~ClosingOvercurrentOpening();
	bool accept();
};

#endif /* CLOSINGOVERCURRENTOPENING_H_ */
