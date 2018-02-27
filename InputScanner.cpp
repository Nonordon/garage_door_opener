/*
 * InputScanner.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: edf7470
 */

#include "InputScanner.h"
#include "Global.h"
#include <iostream>
#include <ctype.h>
#include "Input.h"
#include "FullClose.h"
#include "FullOpen.h"
#include "InfraredBeamTrip.h"
#include "MotorOvercurrent.h"
#include "PushButton.h"
#include "Idle.h"

bool InputScanner::MUTEX = false;

bool InputScanner::OVERCURRENT = false;
bool InputScanner::IRBEAMTRIP = false;
bool InputScanner::BUTTON = false;
bool InputScanner::FULLOPEN = false;
bool InputScanner::FULLCLOSED = false;

InputScanner::InputScanner(std::queue<char> *inQueue) {
    // TODO Auto-generated constructor stub
    currentState = 0;
	ioqueue = inQueue;

    Idle* idle = new Idle();
    stateList.push_back(idle);   // 0

    std::vector<Transition*> transitions;
    FullClose* fc = new FullClose();
    FullOpen* fo = new FullOpen();
    InfraredBeamTrip* ir = new InfraredBeamTrip();
    MotorOvercurrent* mo = new MotorOvercurrent();
    PushButton* pb = new PushButton();
    transitions.push_back(fc);
    transitions.push_back(fo);
    transitions.push_back(ir);
    transitions.push_back(mo);
    transitions.push_back(pb);
    transitionList.push_back(transitions);
}

void* InputScanner::InputScannerThread(void* arg) {
    unsigned char userInput = 'x';
    InputScanner IS = InputScanner((std::queue<char>*) arg);

    do{
    	// print input directions on screen
        std::cout << "\nSignal Options:\n'm' - motor overcurrent detected \n'i' - infrared beam interruption \n'r' - remote button press\n";
        std::cout << "\nEnter signal choice: ";

        // get user's input
        std::cin >> userInput;
        for (unsigned int trans = 0; trans < IS.transitionList[IS.currentState].size(); trans++)
    	{
    		//std::cout << GDC.currentState << std::endl;
    		if (IS.transitionList[IS.currentState][trans]->guard() && IS.transitionList[IS.currentState][trans]->accept())
    		{
    			IS.transitionList[IS.currentState][trans]->event();
    			IS.currentState = IS.transitionList[IS.currentState][trans]->nextState;
    			IS.stateList[IS.currentState]->entry();
    		}
    	}
        if(InputScanner::MUTEX == false)
        {
           	// Set MUTEX to True to lock the shared resources temporarily
        	InputScanner::MUTEX = true;
			//std::cout << "IN: <" << userInput << ">" << std::endl;

			InputScanner::FULLCLOSED = IS.inputs[0]->getEvent(&userInput);
			InputScanner::FULLOPEN = IS.inputs[1]->getEvent(&userInput);
			InputScanner::IRBEAMTRIP = IS.inputs[2]->getEvent(&userInput);
			InputScanner::OVERCURRENT = IS.inputs[3]->getEvent(&userInput);
			InputScanner::BUTTON = IS.inputs[4]->getEvent(&userInput);

			// Set MUTEX to False to release our lock on the shared resources
			InputScanner::MUTEX = false;
        }
        /*
        switch(tolower(userInput)){
            // 'm' - motor overcurrent detected
            case 'm':
            	((InputScanner*)arg)->signalMotorOvercurrent();
            	break;

            // 'i' - infrared beam interruption
            case 'i':
            	((InputScanner*)arg)->signalInfraredBeamTrip();
            	break;

            // 'r' - remote button press
            case 'r':
            	((InputScanner*)arg)->signalPushButton();
                break;

            default:
            	std::cout << "\nInvalid input.";

        }
         */
    }while (true); // Loop forever
    return 0;
}

void InputScanner::signalMotorOvercurrent() {
	// Check that no one else is accessing the shared (global) variables
    if(InputScanner::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	InputScanner::MUTEX = true;
        // If no other signal flag is set, set OVERCURRENT signal flag True
        if((InputScanner::OVERCURRENT == false) && (InputScanner::IRBEAMTRIP == false) && (InputScanner::BUTTON == false) && (InputScanner::FULLOPEN == false) && (InputScanner::FULLCLOSED == false)){
        	InputScanner::OVERCURRENT = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        InputScanner::MUTEX = false;
    }
}

void InputScanner::signalInfraredBeamTrip() {
	// Check that no one else is accessing the shared (global) variables
    if(InputScanner::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	InputScanner::MUTEX = true;
        // If no other signal flag is set, set IRBEAMTRIP signal flag True
        if(InputScanner::OVERCURRENT == false && InputScanner::IRBEAMTRIP == false && InputScanner::BUTTON == false && InputScanner::FULLOPEN == false && InputScanner::FULLCLOSED == false){
        	InputScanner::IRBEAMTRIP = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        InputScanner::MUTEX = false;
    }
}

void InputScanner::signalPushButton() {
	// Check that no one else is accessing the shared (global) variables
    if(InputScanner::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	InputScanner::MUTEX = true;
        // If no other signal flag is set, set BUTTON signal flag True
        if(InputScanner::OVERCURRENT == false && InputScanner::IRBEAMTRIP == false && InputScanner::BUTTON == false && InputScanner::FULLOPEN == false && InputScanner::FULLCLOSED == false){
        	InputScanner::BUTTON = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        InputScanner::MUTEX = false;
    }
}

void InputScanner::signalFullOpen() {
	// Check that no one else is accessing the shared (global) variables
    if(InputScanner::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	InputScanner::MUTEX = true;
        // If no other signal flag is set, set FULLOPEN signal flag True
        if(InputScanner::OVERCURRENT == false && InputScanner::IRBEAMTRIP == false && InputScanner::BUTTON == false && InputScanner::FULLOPEN == false && InputScanner::FULLCLOSED == false){
        	InputScanner::FULLOPEN = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        InputScanner::MUTEX = false;
    }
}

void InputScanner::signalFullClosed() {
	// Check that no one else is accessing the shared (global) variables
    if(InputScanner::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	InputScanner::MUTEX = true;
        // If no other signal flag is set, set FULLCLOSED signal flag True
        if(InputScanner::OVERCURRENT == false && InputScanner::IRBEAMTRIP == false && InputScanner::BUTTON == false && InputScanner::FULLOPEN == false && InputScanner::FULLCLOSED == false){
        	InputScanner::FULLCLOSED = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        InputScanner::MUTEX = false;
    }
}

//InputScanner::~InputScanner() {
//    // TODO Auto-generated destructor stub
//}
