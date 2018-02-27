/*
 * GarageDoorController.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: Nonordon
 */

#include "GarageDoorController.h"
#include <iostream>
#include "Closed.h"
#include "Closing.h"
#include "Open.h"
#include "Opening.h"
#include "Stopped.h"

#include "ClosedButtonOpening.h"
#include "ClosingButtonStopped.h"
#include "ClosingFullclosedClosed.h"
#include "ClosingInfraredbeamOpening.h"
#include "ClosingOvercurrentOpening.h"
#include "OpenButtonClosing.h"
#include "OpeningButtonStopped.h"
#include "OpeningFullopenOpen.h"
#include "OpeningOvercurrentStopped.h"
#include "StoppedButtonClosing.h"
#include "StoppedButtonOpening.h"

GarageDoorController::GarageDoorController(std::queue<char>* inQueue) {
	// TODO Auto-generated constructor stub
    currentState = 0;
    direction = 0;
    position = 0;
    ioqueue = inQueue;

    Closed* closed = new Closed();
    Closing* closing = new Closing();
    Open* open = new Open();
    Opening* opening = new Opening();
    Stopped* stopped = new Stopped();
    stateList.push_back(closed);   // 0
    stateList.push_back(closing);  // 1
    stateList.push_back(open);     // 2
    stateList.push_back(opening);  // 3
    stateList.push_back(stopped);  // 4

    // Transitions from CLOSED state
    std::vector<Transition*> closed_transitions;
    ClosedButtonOpening* closedButtonOpening = new ClosedButtonOpening();
    closed_transitions.push_back(closedButtonOpening);
    transitionList.push_back(closed_transitions);

    // Transitions from CLOSING state
    std::vector<Transition*> closing_transitions;
    ClosingButtonStopped* closingButtonStopped = new ClosingButtonStopped();
    ClosingFullclosedClosed* closingFullclosedClosed = new ClosingFullclosedClosed();
    ClosingInfraredbeamOpening* closingInfraredbeamOpening = new ClosingInfraredbeamOpening();
    ClosingOvercurrentOpening* closingOvercurrentOpening = new ClosingOvercurrentOpening();
    closing_transitions.push_back(closingButtonStopped);
    closing_transitions.push_back(closingFullclosedClosed);
    closing_transitions.push_back(closingInfraredbeamOpening);
    closing_transitions.push_back(closingOvercurrentOpening);
    transitionList.push_back(closing_transitions);

    // Transitions from OPEN state
    std::vector<Transition*> open_transitions;
    OpenButtonClosing* openButtonClosing = new OpenButtonClosing();
    open_transitions.push_back(openButtonClosing);
    transitionList.push_back(open_transitions);

    // Transitions from OPENING state
    std::vector<Transition*> opening_transitions;
    OpeningButtonStopped* openingButtonStopped = new OpeningButtonStopped();
    OpeningFullopenOpen* openingFullopenOpen = new OpeningFullopenOpen();
    OpeningOvercurrentStopped* openingOvercurrentStopped = new OpeningOvercurrentStopped();
    opening_transitions.push_back(openingButtonStopped);
    opening_transitions.push_back(openingFullopenOpen);
    opening_transitions.push_back(openingOvercurrentStopped);
    transitionList.push_back(opening_transitions);

    // Transitions from STOPPED state
    std::vector<Transition*> stopped_transitions;
    StoppedButtonClosing* stoppedButtonClosing = new StoppedButtonClosing();
    StoppedButtonOpening* stoppedButtonOpening = new StoppedButtonOpening();
    stopped_transitions.push_back(stoppedButtonClosing);
    stopped_transitions.push_back(stoppedButtonOpening);
    transitionList.push_back(stopped_transitions);

}

GarageDoorController::~GarageDoorController() {
	// TODO Auto-generated destructor stub
}

void* GarageDoorController::GarageDoorControllerThread(void* arg) {
	GarageDoorController GDC = GarageDoorController((std::queue<char>*) arg);

	do{
    	for (unsigned int trans = 0; trans < GDC.transitionList[GDC.currentState].size(); trans++)
    	{
    		//std::cout << GDC.currentState << std::endl;
    		if (GDC.transitionList[GDC.currentState][trans]->guard() && GDC.transitionList[GDC.currentState][trans]->accept())
    		{
    			std::cout << "Pre" << GDC.currentState << std::endl;
    			GDC.transitionList[GDC.currentState][trans]->event();
    			GDC.currentState = GDC.transitionList[GDC.currentState][trans]->nextState;
    			GDC.stateList[GDC.currentState]->entry();
    			std::cout << "Post" << GDC.currentState << std::endl;
    		}
    	}

    }while (true); // Loop forever
    return 0;
}
