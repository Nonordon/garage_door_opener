/*
 * Output.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#include "Output.h"


Output::Output() {
    // TODO Auto-generated constructor stub
	motorUp = false;
	motorDown = false;
	beamOn = false;
}

Output::~Output() {
    // TODO Auto-generated destructor stub
}

void Output::beamStatus()
{
    if (beamOn)
    {
        std::cout << "The beam is currently on." << std::endl;
    } else
    {
    	std::cout << "The beam is currently off." << std::endl;
    }
}

void Output::motorStatus()
{
    if ((motorUp) && !(motorDown))
    {
    	std::cout << "The motor is moving up." << std::endl;
    } else if ((motorDown) && !(motorUp))
    {
    	std::cout << "The motor is moving down." << std::endl;
    } else if (!(motorDown) && !(motorUp))
    {
        std::cout << "The motor is not moving." << std::endl;
    } else
    {
    	std::cout << "Motor is currently set to move up and down." << std::endl;
    }
}
void Output::turnOnBeam()
{
	beamOn = true;
	beamStatus();
}
void Output::turnOffBeam()
{
	beamOn = false;
	beamStatus();
}
void Output::setMotorUp()
{
	motorUp = true;
	motorDown = false;
	motorStatus();
}
void Output::setMotorDown()
{
	motorUp = false;
	motorDown = true;
	motorStatus();
}
void Output::setMotorOff()
{
	motorUp = false;
	motorDown = false;
	motorStatus();
}
void Output::fullOpen()
{
	std::cout << "The door is completely open." << std::endl;
}
void Output::fullClose()
{
	std::cout << "The door is completely closed." << std::endl;
}
