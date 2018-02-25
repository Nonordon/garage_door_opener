/*
 * Global.h
 *
 *  Created on: Feb 24, 2018
 *      Author: edf7470
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

class Global{
public:
    // MUTEX is True when a thread is currently accessing shared (global) variables, else False.
    bool MUTEX = false;

    bool OVERCURRENT = false;
    bool IRBEAMTRIP = false;
    bool BUTTON = false;
    bool FULLOPEN = false;
    bool FULLCLOSED = false;
};

#endif /* GLOBAL_H_ */
