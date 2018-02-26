/*
 * Opening.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: filme
 */

#include "Opening.h"
#include <chrono>

Opening::Opening() {
	// TODO Auto-generated constructor stub

}

Opening::~Opening() {
	// TODO Auto-generated destructor stub
}

void Opening::entry()
{
	Timer t_position;
	t_position.start(std::chrono::milliseconds(1000), []{
		reaction();
		if (GarageDoorController::position == 10){
			t_position.stop();
		}
	});
}

void Opening::reaction()
{
    // Increment position once per second (until position == 10)
	GarageDoorController::position++;
	/*(while (GarageDoorController::position < 10){
		usleep(1000);
		GarageDoorController::position++;
	}*/
}
