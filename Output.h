/*
 * Output.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_
#include <iostream>

class Output {
public:
    Output();
    virtual ~Output();
    static void turnOnBeam();
    static void turnOffBeam();
    static void setMotorUp();
    static void setMotorDown();
private:
    void motorStatus();
    void beamStatus();
	bool motorUp;
    bool motorDown;
    bool beamOn;
};

#endif /* OUTPUT_H_ */
