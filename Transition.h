/*
 * Transition.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#ifndef TRANSITION_H_
#define TRANSITION_H_
//#include "State.h"
#include <queue>

class Transition {
public:
    Transition(std::queue<char>* inQueue);
    virtual ~Transition();
    int nextState;
    virtual bool guard(void*) {return true;}
    virtual bool accept(char* ev) {return true;}
    virtual void event() {}
    std::queue<char>* ioqueue;
};

#endif /* TRANSITION_H_ */
