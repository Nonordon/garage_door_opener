/*
 * GarageDoorController.h
 *
 *  Created on: Feb 22, 2018
 *      Author: Nonordon
 */

#ifndef GARAGEDOORCONTROLLER_H_
#define GARAGEDOORCONTROLLER_H_

#include <pthread.h>
#include "StateTable.h"
#include "Output.h"

class GarageDoorController: public StateTable {
public:
	pthread_t GarageDoorControllerThreadID;
	static void *GarageDoorControllerThread(void* arg);
	GarageDoorController(std::queue<char>* inQueue);
	virtual ~GarageDoorController();
	int direction;
	int position;
	Output* output;
};

#endif /* GARAGEDOORCONTROLLER_H_ */
