/*
 * Output.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_
#include <iostream>
//QNX I/O
#include <sys/neutrino.h>
#include <stdint.h>
#include <sys/mman.h>
#include <hw/inout.h>

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

    static bool simulation;

	uintptr_t portA;
	uintptr_t portB;
	uintptr_t portC;
	uintptr_t ctrReg;

	int AVal;
	int BVal;
	int CVal;
};

#endif /* OUTPUT_H_ */
