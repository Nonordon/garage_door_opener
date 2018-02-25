/*
 * GarageDoorController.h
 *
 *  Created on: Feb 22, 2018
 *      Author: Nonordon
 */

#ifndef GARAGEDOORCONTROLLER_H_
#define GARAGEDOORCONTROLLER_H_

class GarageDoorController {
public:
	GarageDoorController();
	virtual ~GarageDoorController();
	void thread();
	bool direction;
	bool position;
};

#endif /* GARAGEDOORCONTROLLER_H_ */
