/*
 * GarageDoorController.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: Nonordon
 */

#include "GarageDoorController.h"

GarageDoorController::GarageDoorController() {
	// TODO Auto-generated constructor stub
	direction = 0;
	position = 0;
    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);		// initialize thread attributes structure
    pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&GarageDoorControllerThreadID, &threadAttr, &GarageDoorController::GarageDoorControllerThread, this);


}

GarageDoorController::~GarageDoorController() {
	// TODO Auto-generated destructor stub
}

void* GarageDoorController::GarageDoorControllerThread(void* arg) {
	GarageDoorController GDC = GarageDoorController();
    do{
    	for (unsigned int trans = 0; trans < GDC.transitionList[GDC.currentState].size(); trans++)
    	{
    		if (GDC.transitionList[GDC.currentState][trans].guard() && GDC.transitionList[GDC.currentState][trans].accept())
    		{
    			GDC.transitionList[GDC.currentState][trans].event();
    			GDC.currentState = GDC.transitionList[GDC.currentState][trans].nextState;
    			GDC.stateList[GDC.currentState].entry();
    		}
    	}

    }while (true); // Loop forever
    return 0;
}
