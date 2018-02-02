#include "Pos3.h"
#include <DriverStation.h>

Pos3::Pos3() {
	char gameData [3];
/*	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if(gameData[0] == 'R') {
		ScoreSwitch(true);
	} else if (gameData[1] == 'R'){
		ScoreScale (true);
	} else{
		AutoRun();
	} */
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Pos3::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Pos3::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Pos3::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Pos3::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Pos3::Interrupted() {

}
