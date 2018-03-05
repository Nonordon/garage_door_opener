#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include "GarageDoorController.h"
#include "InputScanner.h"
#include "Output.h"
#include <queue>
#include <unistd.h>

int main(int argc, char *argv[]) {
	std::queue<char>* programQueue = new std::queue<char>;
	//Need to check the input argument and see if it should run as a sim

	Output::simulation = false;
	int opList;

	while ((opList = getopt(argc, argv, "s")) != -1)
	{
		switch(opList)
		{
		case 's':
			Output::simulation = true;
			std::cout << "Started in simulation mode." << std::endl;
			break;
		}
	}

	try
	{
		pthread_t IS;
		pthread_attr_t threadAttr;
		pthread_attr_init(&threadAttr);		// initialize thread attributes structure
		pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_JOINABLE);
		pthread_create(&IS, &threadAttr, &InputScanner::InputScannerThread, programQueue);
		pthread_t GDC;
		//pthread_attr_t threadAttr;
		pthread_attr_init(&threadAttr);		// initialize thread attributes structure
		pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_JOINABLE);
		pthread_create(&GDC, &threadAttr, &GarageDoorController::GarageDoorControllerThread, programQueue);

		while(true)
		{
		}
	}
	catch (char* c)
	{
		std::cout << c;
	}

    return EXIT_SUCCESS;
}
