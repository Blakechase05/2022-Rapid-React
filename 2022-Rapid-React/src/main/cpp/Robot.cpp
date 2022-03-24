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
  /**
   * Set one side inverted
   */
  driveLeftFront.SetInverted(true);
  driveLeftBack.SetInverted(true);

  driveRightFront.SetInverted(false);
  driveRightBack.SetInverted(false);

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
void Robot::TeleopPeriodic() {
  /**
   * Make variables that we can continuosly add the controller throttle values to
   */
  double driveLeftSpeed = 0;
  double driveRightSpeed = 0;

  /**
   * If the controller values exceed the deadzone,
   * add that value to the speed of the driveSpeed variable
   */
  if(xbox1.GetAxis(xbox1.kLeftThrottle) >= deadzone) {
    driveLeftSpeed += xbox1.GetAxis(xbox1.kLeftThrottle);
  }

  if(xbox1.GetAxis(xbox1.kRightThrottle) >= deadzone) {
    driveRightSpeed += xbox1.GetAxis(xbox1.kRightThrottle);
  }

  /**
   * Set the actual motor controllers to turn the motors at that speed
   */
  driveLeftFront.Set(driveLeftSpeed);
  driveLeftBack.Set(driveLeftSpeed);
  
  driveRightFront.Set(driveRightSpeed);
  driveRightBack.Set(driveRightSpeed);
}

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