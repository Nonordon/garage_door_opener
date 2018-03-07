/*
 * Opening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Opening.h"
#include "Output.h"
#include "GarageDoorController.h"
#include <unistd.h>

bool Opening::exited = false;

Opening::Opening(){
	// TODO Auto-generated constructor stub
}

Opening::~Opening() {
	// TODO Auto-generated destructor stub
}

void Opening::entry()
{
	Output::setMotorUp();
	Opening::exited = false;
	//Opening::reaction();
}
void Opening::exit()
{
	Opening::exited = true;
	Output::setMotorOff();
}

void* openingReactionThread(void* GDC)
{
	while (((GarageDoorController*) GDC)->position < 10){
		sleep(1);
		if (Opening::exited)
		{
			pthread_exit(NULL);
		}
		((GarageDoorController*) GDC)->position = (((GarageDoorController*) GDC)->position + 1);
	}
	pthread_exit(NULL);
}

void Opening::reaction(void* GDC)
{
    // Increment position once per second (until position == 10)
	if (Output::simulation)
	{
		pthread_create(&timer, NULL, openingReactionThread, GDC);
	}
}
