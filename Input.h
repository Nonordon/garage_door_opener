/*
 * Input.h
 *
 *  Created on: Feb 25, 2018
 *      Author: Nonordon
 */

#ifndef INPUT_H_
#define INPUT_H_

class Input {
public:
	Input();
	virtual ~Input();
	virtual bool getEvent(unsigned char* event);// {return false;}
};

#endif /* INPUT_H_ */
