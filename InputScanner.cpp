/*
 * InputScanner.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: edf7470
 */

#include "InputScanner.h"
#include <iostream>
#include <ctype.h>
#include "FullClose.h"
#include "FullOpen.h"
#include "InfraredBeamTrip.h"
#include "MotorOvercurrent.h"
#include "PushButton.h"
#include "Idle.h"
#include "Reset.h"
#include <string>
#include <unistd.h>
#include <time.h>

#define CHECK_BIT(var,pos) !!((var) & (1<<(pos)))
#define BOUNCELIMIT 0.75

InputScanner::InputScanner(std::queue<char> *inQueue) {
    // TODO Auto-generated constructor stub
    currentState = 0;
	ioqueue = inQueue;

    Idle* idle = new Idle();
    stateList.push_back(idle);   // 0

    std::vector<Transition*> transitions;
    FullClose* fc = new FullClose(inQueue);
    FullOpen* fo = new FullOpen(inQueue);
    InfraredBeamTrip* ir = new InfraredBeamTrip(inQueue);
    MotorOvercurrent* mo = new MotorOvercurrent(inQueue);
    PushButton* pb = new PushButton(inQueue);
    Reset* rs = new Reset(inQueue);
    transitions.push_back(fc);
    transitions.push_back(fo);
    transitions.push_back(ir);
    transitions.push_back(mo);
    transitions.push_back(pb);
    transitions.push_back(rs);
    transitionList.push_back(transitions);
	clock_gettime(CLOCK_MONOTONIC, &openTimer);
	clock_gettime(CLOCK_MONOTONIC, &closeTimer);
	clock_gettime(CLOCK_MONOTONIC, &infraTimer);
	clock_gettime(CLOCK_MONOTONIC, &motorTimer);
	clock_gettime(CLOCK_MONOTONIC, &pushTimer);
}

void* InputScanner::InputScannerThread(void* arg) {
    InputScanner IS = InputScanner((std::queue<char>*) arg);

    if (Output::simulation)
    {
		char userInput = 'x';

		do{
			// print input directions on screen
			std::cout << "\nSignal Options:\n'm' - motor overcurrent detected \n'i' - infrared beam interruption \n'r' - remote button press\n";
			std::cout << "\nEnter signal choice: ";

			// get user's input
			std::cin >> userInput;
			//std::cout << "UserInput: " << userInput << std::endl;
			for (unsigned int trans = 0; trans < IS.transitionList[IS.currentState].size(); trans++)
			{
				//std::cout << GDC.currentState << std::endl;
				if (IS.transitionList[IS.currentState][trans]->guard((void*)NULL) && IS.transitionList[IS.currentState][trans]->accept(&userInput))
				{
					//std::cout << "Transition Taken on inputscanner" << std::endl;
					IS.stateList[IS.currentState]->exit();
					while (StateTable::QUEUEMUTEX)
					{
						//Hangs till it can access the queue.
					}
					StateTable::QUEUEMUTEX = true;
					IS.stateList[IS.currentState]->entry();
					IS.transitionList[IS.currentState][trans]->event();
					//std::cout << "Queue front: " << IS.ioqueue->front() << std::endl;
					StateTable::QUEUEMUTEX = false;
					IS.currentState = IS.transitionList[IS.currentState][trans]->nextState;
					IS.stateList[IS.currentState]->entry();
				}
			}

		}while (true); // Loop forever
    } else
    {
    	sleep(2);
    	//QNX I/O
		if (ThreadCtl(_NTO_TCTL_IO, NULL) == -1)
		{
			throw ("Failed to get I/O access permission");
		}
    	std::string userInputString;
    	char userInput;
    	int prevAVal = 0x0;
    	do {
    		Output::readA();
    		if (prevAVal != Output::AVal)
    		{
    			userInputString = IS.byteToString(Output::AVal);
    			prevAVal = Output::AVal;
    		}
    		else
    		{
    			userInputString = "";
    		}
    		for (unsigned int i = 0; i < userInputString.length(); i++)
    		{
    			userInput = userInputString[i];
    			//std::cout << userInput << std::endl;
    			for (unsigned int trans = 0; trans < IS.transitionList[IS.currentState].size(); trans++)
    			{
    				//std::cout << IS.currentState << std::endl;
    				if (IS.transitionList[IS.currentState][trans]->guard((void*)NULL) && IS.transitionList[IS.currentState][trans]->accept(&userInput))
    				{
    					//std::cout << "Transition Taken on inputscanner" << std::endl;
    					IS.stateList[IS.currentState]->exit();
    					while (StateTable::QUEUEMUTEX)
    					{
    						//Hangs till it can access the queue.
    					}
    					StateTable::QUEUEMUTEX = true;
    					IS.stateList[IS.currentState]->entry();
    					IS.transitionList[IS.currentState][trans]->event();
    					//std::cout << "Queue front: " << IS.ioqueue->front() << std::endl;
    					StateTable::QUEUEMUTEX = false;
    					IS.currentState = IS.transitionList[IS.currentState][trans]->nextState;
    					IS.stateList[IS.currentState]->entry();
    				}
    			}
    		}

    	} while (true);
    }
    return 0;
}

