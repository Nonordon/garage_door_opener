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

Closing::Closing(Output* inOutput) {
	// TODO Auto-generated constructor stub
	output = *inOutput;
}

Closing::~Closing() {
	// TODO Auto-generated destructor stub
}

void Closing::entry()
{
    // Turn ON Beam
	output.turnOnBeam();
	output.setMotorDown();
	//Closing::reaction();
}

void Closing::exit()
{
    // Turn OFF Beam
	output.turnOffBeam();
	pthread_cancel(timer);
}

void *closingReactionThread(void* GDC)
{
    // Decrement position once per second (until position == 0)
	//GarageDoorController::position = (GarageDoorController::position - 1);
	GarageDoorController* localGDC = (GarageDoorController*) GDC;
	while (localGDC->position > 0){
		sleep(1);
		localGDC->position = (localGDC->position - 1);
	}
	pthread_exit(NULL);
}


void Closing::reaction(void* GDC)
{
    // Decrement position once per second (until position == 0)
	//GarageDoorController::position = (GarageDoorController::position - 1);
	pthread_create(&timer, NULL, closingReactionThread, GDC);
}
