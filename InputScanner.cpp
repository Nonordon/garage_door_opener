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

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

InputScanner::InputScanner(std::queue<char> *inQueue) {
    // TODO Auto-generated constructor stub
    currentState = 0;
	ioqueue = inQueue;

    Idle* idle = new Idle((void*)NULL);
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
    	int AVal;
    	std::string userInputString;
    	char userInput;
    	do {
    		AVal = Output::readA();
    		userInputString = IS.byteToString(AVal);
    		for (unsigned int i; i < userInputString.length(); i++)
    		{
    			userInput = userInputString[i];
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
    		}

    	} while (true);
    }
    return 0;
}

std::string InputScanner::byteToString(int byte)
{
	std::string returnString = "";
	if (CHECK_BIT(byte,0) == 1)
	{
		returnString += 'o';
	} else if (CHECK_BIT(byte,1) == 1)
	{
		returnString += 'c';
	} else if (CHECK_BIT(byte,2) == 1)
	{
		returnString += 'i';
	} else if (CHECK_BIT(byte,3) == 1)
	{
		returnString += 'm';
	} else if (CHECK_BIT(byte,4) == 1)
	{
		returnString += 'r';
	} else if (CHECK_BIT(byte,7) == 1)
	{
		returnString += 's';
	}
	return returnString;
}
