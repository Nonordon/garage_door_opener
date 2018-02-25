/*
 * StateTable.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#ifndef STATETABLE_H_
#define STATETABLE_H_
#include "Transition"
#include "State"

class StateTable {
public:
    StateTable(int maxStates, int initialState = 0);
    virtual ~StateTable() {}
    int getCurrentState() {return currentState;};
    int getMaxStates() {return maxStates;};

    std::map<int, std::map<int,Transition>> stateTransitionMap;

private:
    int currentState;
    int maxStates;

};

#endif /* STATETABLE_H_ */
