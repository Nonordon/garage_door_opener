/*
 * Opening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

//#include <chrono>
//#include <Timer>
#include <unistd.h>
#include "Opening.h"
#include "Output.h"
#include "GarageDoorController.h"
#include <pthread.h>

Opening::Opening() {
	// TODO Auto-generated constructor stub

}

Opening::~Opening() {
	// TODO Auto-generated destructor stub
}

void Opening::entry()
{
	output.setMotorUp();
	exited = false;
	p_thread timer;
	pthread_create(&timer, NULL, &reaction(), NULL);
	//Opening::reaction();
}
void Opening::exit()
{
	exited = true;
}

void Opening::reaction()
{
    // Increment position once per second (until position == 10)
	GarageDoorController::position = (GarageDoorController::position + 1);
	while (GarageDoorController::position < 10){
		sleep(1);
		if (exited)
		{
			exited = false;
			pthread_exit(NULL);
		}
		GarageDoorController::position = (GarageDoorController::position + 1);
	}
	pthread_exit(NULL);
}
