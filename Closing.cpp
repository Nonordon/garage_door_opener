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

bool Closing::exited = false;

Closing::Closing() {
	// TODO Auto-generated constructor stub

}

Closing::~Closing() {
	// TODO Auto-generated destructor stub
}

void Closing::entry()
{
    // Turn ON Beam
	Output::turnOnBeam();
	Output::setMotorDown();
	Closing::exited = false;
	p_thread timer;
	pthread_create(&timer, NULL, &Closing::reaction(), NULL);
	//Closing::reaction();
}

void Closing::exit()
{
    // Turn OFF Beam
	Closing::exited = true;
	Output::turnOffBeam();
}

void Closing::reaction()
{
    // Decrement position once per second (until position == 0)
	//GarageDoorController::position = (GarageDoorController::position - 1);
	while (GarageDoorController::position > 0){
		sleep(1);
		if (Closing::exited)
		{
			Closing::exited = false;
			pthread_exit(NULL);
		}
		GarageDoorController::position = (GarageDoorController::position - 1);
	}
	pthread_exit(NULL);
}
