/*
 * StateTable.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#ifndef STATETABLE_H_
#define STATETABLE_H_
#include "Transition.h"
#include "State.h"
#include <vector>

class StateTable {
public:
    StateTable(int initialState = 0);
    virtual ~StateTable();
    //int getCurrentState() {return currentState;}
    //int getMaxStates() {return maxStates;}

    //State stateList[];
    std::vector<State> stateList;

    //Transition TransitionList[][5];
    std::vector< std::vector<Transition> > transitionList;

    int currentState;
    //int maxStates;



};

#endif /* STATETABLE_H_ */
