/*
 * Output.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Emily Filmer, Zachary Campanella
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_
#include <iostream>

class Output {
public:
    Output();
    virtual ~Output();
    void turnOnBeam();
    void turnOffBeam();
    void setMotorUp();
    void setMotorDown();
    void setMotorOff();

    void fullOpen();
    void fullClose();

//private:
    void motorStatus();
    void beamStatus();
    bool motorUp;
    bool motorDown;
    bool beamOn;
};

#endif /* OUTPUT_H_ */
