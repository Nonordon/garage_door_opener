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
    static bool MUTEX = false;

    static bool OVERCURRENT = false;
    static bool IRBEAMTRIP = false;
    static bool BUTTON = false;
    static bool FULLOPEN = false;
    static bool FULLCLOSED = false;
};

#endif /* GLOBAL_H_ */
