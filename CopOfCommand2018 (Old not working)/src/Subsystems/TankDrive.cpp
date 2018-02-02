#include "TankDrive.h"
#include "../RobotMap.h"
#include "../Commands/Drive.h"
#include "../Commands/CustomDriveWithXbox.h"

#include <SmartDashboard/SmartDashboard.h>
#include <Victor.h>

//Left Two Motors need to be inverted

TankDrive::TankDrive() : Subsystem("TankDrive") {

	Left1 = new Victor(kLeft1);
	Left2 = new Victor(kLeft2);
	Right1 = new Victor(kRight1);
	Right2 = new Victor(kRight2);
	Stick = new Joystick(0);
	Xbox = new XboxController(0);

	Left = 0;
	Right = 0;
	RTrigger = 0;
	LTrigger = 0;

	LeftEncoder = new Encoder(0,1, true, Encoder::EncodingType::k2X);
	RightEncoder = new Encoder(2,3, false, Encoder::EncodingType::k2X);

	LeftEncoder->Reset();
	RightEncoder->Reset();

	Left1->SetInverted(true);
	Left2->SetInverted(true);
}

void TankDrive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new CustomDriveWithXbox());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


void TankDrive::DriveLeftMotors(int LAxis){
	Left1->Set(-(Stick->GetRawAxis(LAxis)));
	Left2->Set(-(Stick->GetRawAxis(LAxis)));
}

void TankDrive::DriveRightMotors(int RAxis){
	Right1->Set(Stick->GetRawAxis(RAxis));
	Right2->Set(Stick->GetRawAxis(RAxis));
}

double* TankDrive::DriveValues(int LAxis, int RAxis, int RTriggerAxis, int LTriggerAxis){

	RTrigger = Xbox->GetRawAxis(RTriggerAxis);
	LTrigger = Xbox->GetRawAxis(LTriggerAxis);
	Left = Xbox->GetRawAxis(LAxis);
	Right = Xbox->GetRawAxis(RAxis);

	//Resets encoders from start button
	if (Xbox->GetStartButton() == 1){LeftEncoder->Reset();RightEncoder->Reset();}

	//Drive forward and backward
	Motors[0] = RTrigger - LTrigger;
	Motors[1] = RTrigger - LTrigger;
	Motors[2] = RTrigger - LTrigger;
	Motors[3] = RTrigger - LTrigger;

	//Turning slowly (Assuming LAxis is the slow turning axis)
	Motors[0] = (1 - Right) * Motors[0];
	Motors[1] = (1 - Right) * Motors[1];
	Motors[2] = (1 + Right) * Motors[2];
	Motors[3] = (1 + Right) * Motors[3];

	//Turning quickly (Assuming RAxis is the fast turning axis)
	Motors[0] = Motors[0] + (0.5 * Left);
	Motors[1] = Motors[1] + (0.5 * Left);
	Motors[2] = Motors[2] - (0.5 * Left);
	Motors[3] = Motors[3] - (0.5 * Left);

	return Motors;
}

void TankDrive::DriveMotors(double DriveValues[4]) {
	Right1->Set(DriveValues[0]);
	Right2->Set(DriveValues[1]);
	Left1->Set(DriveValues[2]);
	Left2->Set(DriveValues[3]);
}

void TankDrive::Brake(){
	Right1->Set(0);
	Right2->Set(0);
	Left1->Set(0);
	Left2->Set(0);
}

double TankDrive::DriveForward(double TargetDistance, double speed){

	double distance = (LeftEncoder->GetDistance() + RightEncoder->GetDistance()) / 2.0;
	double inches = distance/kEncoder;

	frc::SmartDashboard::PutNumber("Inches", inches);

	Right1->Set(speed);
	Right2->Set(speed);
	Left1->Set(speed);
	Left2->Set(speed);

	return inches;
}

