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
#include "InputScanner.h"

bool Opening::exited = false;

Opening::Opening() {
	// TODO Auto-generated constructor stub

}

Opening::~Opening() {
	// TODO Auto-generated destructor stub
}

void Opening::entry()
{
	Output::setMotorUp();
	Opening::exited = false;
	//p_thread timer;
	//pthread_create(&timer, NULL, &Opening::reaction(), NULL);
	Opening::reaction();
}
void Opening::exit()
{
	Opening::exited = true;
}

void Opening::reaction()
{
    // Increment position once per second (until position == 10)
	//GarageDoorController::position = (GarageDoorController::position + 1);
	while (GarageDoorController::position < 10){
		sleep(1);
		if (InputScanner::OVERCURRENT || InputScanner::BUTTON)
		{
			break;
		}
		//if (Opening::exited)
		//{
			//Opening::exited = false;
			//pthread_exit(NULL);
		//}
		GarageDoorController::position = (GarageDoorController::position + 1);
	}
	Output::setMotorOff();
	//pthread_exit(NULL);
}
