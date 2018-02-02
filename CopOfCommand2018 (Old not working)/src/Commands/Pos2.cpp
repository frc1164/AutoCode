#include "Pos2.h"
#include <DriverStation.h>

Pos2::Pos2() {
	char gameData [3];
	/*gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if(gameData[0] == 'R'){
		MidSwitch();
	} else {
		AutoRun();
	}*/
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Pos2::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Pos2::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Pos2::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Pos2::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Pos2::Interrupted() {

}
