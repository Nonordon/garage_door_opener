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
#include "Inputs/FullClose.h"
#include "Inputs/FullOpen.h"
#include "Inputs/InfraredBeamTrip.h"
#include "Inputs/MotorOvercurrent.h"
#include "Inputs/PushButton.h"

bool InputScanner::MUTEX = false;
bool InputScanner::FULLCLOSED = false;
bool InputScanner::FULLOPEN = false;
bool InputScanner::IRBEAMTRIP = false;
bool InputScanner::OVERCURRENT = false;
bool InputScanner::BUTTON = false;

InputScanner::InputScanner() {
    // TODO Auto-generated constructor stub
}

void* InputScanner::InputScannerThread(void* arg) {
    char userInput = 'x';
    InputScanner IS = InputScanner();
    IS.inputs.push_back(FullClose::Input());
    IS.inputs.push_back(FullOpen::Input());
    IS.inputs.push_back(InfraredBeamTrip::Input());
    IS.inputs.push_back(MotorOvercurrent::Input());
    IS.inputs.push_back(PushButton::Input());

    do{
    	// print input directions on screen
        std::cout << "\nSignal Options:\n'm' - motor overcurrent detected \n'i' - infrared beam interruption \n'r' - remote button press\n";
        std::cout << "\nEnter signal choice: ";

        // get user's input
        std::cin >> userInput;
        if(MUTEX == false)
        {
           	// Set MUTEX to True to lock the shared resources temporarily
			MUTEX = true;

			InputScanner::FULLCLOSED = IS.inputs[0].getEvent((unsigned char*) userInput);
			InputScanner::FULLOPEN = IS.inputs[1].getEvent((unsigned char*) userInput);
			InputScanner::IRBEAMTRIP = IS.inputs[2].getEvent((unsigned char*) userInput);
			InputScanner::OVERCURRENT = IS.inputs[3].getEvent((unsigned char*) userInput);
			InputScanner::BUTTON = IS.inputs[4].getEvent((unsigned char*) userInput);

			// Set MUTEX to False to release our lock on the shared resources
			MUTEX = false;
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
    if(MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	MUTEX = true;
        // If no other signal flag is set, set OVERCURRENT signal flag True
        if((OVERCURRENT == false) && (IRBEAMTRIP == false) && (BUTTON == false) && (FULLOPEN == false) && (FULLCLOSED == false)){
        	OVERCURRENT = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        MUTEX = false;
    }
}

void InputScanner::signalInfraredBeamTrip() {
	// Check that no one else is accessing the shared (global) variables
    if(MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	MUTEX = true;
        // If no other signal flag is set, set IRBEAMTRIP signal flag True
        if(OVERCURRENT == false && IRBEAMTRIP == false && BUTTON == false && FULLOPEN == false && FULLCLOSED == false){
        	IRBEAMTRIP = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        MUTEX = false;
    }
}

void InputScanner::signalPushButton() {
	// Check that no one else is accessing the shared (global) variables
    if(MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	MUTEX = true;
        // If no other signal flag is set, set BUTTON signal flag True
        if(OVERCURRENT == false && IRBEAMTRIP == false && BUTTON == false && FULLOPEN == false && FULLCLOSED == false){
        	BUTTON = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        MUTEX = false;
    }
}

void InputScanner::signalFullOpen() {
	// Check that no one else is accessing the shared (global) variables
    if(MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	MUTEX = true;
        // If no other signal flag is set, set FULLOPEN signal flag True
        if(OVERCURRENT == false && IRBEAMTRIP == false && BUTTON == false && FULLOPEN == false && FULLCLOSED == false){
        	FULLOPEN = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        MUTEX = false;
    }
}

void InputScanner::signalFullClosed() {
	// Check that no one else is accessing the shared (global) variables
    if(MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	MUTEX = true;
        // If no other signal flag is set, set FULLCLOSED signal flag True
        if(OVERCURRENT == false && IRBEAMTRIP == false && BUTTON == false && FULLOPEN == false && FULLCLOSED == false){
        	FULLCLOSED = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        MUTEX = false;
    }
}

//InputScanner::~InputScanner() {
//    // TODO Auto-generated destructor stub
//}
