/*
 * Closing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

//#include <chrono>
#include <unistd.h>
#include "Closing.h"
#include "Output.h"
#include "GarageDoorController.h"
#include <pthread.h>

Closing::Closing() {
	// TODO Auto-generated constructor stub

}

Closing::~Closing() {
	// TODO Auto-generated destructor stub
}

void Closing::entry()
{
    // Turn ON Beam
	output.turnOnBeam();
	output.setMotorDown();
	exited = false;
	p_thread timer;
	pthread_create(&timer, NULL, &reaction(), NULL);
	//Closing::reaction();
}

void Closing::exit()
{
    // Turn OFF Beam
	exited = true;
	output.turnOffBeam();
}

void Closing::reaction()
{
    // Decrement position once per second (until position == 0)
	//GarageDoorController::position = (GarageDoorController::position - 1);
	while (GarageDoorController::position > 0){
		sleep(1);
		if (exited)
		{
			exited = false;
			pthread_exit(NULL);
		}
		GarageDoorController::position = (GarageDoorController::position - 1);
	}
	pthread_exit(NULL);
}
