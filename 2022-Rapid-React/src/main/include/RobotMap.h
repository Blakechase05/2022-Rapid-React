#pragma once

// General
#include <string>
#include <stdint.h>


// FRC/WPI
#include <frc/Timer.h>
#include <frc/TimedRobot.h>
#include <frc/DoubleSolenoid.h>
#include <frc/GenericHID.h>

#include <cameraserver/CameraServer.h>

#include <frc/DriverStation.h>

#include <frc/SpeedControllerGroup.h>
#include <frc/PowerDistribution.h>
#include <frc/Servo.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/AnalogInput.h>
#include <networktables/NetworkTableInstance.h>

#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/fs.h>
#include <networktables/NetworkTableInstance.h>
#include <wpi/SmallString.h>

// WML
#include <WMLCtre.h>
#include <actuators/BinaryServo.h>
#include <NTProvider.h>
#include <actuators/DoubleSolenoid.h>
#include <actuators/VoltageController.h>
#include <Drivetrain.h>
#include <sensors/Encoder.h>
#include <sensors/LimitSwitch.h>
#include <sensors/NavX.h>
#include <sensors/PressureSensor.h>
#include <control/PIDController.h>
#include <MotionProfiling.h>
#include <Toggle.h>

#include <devices/StateDevice.h>
#include <strategy/StrategyController.h>
#include <strategy/MPStrategy.h>
#include <control/MotorFilters.h>
#include <Gearbox.h>
#include <strategy/Strategy.h>
#include <sensors/BinarySensor.h>
#include <rev/CANSparkMax.h>

// WML Rev
#include <WMLRev.h>

// Include Local Files
#include "ControlMap.h"

// wml::physics::DcMotor mNEO { 12.0, wml::physics::DcMotor::rpm2rads(5880), 1.3, 166, 3.36 };
// wml::physics::DcMotor mFalcon500 { 12.0, wml::physics::DcMotor::rpm2rads(6380), 1.5, 257, 4.69 };

struct RobotMap {

  // Controllers Definitions (Xbox[1/2] are Left/Right Respectively 
  wml::controllers::XboxController xbox1 {ControlMap::xbox1Port}; // LEFT STICK
  wml::controllers::XboxController xbox2 {ControlMap::xbox2Port}; // RIGHT STICK
  // Creates group to place the controllers into
  wml::controllers::SmartControllerGroup contGroup{xbox1, xbox2};

  struct DrivetrainSystem {
    // L/R DRIVE BASE MOTORS FRONT AND BACK
    wml::SparkMax leftMotorF {ControlMap::Drivetrain::leftMotorPortF, wml::SparkMax::MotorType::kBrushed, 0}; // LEFT DRIVE MOTOR FRONT
    wml::SparkMax leftMotorB {ControlMap::Drivetrain::leftMotorPortB, wml::SparkMax::MotorType::kBrushed, 0}; // LEFT DRIVE MOTOR BACK
    
    wml::SparkMax rightMotorF {ControlMap::Drivetrain::rightMotorPortF, wml::SparkMax::MotorType::kBrushed, 0}; // RIGHT DRIVE MOTOR FRONT
    wml::SparkMax rightMotorB {ControlMap::Drivetrain::rightMotorPortB, wml::SparkMax::MotorType::kBrushed, 0}; // RIGHT DRIVE MOTOR BACK

    // MOTOR GROUPS
    wml::actuators::MotorVoltageController leftMotors = wml::actuators::MotorVoltageController::Group(leftMotorF, leftMotorB);    // MOTOR GROUP L
    wml::actuators::MotorVoltageController rightMotors = wml::actuators::MotorVoltageController::Group(rightMotorF, rightMotorB); // MOTOR GROUP R

    // GEAR BOXES
    wml::Gearbox LGearbox {&leftMotors, &leftMotorF};   // Left Gear Box
    wml::Gearbox RGearbox {&rightMotors, &rightMotorF}; // Right Gear Box

    wml::sensors::NavX NavX {frc::SPI::Port::kMXP};
    wml::sensors::NavXGyro gyro {NavX.Angular(wml::sensors::AngularAxis::YAW)};

    wml::DrivetrainConfig drivetrainConfig{LGearbox, RGearbox, &gyro, ControlMap::Drivetrain::trackWidth, ControlMap::Drivetrain::trackDepth, ControlMap::Drivetrain::wheelRadius, ControlMap::Drivetrain::mass};
    wml::control::PIDGains gainsVelocity{"Drivetrain Velocity", 1};
    wml::Drivetrain drivetrain{drivetrainConfig, gainsVelocity};

  }; DrivetrainSystem drivetrainSystem;

  struct IntakeSystem {
    wml::SparkMax intakeMotor {ControlMap::Intake::intakeMotorPort, wml::SparkMax::MotorType::kNEO, 42};
    wml::SparkMax indexWheelMotor {ControlMap::Intake::indexWheelMotorPort, wml::SparkMax::MotorType::kBrushless, 42};
    wml::SparkMax magazineMotor {ControlMap::Intake::magazineMotorPort, wml::SparkMax::MotorType::kBrushless, 42};

    // Limit Switch
    wml::sensors::LimitSwitch limitSwitch {99, false, "Funny Switch"};

  }; IntakeSystem intakeSystem;

  struct ShooterSystem {
    wml::SparkMax shooterMotor {ControlMap::Shooter::shooterMotorPort, wml::SparkMax::MotorType::kBrushless, 2048};

  }; ShooterSystem shooterSystem;

  struct ClimberSystem {
    wml::SparkMax leftClimbMotor {ControlMap::Climber::leftClimbMotorPort ,wml::SparkMax::MotorType::kNEO , 42};
    wml::SparkMax rightClimbMotor {ControlMap::Climber::rightClimbMotorPort, wml::SparkMax::MotorType::kNEO, 42};

  }; ClimberSystem climberSystem;

};
