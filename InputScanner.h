/*
 * InputScanner.h
 *
 *  Created on: Feb 24, 2018
 *      Author: edf7470
 */

#ifndef INPUTSCANNER_H_
#define INPUTSCANNER_H_

#include <pthread.h>

class InputScanner {
public:
	InputScanner();
	pthread_t inputScannerThreadID;
	static void* InputScannerThread(void* arg);
	void signalMotorOvercurrent();
	void signalInfraredBeamTrip();
	void signalPushButton();
	void signalFullOpen();
	void signalFullClosed();
};

#endif /* INPUTSCANNER_H_ */
