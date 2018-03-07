# garage_door_opener

Program created for a [project](http://www.se.rit.edu/~swen-564/projects/state%20machine/Door%20Opener%20-%20Hardware%20Simulation.html) in SWEN-564 Modeling of Real-Time Systems. Built using QNX Momentics IDE 4.7.

Garage door opener written in C++ for a [Diamond Systems Athena board](http://www.se.rit.edu/~rtembed/LabInfo/DiamondSystems/Athena%20-%20Manual%201.40.pdf) to be connected to a pre-programmed [DIGILENT Spartan 3 board](http://www.se.rit.edu/~rtembed/LabInfo/Digilent/Spartan%203%20board%20-%20Reference%20manual.PDF).

Running program with argument "-s" starts it in simulation mode.

# IO Wiring

| Signal | [Athena Port](http://www.se.rit.edu/~rtembed/LabInfo/DiamondSystems/Athena%20-%20Manual%201.40.pdf#page=15) | [Spartan Port](http://www.se.rit.edu/~rtembed/LabInfo/FPGA-Interface/FPGA%20A2%20Pinouts.pdf) | I/O (in respect to Athena) |
| --- | --- | --- | --- |
| Digital Ground | Dground | A2-1 | N/A |
| Full Open | DIO A0 | A2-5 | Input |
| Full Close | DIO A1 | A2-7 | Input |
| IR Beam Broken |  DIO A2 | A2-9 | Input |
| Motor Overcurrent | DIO A3 | A2-11 | Input |
| Remote Pushbutton | DIO A4 | A2-13 | Input |
| Motor Up | DIO B0 | A2-6 | Output |
| Motor Down | DIO B1 | A2-8 | Output |
| IR Beam | DIO B2 | A2-10 | Output |
| FPGA Reset | DIO B7 | A2-12 | Output |