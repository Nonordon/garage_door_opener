/*
 * StateTable.cpp
 *
 *  Created on: Feb 20, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#include "StateTable.h"

bool StateTable::QUEUEMUTEX = false;

StateTable::StateTable() {
    // TODO Auto-generated constructor stub
    currentState = 0;

}

StateTable::~StateTable() {
	// TODO Auto-generated destructor stub
}
