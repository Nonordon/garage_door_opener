/*
 * OpeningFullopenOpen.h
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#ifndef OPENINGFULLOPENOPEN_H_
#define OPENINGFULLOPENOPEN_H_
#include "Transition.h"
#include "GarageDoorController.h"

class OpeningFullopenOpen: public Transition {
public:
	OpeningFullopenOpen(std::queue<char>* inQueue);
	virtual ~OpeningFullopenOpen();
	bool accept(char* ev);
	bool guard(void* GDC);
};

#endif /* OPENINGFULLOPENOPEN_H_ */
