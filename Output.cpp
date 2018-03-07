/*
 * Output.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#include "Output.h"
#include <unistd.h>

//http://www.se.rit.edu/~rtembed/LabInfo/DiamondSystems/Athena%20-%20Manual%201.40.pdf 		pg 47
#define DIOA 0x288		//IN
#define DIOB 0x289		//OUT
#define DIOC 0x28A		//7-4 OUT	3-0 IN
#define DIOCTRL 0x28B
#define INITA 0x0
#define INITB 0x0
#define INITC 0x0
#define INITCTRL 0x91
#define RESETTIME 1

uintptr_t Output::portA = DIOA;
uintptr_t Output::portB = DIOB;
uintptr_t Output::portC = DIOC;
bool Output::motorUp = false;
bool Output::motorDown = false;
bool Output::beamOn = false;

bool Output::simulation = false;

uintptr_t Output::ctrReg = DIOCTRL;

int Output::AVal = INITA;
int Output::BVal = INITB;
int Output::CVal = INITC;

Output::Output() {
    // TODO Auto-generated constructor stub
}

Output::~Output() {
    // TODO Auto-generated destructor stub
}

void Output::init()
{
	Output::motorUp = false;
	Output::motorDown = false;
	Output::beamOn = false;
	if (!Output::simulation)
	{
		//QNX I/O
		if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
		{
			throw ("Failed to get I/O access permission");
		}
		Output::ctrReg = mmap_device_io(1,DIOCTRL);
		if (Output::ctrReg == MAP_DEVICE_FAILED)
		{
			throw ("Failed to map control register");
		}
		Output::portA = mmap_device_io(1,DIOA);
		if (Output::portA == MAP_DEVICE_FAILED)
		{
			throw ("Failed to map I/O A register");
		}
		Output::portB = mmap_device_io(1,DIOB);
		if (Output::portB == MAP_DEVICE_FAILED)
		{
			throw ("Failed to map I/O B register");
		}
		Output::portC = mmap_device_io(1,DIOC);
		if (Output::portC == MAP_DEVICE_FAILED)
		{
			throw ("Failed to map I/O C register");
		}
		out8(Output::ctrReg,INITCTRL); //10010001
		Output::reset();
	}
}

void Output::beamStatus()
{
	if (Output::simulation)
	{
		if (Output::beamOn)
		{
			std::cout << "The beam is currently on." << std::endl;
		} else
		{
			std::cout << "The beam is currently off." << std::endl;
		}
	} else
	{
		if (Output::beamOn)
		{
			Output::BVal |= (1u << 2); //Setting pin 11 high
		} else
		{
			Output::BVal &= ~(1u << 2); //Setting pin 11 low
		}
		out8(Output::Output::portB, Output::BVal);
	}
}

void Output::motorStatus()
{
	if (Output::simulation)
	{
		if ((Output::motorUp) && !(Output::motorDown))
		{
			std::cout << "The motor is moving up." << std::endl;
		} else if ((Output::motorDown) && !(Output::motorUp))
		{
			std::cout << "The motor is moving down." << std::endl;
		} else if (!(Output::motorDown) && !(Output::motorUp))
		{
			std::cout << "The motor is not moving." << std::endl;
		} else
		{
			std::cout << "Motor is currently set to move up and down." << std::endl;
		}
	} else
	{
		if ((Output::motorUp) && !(Output::motorDown))
		{
			Output::BVal |= (1u << 0); //Setting pin 9 high
			Output::BVal &= ~(1u << 1); //Setting pin 10 low
		} else if ((Output::motorDown) && !(motorUp))
		{
			Output::BVal &= ~(1u << 0); //Setting pin 9 low
			Output::BVal |= (1u << 1); //Setting pin 10 high
		} else if (!(Output::motorDown) && !(Output::motorUp))
		{
			Output::BVal &= ~(1u << 0); //Setting pin 9 low
			Output::BVal &= ~(1u << 1); //Setting pin 10 low
		} else
		{
			Output::BVal |= (1u << 0); //Setting pin 9 high
			Output::BVal |= (1u << 1); //Setting pin 10 high
		}
		out8(Output::portB, Output::BVal);
		//std::cout << "BVal:" << BVal << std::endl;
	}
}
void Output::fullOpen()
{
	if (Output::simulation)
	{
		std::cout << "The door is completely open." << std::endl;
	} else
	{
		Output::setMotorOff();
		//Output::BVal |= (1u << 0); //Setting pin 1 high
		//out8(Output::portA, Output::BVal);
	}
}
void Output::fullClose()
{
	if (Output::simulation)
	{
		std::cout << "The door is completely closed." << std::endl;
	} else
	{
		Output::setMotorOff();
		Output::turnOffBeam();
		//Output::BVal |= (1u << 1); //Setting pin 2 high
		//out8(Output::portB, Output::BVal);
	}
}
void Output::reset()
{
	if (Output::simulation)
	{
		std::cout << "Resetting System" << std::endl; // This won't do anything in a simulation without passing GDC to entry on closed, and changing pos/dir from there
	} else
	{
		Output::AVal = INITA;
		Output::BVal = INITB;
		Output::CVal = INITC;
		//out8(Output::portC, Output::CVal);
		out8(Output::portB, Output::BVal);
		sleep(RESETTIME);
		//Output::CVal |= (1u << 4); //Setting pin 5 high
		Output::BVal |= (1u << 7); //Setting pin 5 high
		//out8(Output::portC, Output::CVal);
		out8(Output::portB, Output::BVal);
	}
}
void Output::turnOnBeam()
{
	Output::beamOn = true;
	beamStatus();
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
void Output::readA()
{
	Output::AVal = in8(Output::portA);
}
void Output::readB()
{
	Output::BVal = in8(Output::portB);
}
void Output::readC()
{
	Output::CVal = in8(Output::portC);
}
