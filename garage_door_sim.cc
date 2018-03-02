#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include "GarageDoorController.h"
#include "InputScanner.h"
#include <queue>

int main(int argc, char *argv[]) {
	std::queue<char>* programQueue = new std::queue<char>;
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

    return EXIT_SUCCESS;
}
