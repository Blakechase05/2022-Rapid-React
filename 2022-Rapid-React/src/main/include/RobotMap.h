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

  wml::controllers::XboxController xbox1 {ControlMap::xbox1Port};
  wml::controllers::XboxController xbox2 {ControlMap::xbox2Port};
  wml::controllers::SmartControllerGroup contGroup{xbox1, xbox2};

  struct DrivetrainSystem {
    wml::SparkMax leftMotorF {ControlMap::Drivetrain::leftMotorPortF, wml::SparkMax::MotorType::kBrushed, 0};
    wml::SparkMax leftMotorB {ControlMap::Drivetrain::leftMotorPortB, wml::SparkMax::MotorType::kBrushed, 0};
    
    wml::SparkMax rightMotorF {ControlMap::Drivetrain::rightMotorPortF, wml::SparkMax::MotorType::kBrushed, 0};
    wml::SparkMax rightMotorB {ControlMap::Drivetrain::rightMotorPortB, wml::SparkMax::MotorType::kBrushed, 0};

    wml::actuators::MotorVoltageController leftMotors = wml::actuators::MotorVoltageController::Group(leftMotorF, leftMotorB);
    wml::actuators::MotorVoltageController rightMotors = wml::actuators::MotorVoltageController::Group(rightMotorF, rightMotorB);

    wml::Gearbox LGearbox {&leftMotors, &leftMotorF};
    wml::Gearbox RGearbox {&rightMotors, &rightMotorF};

    wml::sensors::NavX NavX {frc::SPI::Port::kMXP};
    wml::sensors::NavXGyro gyro {NavX.Angular(wml::sensors::AngularAxis::YAW)};

    wml::DrivetrainConfig drivetrainConfig{LGearbox, RGearbox, &gyro, ControlMap::Drivetrain::trackWidth, ControlMap::Drivetrain::trackDepth, ControlMap::Drivetrain::wheelRadius, ControlMap::Drivetrain::mass};
    wml::control::PIDGains gainsVelocity{"Drivetrain Velocity", 1};
    wml::Drivetrain drivetrain{drivetrainConfig, gainsVelocity};

  }; DrivetrainSystem drivetrainSystem;
};
