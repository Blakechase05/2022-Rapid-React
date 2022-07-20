#pragma once

// Include Subsystem Files
#include "RobotMap.h"
#include "Drivebase.h"
#include "Intake.h"
#include "Shooter.h"
#include "Climber.h"

// Include Strategy Files
#include "Strategy/IntakeStrategy.h"
#include "Strategy/ShooterStrategy.h"
#include "Strategy/ClimberStrategy.h"

class Robot : public frc::TimedRobot, protected wml::StrategyController, protected wml::NTProvider, protected wml::loops::LoopSystem {
  public:
    void RobotInit() override;
    void RobotPeriodic() override;

    void AutonomousInit() override;
    void AutonomousPeriodic() override;

    void TeleopInit() override;
    void TeleopPeriodic() override;

    void DisabledInit() override;
    void DisabledPeriodic() override;

    void TestInit() override;
    void TestPeriodic() override;

    void Update(double dt) override;

  private:
    RobotMap robotMap;

    // Subsystems :]
    wml::Drivetrain *drivetrain;
    Climber *climber;
    Intake *intake;
    
    // frc::Timer* t;
};