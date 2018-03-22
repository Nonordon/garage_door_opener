/*
 * Closing.cpp
 *
 *  Created on: Feb 25, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#include "Closing.h"
#include "Output.h"
#include "GarageDoorController.h"
#include <unistd.h>

bool Closing::exited = false;

Closing::Closing(){
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
}

void Closing::exit()
{
    // Turn OFF Beam
	Closing::exited = true;
	Output::setMotorOff();
	Output::turnOffBeam();
}

void *closingReactionThread(void* GDC)
{
    // Decrement position once per second (until position == 0)
	while (((GarageDoorController*) GDC)->position > 0){
		sleep(1);
		if (Closing::exited)
		{
			pthread_exit(NULL);
		}
		((GarageDoorController*) GDC)->position = (((GarageDoorController*) GDC)->position - 1);
	}
	pthread_exit(NULL);
}


void Closing::reaction(void* GDC)
{
    // Decrement position once per second (until position == 0)
	if (Output::simulation)
	{
		pthread_create(&timer, NULL, closingReactionThread, GDC);
	}
}
