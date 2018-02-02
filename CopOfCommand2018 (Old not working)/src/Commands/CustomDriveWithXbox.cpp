#include "CustomDriveWithXbox.h"
#include "../RobotMap.h"
#include "../Subsystems/TankDrive.h"

CustomDriveWithXbox::CustomDriveWithXbox() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

	Requires(&MyTankDrive);
}

// Called just before this Command runs the first time
void CustomDriveWithXbox::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CustomDriveWithXbox::Execute() {

	double MotorValues[4];
	MotorValues[0] = MyTankDrive.DriveValues(LXboxStick, RXboxStick, LXboxTrigger, RXboxTrigger)[0];
	MotorValues[1] = MyTankDrive.DriveValues(LXboxStick, RXboxStick, LXboxTrigger, RXboxTrigger)[1];
	MotorValues[2] = MyTankDrive.DriveValues(LXboxStick, RXboxStick, LXboxTrigger, RXboxTrigger)[2];
	MotorValues[3] = MyTankDrive.DriveValues(LXboxStick, RXboxStick, LXboxTrigger, RXboxTrigger)[3];
	MyTankDrive.DriveMotors(MotorValues);


}

// Make this return true when this Command no longer needs to run execute()
bool CustomDriveWithXbox::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CustomDriveWithXbox::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CustomDriveWithXbox::Interrupted() {

}
