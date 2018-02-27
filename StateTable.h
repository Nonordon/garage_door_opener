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
#include <queue>

class StateTable {
public:
    StateTable();
    virtual ~StateTable();
    //int getCurrentState() {return currentState;}
    //int getMaxStates() {return maxStates;}

    //State stateList[];
    std::vector<State*> stateList;

    //Transition TransitionList[][5];
    std::vector< std::vector<Transition*> > transitionList;

    int currentState;
    //int maxStates;

    std::queue<char>* ioqueue;



};

#endif /* STATETABLE_H_ */
