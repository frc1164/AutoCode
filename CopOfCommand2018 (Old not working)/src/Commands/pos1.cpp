#include "pos1.h"
#include <DriverStation.h>

pos1::pos1() {
	char gameData [3];
/*
	if(gameData[0] == 'L') {
	ScoreSwitch(false);
} 	else if (gameData[1] == 'L'){
	ScoreScale(false);
	} else{
	AutoRun();
	}*/
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void pos1::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void pos1::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool pos1::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void pos1::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void pos1::Interrupted() {

}
