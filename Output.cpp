/*
 * Output.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#include "Output.h"

bool Output::motorUp = false;
bool Output::motorDown = false;
bool Output::beamOn = false;

Output::Output() {
    // TODO Auto-generated constructor stub
}

Output::~Output() {
    // TODO Auto-generated destructor stub
}

void Output::beamStatus()
{
    if (Output::beamOn)
    {
        std::cout << "The beam is currently on." << std::endl;
    } else
    {
    	std::cout << "The beam is currently off." << std::endl;
    }
}

void Output::motorStatus()
{
    if ((Output::motorUp) && !(Output::motorDown))
    {
    	std::cout << "The motor is moving up." << std::endl;
    } else if ((Output::motorDown) && !(Output::motorUp))
    {
    	std::cout << "The motor is moving down." << std::endl;
    } else if (!(Output::motorDown) && !(Output::motorUp))
    {
        std::cout << "The motor is off." << std::endl;
    } else
    {
    	std::cout << "Motor is currently set to move up and down." << std::endl;
    }
}
void Output::turnOnBeam()
{
	Output::beamOn = true;
	Output::beamStatus();
}
void Output::turnOffBeam()
{
	Output::beamOn = false;
	Output::beamStatus();
}
void Output::setMotorUp()
{
	Output::motorUp = true;
	Output::motorDown = false;
	Output::motorStatus();
}
void Output::setMotorDown()
{
	Output::motorUp = false;
	Output::motorDown = true;
	Output::motorStatus();
}
void Output::setMotorOff()
{
	Output::motorUp = false;
	Output::motorDown = false;
	Output::motorStatus();
}
void Output::fullOpen()
{
	std::cout << "The door has reached a full open position." << std::endl;
}
void Output::fullClose()
{
	std::cout << "The door has reached a full close position." << std::endl;
}

