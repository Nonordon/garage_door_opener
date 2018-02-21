/*
 * Output.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#include "Output.h"

Output::Output() {
    // TODO Auto-generated constructor stub
    Output::motorUp = false;
    Output::motorDown = false;
    Output::beamOn = false;
}

Output::~Output() {
    // TODO Auto-generated destructor stub
}

void Output::motorStatus()
{
    if (Output::beamOn)
    {
        cout << "The beam is currently on." << endl;
    } else
    {
        cout << "The beam is currently on." << endl;
    }
}

void Output::beamStatus()
{
    if ((Output::motorUp) && !(Output::motorDown))
    {
        cout << "The motor is moving up." << endl;
    } else if ((Output::motorDown) && !(Output::motorUp))
    {
        cout << "The motor is moving down." << endl;
    } else
    {
        cout << "Motor is currently set to move up and down." << endl;
    }
}
void turnOnBeam()
{
	Output::beamOn = true;
	Output::beamStatus();
}
void turnOffBeam()
{
	Output::beamOn = false;
	Output::beamStatus();
}
void setMotorUp()
{
	Output::motorUp = true;
	Output::motorDown = false;
	Output::motorStatus();
}
void setMotorDown()
{
	Output::motorUp = false;
	Output::motorDown = true;
	Output::motorStatus();
}

