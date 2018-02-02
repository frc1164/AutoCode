/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>
#include <DriverStation.h>

#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"

#include "RobotMap.h"
#include "Commands/ScoreScale.h"
#include "Commands/ScoreSwitch.h"
#include "Commands/AutoRun.h"
#include "Commands/MidSwitch.h"
#include "Commands/pos1.h"
#include "Commands/Pos2.h"
#include "Commands/Pos3.h"

//This is some stuff that eric added

class Robot : public frc::TimedRobot {
public:

	//TankDrive Robot::MyTankDrive;

	void RobotInit() override {
		//m_chooser.AddDefault("Pos1", &m_defaultAuto);
		//m_chooser.AddObject("Pos 2", &m_myAuto);
		//m_chooser.AddObject("Pos 3", &);

		m_chooser.AddDefault("Pos1", &m_pos1);
		m_chooser.AddObject("Pos 2", &m_pos2);
		m_chooser.AddObject("Pos 3", &m_Pos3);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
	}

	/**
	 * This function is called once each time the robot enters Disabled
	 * mode.
	 * You can use it to reset any subsystem information you want to clear
	 * when
	 * the robot is disabled.
	 */
	void DisabledInit() override {}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to
	 * the
	 * chooser code above (like the commented example) or additional
	 * comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
	/*	std::string autoSelected = frc::SmartDashboard::GetString(
				"Pos1", "Pos2", "Pos3");
		char gameData [3];
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

		if (autoSelected == "Pos1") {
			pos1;
		} else if (autoSelected == "Pos2") {
			Pos2;
		} else {
			Pos3;

		}*/

		m_autonomousCommand = m_chooser.GetSelected();

		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Cancel();
			m_autonomousCommand = nullptr;
		}
	}

	void TeleopPeriodic() override { frc::Scheduler::GetInstance()->Run(); }

	void TestPeriodic() override {}

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;

	pos1 m_pos1;
	Pos2 m_pos2;
	Pos3 m_Pos3;

	frc::SendableChooser<frc::Command*> m_chooser;
};
START_ROBOT_CLASS(Robot);
