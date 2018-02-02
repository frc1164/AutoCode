#ifndef TankDrive_H
#define TankDrive_H

#include <Commands/Subsystem.h>
#include <Victor.h>
#include <Joystick.h>
#include <XboxController.h>
#include <Encoder.h>


#include "../OI.h"

class TankDrive : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Victor *Left1, *Left2, *Right1, *Right2;
	Joystick *Stick;
	XboxController *Xbox;
	Encoder *LeftEncoder, *RightEncoder;

	double Motors[4];
	double Left, Right, LTrigger, RTrigger;

public:
	TankDrive();
	void InitDefaultCommand();
	void DriveLeftMotors(int LAxis);
	void DriveRightMotors(int RAxis);
	double* DriveValues(int LAxis, int RAxis, int RTriggerAxis, int LTriggerAxis);
	void DriveMotors(double DriveValues[4]);
	void Brake();

	double DriveForward(double TargetDistance, double speed);


};

#endif  // TankDrive_H
