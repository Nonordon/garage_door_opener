/*
 * InputScanner.cpp
 *
 *  Created on: Feb 22, 2018
*      Author: Emily Filmer, Zachary Campanella
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
#include "Output.h"

InputScanner::InputScanner(std::queue<char> *inQueue) {
    // TODO Auto-generated constructor stub
    currentState = 0;
	ioqueue = inQueue;

	Output* output = new Output();
    Idle* idle = new Idle(output);
    stateList.push_back(idle);   // 0

    std::vector<Transition*> transitions;
    FullClose* fc = new FullClose(inQueue);
    FullOpen* fo = new FullOpen(inQueue);
    InfraredBeamTrip* ir = new InfraredBeamTrip(inQueue);
    MotorOvercurrent* mo = new MotorOvercurrent(inQueue);
    PushButton* pb = new PushButton(inQueue);
    transitions.push_back(fc);
    transitions.push_back(fo);
    transitions.push_back(ir);
    transitions.push_back(mo);
    transitions.push_back(pb);
    transitionList.push_back(transitions);
}

void* InputScanner::InputScannerThread(void* arg) {
    char userInput = 'x';
    InputScanner IS = InputScanner((std::queue<char>*) arg);

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
    return 0;
}
