/*
 * Closing.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Closing.h"
#include <chrono>

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
	Timer t_position;
	t_position.start(std::chrono::milliseconds(1000), []{
		reaction();
		if (GarageDoorController::position == 0){
			t_position.stop();
		}
	});
}

void Closing::exit()
{
    // Turn OFF Beam
	Output::turnOffBeam();
}

void Closing::reaction()
{
    // Decrement position once per second (until position == 0)
	GarageDoorController::position--;
	/*while (GarageDoorController::position > 0){
		usleep(1000);
		GarageDoorController::position--;
	}*/
}
