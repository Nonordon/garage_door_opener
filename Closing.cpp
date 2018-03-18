/*
 * Closing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include <unistd.h>
#include "Closing.h"
#include "Output.h"
#include <iostream>

bool Closing::exited = false;

Closing::Closing(Output* inOutput) : State(inOutput){
	// TODO Auto-generated constructor stub
}

Closing::~Closing() {
	// TODO Auto-generated destructor stub
}

void Closing::entry()
{
    // Turn ON Beam
	output->turnOnBeam();
	output->setMotorDown();
	//Closing::reaction();
	Closing::exited = false;
}

void Closing::exit()
{
    // Turn OFF Beam
	Closing::exited = true;
	output->turnOffBeam();
}

void *closingReactionThread(void* GDC)
{
    // Decrement position once per second (until position == 0)
	//GarageDoorController::position = (GarageDoorController::position - 1);
	//GarageDoorController* localGDC = (GarageDoorController*) GDC;
	while (((GarageDoorController*) GDC)->position > 0){
		sleep(1);
		if (Closing::exited)
		{
			pthread_exit(NULL);
		}
		((GarageDoorController*) GDC)->position = (((GarageDoorController*) GDC)->position - 1);
		//std::cout << "Closing: " << ((GarageDoorController*) GDC)->position << std::endl;
	}
	pthread_exit(NULL);
}


void Closing::reaction(void* GDC)
{
    // Decrement position once per second (until position == 0)
	//GarageDoorController::position = (GarageDoorController::position - 1);
	pthread_create(&timer, NULL, closingReactionThread, GDC);
}
