/*
 * StateTable.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#ifndef STATETABLE_H_
#define STATETABLE_H_

class StateTable {
public:
    StateTable(int maxStates, int initialState = 0);
    virtual ~StateTable() {};
    int getCurrentState() {return currentState;};
    int getMaxStates() {return maxStates;};

private:
    int currentState;
    int maxStates;

};

#endif /* STATETABLE_H_ */
