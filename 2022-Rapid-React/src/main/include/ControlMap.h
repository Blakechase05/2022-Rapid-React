#pragma once

#include <vector>
#include "controllers/Controllers.h"

struct ControlMap {
  
  static constexpr int driver = 0;
  static constexpr int coDriver = 1;

  static void InitSmartControllerGroup(wml::controllers::SmartControllerGroup &contGroup) {}

  //-------- VALUES ---------

  static constexpr int xbox1Port = driver;
  static constexpr int xbox2Port = coDriver;
  
  static constexpr double xboxDeadzone = 0.15;
  static constexpr double triggerDeadzone = 0.05;

  struct Drivetrain {
    static constexpr double trackWidth = 0.56;
    static constexpr double trackDepth = 0.60;
    static constexpr double wheelRadius = 0.0762;
    static constexpr double mass = 50;

    static constexpr int leftMotorPortF = 99;
    static constexpr int leftMotorPortB = 99;

    static constexpr int rightMotorPortF = 99;
    static constexpr int rightMotorPortB = 99;

    static constexpr double maxDrivetrainPower = 0.8; // never trust the drivers
  };

  struct Intake {
    // Intake Motor Ports
    static constexpr int intakeMotorPort = 99;
    static constexpr int indexWheelMotorPort = 99;
    static constexpr int magazineMotorPort = 99;
  };

  struct Shooter {
    // Shooter Motor Ports
    static constexpr int shooterMotorPort = 99;
  };

  struct Climber {
    // Climber Motor Ports
    static constexpr int leftClimbMotorPort = 99;
    static constexpr int rightClimbMotorPort = 99;

    // Max Power
    static constexpr double maxClimbPower = 0.5; // Never trust the codriver
  };
  

  //-------- CONTROLS ---------

  // Drivetrain
  inline static const wml::controllers::tAxis leftDrive {driver, wml::controllers::XboxController::kLeftXAxis};
  inline static const wml::controllers::tAxis rightDrive {driver, wml::controllers::XboxController::kRightYAxis};

  // Intake
  inline static const wml::controllers::tAxis intakeInOut {coDriver, wml::controllers::XboxController::kRightYAxis};
  inline static const wml::controllers::tButton magUpDown {coDriver, wml::controllers::XboxController::kBottomRight};

  // Shooter
  inline static const wml::controllers::tButton shootStartStop {coDriver, wml::controllers::XboxController::kBumperRight};

  // Climber
  inline static const wml::controllers::tButton climberSwitch {coDriver, wml::controllers::XboxController::kA};
  inline static const wml::controllers::tAxis climberUpDown {coDriver, wml::controllers::XboxController::kLeftYAxis};
  inline static const wml::controllers::tButton autoClimb {coDriver, wml::controllers::XboxController::kY};

};