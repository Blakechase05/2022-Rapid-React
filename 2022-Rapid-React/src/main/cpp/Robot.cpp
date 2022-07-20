#include "Robot.h"

using namespace frc;
using namespace wml;

double currentTimeStamp;
double lastTimeStamp;
double dt;


/**
 * Robot boot init, then runs periodic
 */
void Robot::RobotInit() {
  // RobotMap::IntakeSystem::colourMatcher.AddColorMatch(RobotMap::IntakeSystem::kBlueTarget);
  // RobotMap::IntakeSystem::colourMatcher.AddColorMatch(RobotMap::IntakeSystem::kRedTarget);

  // Init the controllers
  ControlMap::InitSmartControllerGroup(robotMap.contGroup);

  intake = new Intake(robotMap.intakeSystem, robotMap.contGroup);
  intake->SetDefault(std::make_shared<IntakeStrategy>("Intake Manual Strategy", *intake, robotMap.contGroup));
  intake->StartLoop(100);

  climber = new Climber(robotMap.climberSystem, robotMap.contGroup);
  climber->SetDefault(std::make_shared<ClimberStrategy>("Climber Manual Strategy", *climber, robotMap.contGroup));
  climber->StartLoop(100);

  robotMap.climberSystem.leftClimbMotor.SetInverted(false);
  robotMap.climberSystem.rightClimbMotor.SetInverted(false);

  // Make new drivetrain
  drivetrain = new wml::Drivetrain(robotMap.drivetrainSystem.drivetrainConfig, robotMap.drivetrainSystem.gainsVelocity);

  // Set default strategy for drivetrain to manual
  drivetrain->SetDefault(std::make_shared<DrivetrainManual>("Drivetrain Manual", *drivetrain, robotMap.contGroup));
  drivetrain->StartLoop(100);

  // Invert one side of drivetrain so it go straight
  drivetrain->GetConfig().leftDrive.transmission->SetInverted(true);
  drivetrain->GetConfig().rightDrive.transmission->SetInverted(false);

  // Register our systems to be called via strategy
  StrategyController::Register(drivetrain);
  StrategyController::Register(climber);
  StrategyController::Register(intake);

  // Make timer
  // t = new frc::Timer();
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
  // t->Start();
}

void Robot::AutonomousPeriodic() {
  // If time is less than or equal to 5 seconds, set drivetrain speed to 0.5, if over, set 0
  // (double)t->Get() <= 5 ? drivetrain->Set(0.5, 0.5) : drivetrain->Set(0, 0);

}

/**
 * Inits and runs teleop (driver controlled) code
 */
void Robot::TeleopInit() {
  Schedule(drivetrain->GetDefaultStrategy(), true);
  Schedule(climber->GetDefaultStrategy(), true);
  Schedule(intake->GetDefaultStrategy(), true);
}

void Robot::TeleopPeriodic() {
  climber->updateClimber(dt);

}

/**
 * Runs instead of RobotInit and RobotPeriodic
 * after the robot has been disabled at least once
 */
void Robot::DisabledInit() {
  InterruptAll(true);
  Schedule(std::make_shared<ClimberDisableStrategy>("Climber Disable Strategy", *climber));
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