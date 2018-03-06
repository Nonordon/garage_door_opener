/*
 * Opening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include <unistd.h>
#include "Opening.h"
#include "Output.h"

bool Opening::exited = false;

Opening::Opening(Output* inOutput) : State(inOutput){
	// TODO Auto-generated constructor stub
}

Opening::~Opening() {
	// TODO Auto-generated destructor stub
}

void Opening::entry()
{
	output->setMotorUp();
	std::cout << "MotorSet" << std::endl;
	Opening::exited = false;
	//Opening::reaction();
}
void Opening::exit()
{
	Opening::exited = true;
}

void* openingReactionThread(void* GDC)
{
	//GarageDoorController* localGDC = (GarageDoorController*)GDC;
	while (((GarageDoorController*) GDC)->position < 10){
		sleep(1);
		if (Opening::exited)
		{
			pthread_exit(NULL);
		}
		((GarageDoorController*) GDC)->position = (((GarageDoorController*) GDC)->position + 1);
		//std::cout << "Opening: " << ((GarageDoorController*) GDC)->position << std::endl;
	}
	pthread_exit(NULL);
}

void Opening::reaction(void* GDC)
{
    // Increment position once per second (until position == 10)
	//GDC->position = (GarageDoorController::position + 1);
	pthread_create(&timer, NULL, openingReactionThread, GDC);
}
