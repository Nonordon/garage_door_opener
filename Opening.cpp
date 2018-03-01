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

Opening::Opening(Output* inOutput) {
	// TODO Auto-generated constructor stub
	output = *inOutput;
}

Opening::~Opening() {
	// TODO Auto-generated destructor stub
}

void Opening::entry()
{
	output.setMotorUp();
	//Opening::reaction();
}
void Opening::exit()
{
	pthread_cancel(timer);
}

void* openingReactionThread(void* GDC)
{
	GarageDoorController* localGDC = (GarageDoorController*)GDC;
	while (localGDC->position < 10){
		sleep(1);
		localGDC->position = (localGDC->position + 1);
	}
	pthread_exit(NULL);
}

void Opening::reaction(void* GDC)
{
    // Increment position once per second (until position == 10)
	//GDC->position = (GarageDoorController::position + 1);
	pthread_create(&timer, NULL, openingReactionThread, GDC);
}
