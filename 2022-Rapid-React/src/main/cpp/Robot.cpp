#include "Robot.h"

double currentTimeStamp;
double lastTimeStamp;
double dt;

/**
 * Robot boot init, then runs periodic
 */
void Robot::RobotInit() {
  // Make timer
  t = new frc::Timer();
}

void Robot::Update(double dt) {}

void Robot::RobotPeriodic() {
  currentTimeStamp = (double)frc::Timer::GetFPGATimestamp();
  dt = currentTimeStamp - lastTimeStamp;
  
  
  lastTimeStamp = currentTimeStamp;
}

/**
 * Inits and runs auto code
 */
void Robot::AutonomousInit() {
  // Start timer
  t->Start();
}

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