/*
 * StateTable.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#include "StateTable.h"
#include "State.h"
#include "Closed.h"
#include "Closing.h"
#include "Open.h"
#include "Opening.h"
#include "Stopped.h"

#include "Transition.h"
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

StateTable::StateTable() {
    // TODO Auto-generated constructor stub
    currentState = 0;

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
    std::vector<Transition> closed_transitions;
    ClosedButtonOpening* closedButtonOpening = new ClosedButtonOpening();
    closed_transitions.push_back(closedButtonOpening);
    transitionList.push_back(closed_transitions);

    // Transitions from CLOSING state
    std::vector<Transition> closing_transitions;
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
    std::vector<Transition> open_transitions;
    OpenButtonClosing* openButtonClosing = new OpenButtonClosing();
    open_transitions.push_back(OpenButtonClosing);
    transitionList.push_back(open_transitions);

    // Transitions from OPENING state
    std::vector<Transition> opening_transitions;
    OpeningButtonStopped* openingButtonStopped = new OpeningButtonStopped();
    OpeningFullopenOpen* openingFullopenOpen = new OpeningFullopenOpen();
    OpeningOvercurrentStopped* openingOvercurrentStopped = new OpeningOvercurrentStopped();
    opening_transitions.push_back(openingButtonStopped);
    opening_transitions.push_back(openingFullopenOpen);
    opening_transitions.push_back(openingOvercurrentStopped);
    transitionList.push_back(opening_transitions);

    // Transitions from STOPPED state
    std::vector<Transition> stopped_transitions;
    StoppedButtonClosing* StoppedButtonClosing = new StoppedButtonClosing();
    StoppedButtonOpening* StoppedButtonOpening = new StoppedButtonOpening();
    stopped_transitions.push_back(StoppedButtonClosing);
    stopped_transitions.push_back(StoppedButtonOpening);
    transitionList.push_back(stopped_transitions);

}

StateTable::~StateTable() {
	// TODO Auto-generated destructor stub
}
