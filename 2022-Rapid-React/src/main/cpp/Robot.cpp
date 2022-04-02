#include "Robot.h"

double currentTimeStamp;
double lastTimeStamp;
double dt;

/**
 * Robot boot init, then runs periodic
 */
void Robot::RobotInit() {
  // Init the controllers
  ControlMap::InitSmartControllerGroup(robotmap.contGroup);

  // Make new drivetrain
  drivetrain = new wml::Drivetrain(robotmap.drivetrainSystem.drivetrainConfig, robotmap.drivetrainSystem.gainsVelocity);

  // Set default strategy for drivetrain to manual
  drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotmap.contGroup));
  drivetrain->StartLoop(100);

  // Invert one side of drivetrain so it go straight
  drivetrain->GetConfig().leftDrive.transmission->SetInverted(true);
  drivetrain->GetConfig().rightDrive.transmission->SetInverted(false);

  // Register our systems to be called via strategy
  StrategyController::Register(drivetrain);

  // Make timer
  t = new frc::Timer();
}

void Robot::Update(double dt) {
  StrategyController::Update(dt);
}

void Robot::RobotPeriodic() {
  currentTimeStamp = (double)frc::Timer::GetFPGATimestamp();
  dt = currentTimeStamp - lastTimeStamp;
  
  
  lastTimeStamp = currentTimeStamp;
}

/**
 * Inits and runs auto code
 */
void Robot::AutonomousInit() {
  // Reset Gyro
  drivetrain->GetConfig().gyro->Reset();

  // Start timer
  t->Start();
}

void Robot::AutonomousPeriodic() {
  // If time is less than or equal to 5 seconds, set drivetrain speed to 50%, if over, set 0%
  (double)t->Get() <= 5 ? drivetrain->Set(0.5, 0.5) : drivetrain->Set(0, 0);

}

/**
 * Inits and runs teleop (driver controlled) code
 */
void Robot::TeleopInit() {
  Schedule(drivetrain->GetDefaultStrategy(), true);
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