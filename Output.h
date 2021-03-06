/*
 * Output.h
 *
 *  Created on: Feb 20, 2018
*      Author: Emily Filmer, Zachary Campanella
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_
//QNX I/O
#include <sys/neutrino.h>
#include <stdint.h>
#include <sys/mman.h>
#include <hw/inout.h>

class Output {
public:
    Output();
    virtual ~Output();
    static void turnOnBeam();
    static void turnOffBeam();
    static void setMotorUp();
    static void setMotorDown();
    static void setMotorOff();

    static void fullOpen();
    static void fullClose();

    static void motorStatus();
    static void beamStatus();
    static bool motorUp;
    static bool motorDown;
    static bool beamOn;

    static bool simulation;

	static uintptr_t portA;
	static uintptr_t portB;
	static uintptr_t portC;
	static uintptr_t ctrReg;

	static void readA();
	static int AVal;
	static int BVal;
	static int CVal;

	static void init();
};

#endif /* OUTPUT_H_ */
