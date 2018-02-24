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
    extern bool MUTEX;

    extern bool OVERCURRENT;
    extern bool IRBEAMTRIP;
    extern bool BUTTON;
    extern bool FULLOPEN;
    extern bool FULLCLOSED;
};

#endif /* GLOBAL_H_ */
