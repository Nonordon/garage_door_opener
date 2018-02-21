/*
 * State.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#ifndef STATE_H_
#define STATE_H_

class State {
public:
    State();
    virtual ~State();
    void entry();
    void exit();
    void reaction();

private:

};


#endif /* STATE_H_ */
