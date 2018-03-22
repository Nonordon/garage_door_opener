/*
 * StateTable.h
 *
 *  Created on: Feb 20, 2018
*      Author: Emily Filmer, Zachary Campanella
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

    //State stateList[];
    std::vector<State*> stateList;

    //Transition TransitionList[][5];
    std::vector< std::vector<Transition*> > transitionList;

    int currentState;

    std::queue<char>* ioqueue;

    static bool QUEUEMUTEX;



};

#endif /* STATETABLE_H_ */
