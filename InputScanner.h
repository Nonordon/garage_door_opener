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
#include "Input.h"

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

	std::vector<Input*> inputs;

	static bool MUTEX;

	static bool OVERCURRENT;
	static bool IRBEAMTRIP;
	static bool BUTTON;
	static bool FULLOPEN;
	static bool FULLCLOSED;

};

#endif /* INPUTSCANNER_H_ */
