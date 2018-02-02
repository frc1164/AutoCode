#include "Drive.h"
#include "../Subsystems/TankDrive.h"
#include "../RobotMap.h"


Drive::Drive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

	Requires(&MyTankDrive);
}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {

	// Drives the robot and gets the values for driving forward, backwards, and slowly turning
	MyTankDrive.DriveMotors(MyTankDrive.DriveValues(LJoyChannel, RJoyChannel, RTriggerChannel, LTriggerChannel));

}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
