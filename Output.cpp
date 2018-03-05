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

bool Output::simulation = false;

Output::Output() {
    // TODO Auto-generated constructor stub
	motorUp = false;
	motorDown = false;
	beamOn = false;
	if (!Output::simulation)
	{
		//QNX I/O
		if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
		{
			throw ("Failed to get I/O access permission");
		}
		ctrReg = mmap_device_io(1,DIOCTRL);
		if (ctrReg == MAP_DEVICE_FAILED)
		{
			throw ("Failed to map control register");
		}
		Output::portA = mmap_device_io(1,DIOA);
		if (ctrReg == MAP_DEVICE_FAILED)
		{
			throw ("Failed to map I/O A register");
		}
		Output::portB = mmap_device_io(1,DIOB);
		if (ctrReg == MAP_DEVICE_FAILED)
		{
			throw ("Failed to map I/O B register");
		}
		Output::portC = mmap_device_io(1,DIOC);
		if (ctrReg == MAP_DEVICE_FAILED)
		{
			throw ("Failed to map I/O C register");
		}
		out8(ctrReg,INITCTRL); //10010001
		reset();
	}
}

Output::~Output() {
    // TODO Auto-generated destructor stub
}

void Output::beamStatus()
{
	//if (Output::simulation)
	//{
		if (beamOn)
		{
			std::cout << "The beam is currently on." << std::endl;
		} else
		{
			std::cout << "The beam is currently off." << std::endl;
		}
	//} else
	//{
		if (beamOn)
		{
			BVal |= (1u << 4); //Setting pin 5 high
		} else
		{
			BVal &= ~(1u << 4); //Setting pin 5 low
		}
		out8(Output::portB, BVal);
	//}
}

void Output::motorStatus()
{
	//if (Output::simulation)
	//{
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
	//} else
	//{
		if ((motorUp) && !(motorDown))
		{
			BVal |= (1u << 2); //Setting pin 3 high
			BVal &= ~(1u << 3); //Setting pin 4 low
		} else if ((motorDown) && !(motorUp))
		{
			BVal &= ~(1u << 2); //Setting pin 3 low
			BVal |= (1u << 3); //Setting pin 4 high
		} else if (!(motorDown) && !(motorUp))
		{
			BVal &= ~(1u << 2); //Setting pin 3 low
			BVal &= ~(1u << 3); //Setting pin 4 low
		} else
		{
			BVal |= (1u << 2); //Setting pin 3 high
			BVal |= (1u << 3); //Setting pin 4 high
		}
		out8(Output::portB, BVal);
	//}
}
void Output::fullOpen()
{
	//if (Output::simulation)
	//{
		std::cout << "The door is completely open." << std::endl;
	//} else
	//{
		BVal |= (1u << 0); //Setting pin 1 high
		out8(Output::portA, BVal);
	//}
}
void Output::fullClose()
{
	//if (Output::simulation)
	//{
		std::cout << "The door is completely closed." << std::endl;
	//} else
	//{
		BVal |= (1u << 1); //Setting pin 2 high
		out8(Output::portB, BVal);
	//}
}
void Output::reset()
{
	AVal = INITA;
	BVal = INITB;
	CVal = INITC;
	out8(Output::portC, CVal);
	sleep(RESETTIME);
	CVal |= (1u << 4); //Setting pin 5 high
	out8(Output::portC, CVal);

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
int Output::readA()
{
	return in8(Output::portA);
}
int Output::readB()
{
	return in8(Output::portB);
}
int Output::readC()
{
	return in8(Output::portC);
}
