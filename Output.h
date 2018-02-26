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
//private:
    static void motorStatus();
    static void beamStatus();
    static bool motorUp;
    static bool motorDown;
    static bool beamOn;
};

#endif /* OUTPUT_H_ */
