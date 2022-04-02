#include "Robot.h"

/**
 * Robot boot init, then runs periodic
 */
void Robot::RobotInit() {
  //Init the controllers
  // ControlMap::InitSmartControllerGroup(robotmap.contGroup);

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
void Robot::TeleopInit() {

}
void Robot::TeleopPeriodic() {}

/**
 * Runs instead of RobotInit and RobotPeriodic
 * after the robot has been disabled at least once
 */
void Robot::DisabledInit() {
  InterruptAll(true);

}
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