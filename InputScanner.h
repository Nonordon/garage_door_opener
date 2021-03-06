/*
 * InputScanner.h
 *
 *  Created on: Feb 24, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#ifndef INPUTSCANNER_H_
#define INPUTSCANNER_H_

#include "StateTable.h"
#include "Output.h"
#include <pthread.h>

class InputScanner: public StateTable {
public:
	InputScanner(std::queue<char> *inQueue);
	pthread_t inputScannerThreadID;
	static void* InputScannerThread(void* arg);
	std::string byteToString(int byte);
	Output* output;

	struct timespec openTimer, closeTimer, infraTimer, motorTimer, pushTimer;
};

#endif /* INPUTSCANNER_H_ */
