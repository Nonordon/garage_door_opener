/*
 * Transition.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#ifndef TRANSITION_H_
#define TRANSITION_H_

class Transition {
public:
    Transition();
    virtual ~Transition();
    State nextState;
    bool guard()
    bool accept()
    void event()
};

#endif /* TRANSITION_H_ */
