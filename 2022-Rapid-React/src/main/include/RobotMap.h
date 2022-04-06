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

// Swerve
#include <

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

  class SwerveSystem {
    // Front left
    wml::SparkMax frontLeftDrive {ControlMap::Swerve::frontLeftDrivePort , wml::SparkMax::MotorType::kNEO, 42};
    wml::SparkMax frontLeftSteer {ControlMap::Swerve::frontLeftSteerPort , wml::SparkMax::MotorType::kNEO, 42};

    // Front right
    wml::SparkMax frontRightDrive {ControlMap::Swerve::frontRightDrivePort , wml::SparkMax::MotorType::kNEO, 42};
    wml::SparkMax frontRightSteer {ControlMap::Swerve::frontRightSteerPort, wml::SparkMax::MotorType::kNEO, 42};

    // Back left
    wml::SparkMax backLeftDrive {ControlMap::Swerve::backLeftDrivePort , wml::SparkMax::MotorType::kNEO, 42};
    wml::SparkMax backLeftSteer {ControlMap::Swerve::backLeftSteerPort , wml::SparkMax::MotorType::kNEO, 42};

    // Back right
    wml::SparkMax backRightDrive {ControlMap::Swerve::backRightDrivePort , wml::SparkMax::MotorType::kNEO, 42};
    wml::SparkMax backRightSteer {ControlMap::Swerve::backRightSteerPort , wml::SparkMax::MotorType::kNEO, 42};

    wml::sensors::NavX navX{frc::SPI::Port::kMXP};
    wml::sensors::NavXGyro gyro{navX.Angular(wml::sensors::AngularAxis::YAW)};

    // Absolute Encoder

    // Turning PID

    // Encoder stuff
    bool absEncoderReversed;
    double absEncoderOffsetRad = 0;

  }; SwerveSystem swerveSystem;

};
