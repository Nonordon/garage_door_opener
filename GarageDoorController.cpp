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
#include "AnyResetClosed.h"

GarageDoorController::GarageDoorController(std::queue<char>* inQueue) {
	// TODO Auto-generated constructor stub
    currentState = 0;
    direction = 0;
    position = 0;
    ioqueue = inQueue;
	Output* output = new Output();
    //output->reset();

    Closed* closed = new Closed(output);
    Closing* closing = new Closing(output);
    Open* open = new Open(output);
    Opening* opening = new Opening(output);
    Stopped* stopped = new Stopped(output);
    stateList.push_back(closed);   // 0
    stateList.push_back(closing);  // 1
    stateList.push_back(open);     // 2
    stateList.push_back(opening);  // 3
    stateList.push_back(stopped);  // 4

    // Transitions from CLOSED state
    std::vector<Transition*> closed_transitions;
    ClosedButtonOpening* closedButtonOpening = new ClosedButtonOpening(inQueue);
    AnyResetClosed* anyResetClosed = new AnyResetClosed(inQueue);
    closed_transitions.push_back(closedButtonOpening);
    closed_transitions.push_back(anyResetClosed);
    transitionList.push_back(closed_transitions);

    // Transitions from CLOSING state
    std::vector<Transition*> closing_transitions;
    ClosingButtonStopped* closingButtonStopped = new ClosingButtonStopped(inQueue);
    ClosingFullclosedClosed* closingFullclosedClosed = new ClosingFullclosedClosed(inQueue);
    ClosingInfraredbeamOpening* closingInfraredbeamOpening = new ClosingInfraredbeamOpening(inQueue);
    ClosingOvercurrentOpening* closingOvercurrentOpening = new ClosingOvercurrentOpening(inQueue);
    closing_transitions.push_back(closingButtonStopped);
    closing_transitions.push_back(closingFullclosedClosed);
    closing_transitions.push_back(closingInfraredbeamOpening);
    closing_transitions.push_back(closingOvercurrentOpening);
    closing_transitions.push_back(anyResetClosed);
    transitionList.push_back(closing_transitions);

    // Transitions from OPEN state
    std::vector<Transition*> open_transitions;
    OpenButtonClosing* openButtonClosing = new OpenButtonClosing(inQueue);
    open_transitions.push_back(openButtonClosing);
    open_transitions.push_back(anyResetClosed);
    transitionList.push_back(open_transitions);

    // Transitions from OPENING state
    std::vector<Transition*> opening_transitions;
    OpeningButtonStopped* openingButtonStopped = new OpeningButtonStopped(inQueue);
    OpeningFullopenOpen* openingFullopenOpen = new OpeningFullopenOpen(inQueue);
    OpeningOvercurrentStopped* openingOvercurrentStopped = new OpeningOvercurrentStopped(inQueue);
    opening_transitions.push_back(openingButtonStopped);
    opening_transitions.push_back(openingFullopenOpen);
    opening_transitions.push_back(openingOvercurrentStopped);
    opening_transitions.push_back(anyResetClosed);
    transitionList.push_back(opening_transitions);

    // Transitions from STOPPED state
    std::vector<Transition*> stopped_transitions;
    StoppedButtonClosing* stoppedButtonClosing = new StoppedButtonClosing(inQueue);
    StoppedButtonOpening* stoppedButtonOpening = new StoppedButtonOpening(inQueue);
    stopped_transitions.push_back(stoppedButtonClosing);
    stopped_transitions.push_back(stoppedButtonOpening);
    stopped_transitions.push_back(anyResetClosed);
    transitionList.push_back(stopped_transitions);

}

GarageDoorController::~GarageDoorController() {
	// TODO Auto-generated destructor stub
}

void* GarageDoorController::GarageDoorControllerThread(void* arg) {

	GarageDoorController GDC = GarageDoorController((std::queue<char>*) arg);
	char event;
	GDC.stateList[GDC.currentState]->entry();
	do{
		event = 'x';
		if (!StateTable::QUEUEMUTEX)
		{
			StateTable::QUEUEMUTEX = true;
			if (!GDC.ioqueue->empty())
			{
				event = GDC.ioqueue->front();
				GDC.ioqueue->pop();
			}
			StateTable::QUEUEMUTEX = false;
		}
    	for (unsigned int trans = 0; trans < GDC.transitionList[GDC.currentState].size(); trans++)
    	{
    		if (GDC.transitionList[GDC.currentState][trans]->accept(&event) && GDC.transitionList[GDC.currentState][trans]->guard(&GDC))
    		{
        		std::cout << "Pre: " << GDC.currentState << std::endl;
    			GDC.stateList[GDC.currentState]->exit();
        		std::cout << "Exited " << std::endl;
    			GDC.transitionList[GDC.currentState][trans]->event();
        		std::cout << "Trans evented " << std::endl;
    			GDC.currentState = GDC.transitionList[GDC.currentState][trans]->nextState;
        		std::cout << "Got next state: " << GDC.currentState << std::endl;
    			GDC.stateList[GDC.currentState]->entry();
        		std::cout << "Post: " << GDC.currentState << std::endl;
    			GDC.stateList[GDC.currentState]->reaction(&GDC);
        		std::cout << "Reacted" << std::endl;
    		}
    	}

    }while (true); // Loop forever
    return 0;
}
