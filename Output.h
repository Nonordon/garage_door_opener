/*
 * Output.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Nonordon
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

class Output {
public:
    Output();
    virtual ~Output();
    void turnOnBeam();
    void turnOffBeam();
    void setMotorUp();
    void setMotorDown();
private:
    bool motorUp;
    bool motorDown;
    bool beamOn;
    void motorStatus();
    void beamStatus();
};

#endif /* OUTPUT_H_ */
