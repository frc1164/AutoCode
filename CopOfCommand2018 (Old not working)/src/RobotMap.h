/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Subsystems/TankDrive.h"
//#include <XboxController.h>
//#include <Joystick.h>

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

constexpr int kLeft1 = 2;
constexpr int kLeft2 = 3;
constexpr int kRight1 = 1;
constexpr int kRight2 = 4;

constexpr int LJoyChannel = 1;
constexpr int RJoyChannel = 3;
constexpr int RTriggerChannel = 0;
constexpr int LTriggerChannel = 2;

// layout for Xbox controller
constexpr int LXboxStick = 0;
constexpr int RXboxStick = 4;
constexpr int LXboxTrigger = 2;
constexpr int RXboxTrigger = 3;

//Encoder conversion factor
constexpr double kEncoder = 22.38535;

static TankDrive MyTankDrive;

