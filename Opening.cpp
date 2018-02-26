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

Opening::Opening() {
	// TODO Auto-generated constructor stub

}

Opening::~Opening() {
	// TODO Auto-generated destructor stub
}

void Opening::entry()
{
	Output::setMotorUp();
	/*Timer t_position;
	t_position.start(std::chrono::milliseconds(1000), []{
		reaction();
		if (GarageDoorController::position == 10){
			t_position.stop();
		}
	});*/
	Opening::reaction();
}

void Opening::reaction()
{
    // Increment position once per second (until position == 10)
	GarageDoorController::position++;
	while (GarageDoorController::position < 10){
		sleep(1);
		GarageDoorController::position++;
	}
}