std::string InputScanner::byteToString(int byte)
{
	double elapsed;
	std::string returnString = "";
	clock_gettime(CLOCK_MONOTONIC, &tempTimer);
	if (CHECK_BIT(byte,0) == 1)
	{
		elapsed = (tempTimer.tv_sec - openTimer.tv_sec);
		elapsed += (tempTimer.tv_nsec - openTimer.tv_nsec) / 1000000000.0;
		if (elapsed >= BOUNCELIMIT)
		{
			returnString += 'o';
			clock_gettime(CLOCK_MONOTONIC, &openTimer);
		}
	}
	if (CHECK_BIT(byte,1) == 1)
	{
		elapsed = (tempTimer.tv_sec - closeTimer.tv_sec);
		elapsed += (tempTimer.tv_nsec - closeTimer.tv_nsec) / 1000000000.0;
		if (elapsed >= BOUNCELIMIT)
		{
			returnString += 'c';
			clock_gettime(CLOCK_MONOTONIC, &closeTimer);
		}
	}
	if (CHECK_BIT(byte,2) == 1)
	{
		elapsed = (tempTimer.tv_sec - infraTimer.tv_sec);
		elapsed += (tempTimer.tv_nsec - infraTimer.tv_nsec) / 1000000000.0;
		if (elapsed >= BOUNCELIMIT)
		{
			returnString += 'i';
			clock_gettime(CLOCK_MONOTONIC, &infraTimer);
		}
	}
	if (CHECK_BIT(byte,3) == 1)
	{
		elapsed = (tempTimer.tv_sec - motorTimer.tv_sec);
		elapsed += (tempTimer.tv_nsec - motorTimer.tv_nsec) / 1000000000.0;
		if (elapsed >= BOUNCELIMIT)
		{
			returnString += 'm';
			clock_gettime(CLOCK_MONOTONIC, &motorTimer);
		}
	}
	if (CHECK_BIT(byte,4) == 1)
	{
		elapsed = (tempTimer.tv_sec - pushTimer.tv_sec);
		elapsed += (tempTimer.tv_nsec - pushTimer.tv_nsec) / 1000000000.0;
		if (elapsed >= BOUNCELIMIT)
		{
			returnString += 'r';
			clock_gettime(CLOCK_MONOTONIC, &pushTimer);
		}
	}
	/*if (CHECK_BIT(byte,7) == 1)
	{
		returnString += 's';
	} *//*else
	{
		returnString += 'r';
	}*/
	//std::cout << "<" << returnString << ">" << std::endl;
	return returnString;
}
