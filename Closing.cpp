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
	/*Timer t_position;
	t_position.start(std::chrono::milliseconds(1000), []{
		reaction();
		if (GarageDoorController::position == 0){
			t_position.stop();
		}
	});*/
	Closing::reaction();
}

void Closing::exit()
{
    // Turn OFF Beam
	Output::turnOffBeam();
}

void Closing::reaction()
{
    // Decrement position once per second (until position == 0)
	GarageDoorController::position = (GarageDoorController::position - 1);
	while (GarageDoorController::position > 0){
		sleep(1000);
		GarageDoorController::position = (GarageDoorController::position - 1);
	}
}
