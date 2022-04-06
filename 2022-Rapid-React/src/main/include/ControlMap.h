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

  struct Swerve {
    static constexpr double trackWidth = 0.56;
    static constexpr double trackDepth = 0.60;
    static constexpr double wheelRadius = 0.0762;
    static constexpr double mass = 50;

    static constexpr int frontLeftDrivePort = 99;
    static constexpr int frontLeftSteerPort = 99;
    
    static constexpr int frontRightDrivePort = 99;
    static constexpr int frontRightSteerPort = 99;

    static constexpr int backLeftDrivePort = 99;
    static constexpr int backLeftSteerPort = 99;
    
    static constexpr int backRightDrivePort = 99;
    static constexpr int backRightSteerPort = 99;
    
    static constexpr double swerveMaxPower = 0.8; // never trust the drivers
  };

  //-------- CONTROLS ---------

  // Swerve
  inline static const wml::controllers::tAxis fwdDrive {driver, wml::controllers::XboxController::kLeftXAxis};
  inline static const wml::controllers::tAxis strDrive {driver, wml::controllers::XboxController::kLeftYAxis};
  inline static const wml::controllers::tAxis rotateDrive {driver, wml::controllers::XboxController::kRightXAxis};

 // Intake

  // Magazine

  // Shooter

  // Climber


};