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
  

  //-------- CONTROLS ---------

  // Drivetrain
  inline static const wml::controllers::tAxis leftDrive {driver, wml::controllers::XboxController::kLeftXAxis};
  inline static const wml::controllers::tAxis rightDrive {driver, wml::controllers::XboxController::kRightYAxis};

 // Intake

  // Magazine

  // Shooter

  // Climber


};