/*
 * StateTable.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#include "StateTable.h"
#include "State.h"
#include "States/Closed.h"
#include "States/Closing.h"
#include "States/Open.h"
#include "States/Opening.h"
#include "States/Stopped.h"

#include "Transition.h"
#include "Transitions/ClosedButtonOpening.h"
#include "Transitions/ClosingButtonStopped.h"
#include "Transitions/ClosingFullclosedClosed.h"
#include "Transitions/ClosingInfraredbeamOpening.h"
#include "Transitions/ClosingOvercurrentOpening.h"
#include "Transitions/OpenButtonClosing.h"
#include "Transitions/OpeningButtonStopped.h"
#include "Transitions/OpeningFullopenOpen.h"
#include "Transitions/OpeningOvercurrentStopped.h"
#include "Transitions/StoppedButtonClosing.h"
#include "Transitions/StoppedButtonOpening.h"

StateTable::StateTable(int initialState) {
    // TODO Auto-generated constructor stub
    currentState = initialState;

    stateList.push_back(Closed::State());
    stateList.push_back(Closing::State());
    stateList.push_back(Open::State());
    stateList.push_back(Opening::State());
    stateList.push_back(Stopped::State());

    // Transitions from CLOSED state
    std::vector<Transition> closed_transitions;
    closed_transitions.push_back(ClosedButtonOpening::Transition());
    transitionList.push_back(closed_transitions);

    // Transitions from CLOSING state
    std::vector<Transition> closing_transitions;
    closing_transitions.push_back(ClosingButtonStopped::Transition());
    closing_transitions.push_back(ClosingFullclosedClosed::Transition());
    closing_transitions.push_back(ClosingInfraredbeamOpening::Transition());
    closing_transitions.push_back(ClosingOvercurrentOpening::Transition());
    transitionList.push_back(closing_transitions);

    // Transitions from OPEN state
    std::vector<Transition> open_transitions;
    open_transitions.push_back(OpenButtonClosing::Transition());
    transitionList.push_back(open_transitions);

    // Transitions from OPENING state
    std::vector<Transition> opening_transitions;
    opening_transitions.push_back(OpeningButtonStopped::Transition());
    opening_transitions.push_back(OpeningFullopenOpen::Transition());
    opening_transitions.push_back(OpeningOvercurrentStopped::Transition());
    transitionList.push_back(opening_transitions);

    // Transitions from STOPPED state
    std::vector<Transition> stopped_transitions;
    stopped_transitions.push_back(StoppedButtonClosing::Transition());
    stopped_transitions.push_back(StoppedButtonOpening::Transition());
    transitionList.push_back(stopped_transitions);

}

StateTable::~StateTable() {
	// TODO Auto-generated destructor stub
}
