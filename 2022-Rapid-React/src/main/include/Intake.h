#pragma once

#include "controllers/Controller.h"
#include "RobotMap.h"

enum class MagState {
  kEmpty = 0, // no balls
  kOne, // one ball, move to top position
  kTwo, // two balls, full magazine
  kEjectFirst, // 1st ball is wrong colour, eject through shooter
  kEjectSecond, // 2nd ball is wrong colour, eject through intake
  kManual // Manually control the magazine
};

class Intake : public wml::StrategySystem, wml::loops::LoopSystem {
  public:
    Intake(RobotMap::IntakeSystem &intakeSystem, wml::controllers::SmartControllerGroup &contGroup);

    void setMagState(MagState state);

    void updateIntake(double dt);
    void Update(double dt) override;

    void setIntakeSpeed(double intake);
    void setIndexSpeed(double index);
    void setMagSpeed(double mag);

  private:

  MagState _magState{MagState::kEmpty};
  RobotMap::IntakeSystem &_intakeSystem;
  wml::controllers::SmartControllerGroup &_contGroup;

  double _intakeSpeed = 0;
  double _indexSpeed = 0;
  double _magSpeed = 0;

  double _indexManualSpeed = 0;
  double _magManualSpeed = 0;
};