/*
 * GarageDoorController.cpp
 *
 *  Created on: Feb 22, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#include "GarageDoorController.h"
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
    ClosedButtonOpening* closedButtonOpening = new ClosedButtonOpening(inQueue);
    closed_transitions.push_back(closedButtonOpening);
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
    transitionList.push_back(closing_transitions);

    // Transitions from OPEN state
    std::vector<Transition*> open_transitions;
    OpenButtonClosing* openButtonClosing = new OpenButtonClosing(inQueue);
    open_transitions.push_back(openButtonClosing);
    transitionList.push_back(open_transitions);

    // Transitions from OPENING state
    std::vector<Transition*> opening_transitions;
    OpeningButtonStopped* openingButtonStopped = new OpeningButtonStopped(inQueue);
    OpeningFullopenOpen* openingFullopenOpen = new OpeningFullopenOpen(inQueue);
    OpeningOvercurrentStopped* openingOvercurrentStopped = new OpeningOvercurrentStopped(inQueue);
    opening_transitions.push_back(openingButtonStopped);
    opening_transitions.push_back(openingFullopenOpen);
    opening_transitions.push_back(openingOvercurrentStopped);
    transitionList.push_back(opening_transitions);

    // Transitions from STOPPED state
    std::vector<Transition*> stopped_transitions;
    StoppedButtonClosing* stoppedButtonClosing = new StoppedButtonClosing(inQueue);
    StoppedButtonOpening* stoppedButtonOpening = new StoppedButtonOpening(inQueue);
    stopped_transitions.push_back(stoppedButtonClosing);
    stopped_transitions.push_back(stoppedButtonOpening);
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
    			GDC.stateList[GDC.currentState]->exit();
    			GDC.transitionList[GDC.currentState][trans]->event();
    			GDC.currentState = GDC.transitionList[GDC.currentState][trans]->nextState;
    			GDC.stateList[GDC.currentState]->entry();
    			GDC.stateList[GDC.currentState]->reaction(&GDC);
    		}
    	}

    }while (true); // Loop forever
    return 0;
}
