/*
 * State.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#ifndef STATE_H_
#define STATE_H_
#include "Output.h"

class State {
public:
    State(Output* inOutput);
    virtual ~State();
    virtual void entry() {};
    virtual void exit() {};
    virtual void reaction(void*) {};

    Output* output;


private:

};


#endif /* STATE_H_ */
