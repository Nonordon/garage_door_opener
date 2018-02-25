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

InputScanner::InputScanner() {
    // TODO Auto-generated constructor stub
    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);		// initialize thread attributes structure
    pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&inputScannerThreadID, &threadAttr, &InputScanner::InputScannerThread, this);
}

void* InputScanner::InputScannerThread(void* arg) {
    char userInput = 'x';

    do{
    	// print input directions on screen
        std::cout << "\nSignal Options:\n'm' - motor overcurrent detected \n'i' - infrared beam interruption \n'r' - remote button press\n";
        std::cout << "\nEnter signal choice: ";

        // get user's input
        std::cin >> userInput;

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

    }while (true); // Loop forever
    return 0;
}

void InputScanner::signalMotorOvercurrent() {
	// Check that no one else is accessing the shared (global) variables
    if(Global::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	Global::MUTEX = true;
        // If no other signal flag is set, set OVERCURRENT signal flag True
        if((Global::OVERCURRENT == false) && (Global::IRBEAMTRIP == false) && (Global::BUTTON == false) && (Global::FULLOPEN == false) && (Global::FULLCLOSED == false)){
        	Global::OVERCURRENT = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        Global::MUTEX = false;
    }
}

void InputScanner::signalInfraredBeamTrip() {
	// Check that no one else is accessing the shared (global) variables
    if(Global::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	Global::MUTEX = true;
        // If no other signal flag is set, set IRBEAMTRIP signal flag True
        if(Global::OVERCURRENT == false && Global::IRBEAMTRIP == false && Global::BUTTON == false && Global::FULLOPEN == false && Global::FULLCLOSED == false){
        	Global::IRBEAMTRIP = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        Global::MUTEX = false;
    }
}

void InputScanner::signalPushButton() {
	// Check that no one else is accessing the shared (global) variables
    if(Global::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	Global::MUTEX = true;
        // If no other signal flag is set, set BUTTON signal flag True
        if(Global::OVERCURRENT == false && Global::IRBEAMTRIP == false && Global::BUTTON == false && Global::FULLOPEN == false && Global::FULLCLOSED == false){
        	Global::BUTTON = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        Global::MUTEX = false;
    }
}

void InputScanner::signalFullOpen() {
	// Check that no one else is accessing the shared (global) variables
    if(Global::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	Global::MUTEX = true;
        // If no other signal flag is set, set FULLOPEN signal flag True
        if(Global::OVERCURRENT == false && Global::IRBEAMTRIP == false && Global::BUTTON == false && Global::FULLOPEN == false && Global::FULLCLOSED == false){
        	Global::FULLOPEN = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        Global::MUTEX = false;
    }
}

void InputScanner::signalFullClosed() {
	// Check that no one else is accessing the shared (global) variables
    if(Global::MUTEX == false){
    	// Set MUTEX to True to lock the shared resources temporarily
    	Global::MUTEX = true;
        // If no other signal flag is set, set FULLCLOSED signal flag True
        if(Global::OVERCURRENT == false && Global::IRBEAMTRIP == false && Global::BUTTON == false && Global::FULLOPEN == false && Global::FULLCLOSED == false){
        	Global::FULLCLOSED = true;
        }
        // Set MUTEX to False to release our lock on the shared resources
        Global::MUTEX = false;
    }
}

//InputScanner::~InputScanner() {
//    // TODO Auto-generated destructor stub
//}
