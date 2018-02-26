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

class GarageDoorController: public StateTable {
public:
	pthread_t GarageDoorControllerThreadID;
	static void* GarageDoorControllerThread(void* arg);
	GarageDoorController();
	virtual ~GarageDoorController();
	void thread();
	int direction;
	int position;
};

#endif /* GARAGEDOORCONTROLLER_H_ */
