/*
 * InputScanner.h
 *
 *  Created on: Feb 24, 2018
 *      Author: edf7470
 */

#ifndef INPUTSCANNER_H_
#define INPUTSCANNER_H_

#include <pthread.h>
#include <vector>
#include "StateTable.h"

class InputScanner: public StateTable {
public:
	InputScanner(std::queue<char> *inQueue);
	pthread_t inputScannerThreadID;
	static void* InputScannerThread(void* arg);
	//void signalMotorOvercurrent();
	//void signalInfraredBeamTrip();
	//void signalPushButton();
	//void signalFullOpen();
	//void signalFullClosed();

};

#endif /* INPUTSCANNER_H_ */
