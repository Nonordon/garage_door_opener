/*
 * GarageDoorController.cpp
 *
 *  Created on: Feb 22, 2018
 *      Author: Nonordon
 */

#include "GarageDoorController.h"
#include <iostream>

int	GarageDoorController::direction = 0;
int	GarageDoorController::position = 0;

GarageDoorController::GarageDoorController() {
	// TODO Auto-generated constructor stub

}

GarageDoorController::~GarageDoorController() {
	// TODO Auto-generated destructor stub
}

void* GarageDoorController::GarageDoorControllerThread(void* arg) {
	//GarageDoorController GDC = GarageDoorController();
	StateTable GDC = StateTable();
	do{
    	for (unsigned int trans = 0; trans < GDC.transitionList[GDC.currentState].size(); trans++)
    	{
    		//std::cout << GDC.currentState << std::endl;
    		if (GDC.transitionList[GDC.currentState][trans]->guard() && GDC.transitionList[GDC.currentState][trans]->accept())
    		{
    			//std::cout << "Pre" << GDC.currentState << std::endl;
    			GDC.stateList[GDC.currentState]->exit();
    			GDC.transitionList[GDC.currentState][trans]->event();
    			GDC.currentState = GDC.transitionList[GDC.currentState][trans]->nextState;
    			GDC.stateList[GDC.currentState]->entry();
    			//std::cout << "Post" << GDC.currentState << std::endl;
    		}
    	}

    }while (true); // Loop forever
    return 0;
}
