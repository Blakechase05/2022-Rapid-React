#include "Robot.h"

const int deadzone = 0.15;

/*
** Xbox Controllers
*/ 
wml::controllers::XboxController xbox1{99}; // Driver Controller
wml::controllers::XboxController xbox2{99}; // Codriver Controller

/**
 * Drivebase Motor Controllers
 */
wml::SparkMax driveLeftFront {99, wml::SparkMax::MotorType::kBrushed, 0};
wml::SparkMax driveLeftBack {99, wml::SparkMax::MotorType::kBrushed, 0};

wml::SparkMax driveRightFront {99, wml::SparkMax::MotorType::kBrushed, 0};
wml::SparkMax driveRightBack {99, wml::SparkMax::MotorType::kBrushed, 0};


/**
 * Robot boot init, then runs periodic
 */
void Robot::RobotInit() {
  
}
void Robot::RobotPeriodic() {}

/**
 * Inits and runs auto code
 */
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

/**
 * Inits and runs teleop (driver controlled) code
 */
void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {}

/**
 * Runs instead of RobotInit and RobotPeriodic
 * after the robot has been disabled at least once
 */
void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

/**
 * Test mode... for testing
 */
void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif