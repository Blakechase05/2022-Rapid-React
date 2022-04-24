#pragma once

#include <iostream>
#include "controllers/Controller.h"
#include "RobotMap.h"

enum class ClimberState {
  kStowed = 0,
  kDeployed
};

class Climber : public wml::StrategySystem, public wml::loops::LoopSystem {
  public:
    Climber(RobotMap::ClimberSystem &climberSystem, wml::controllers::SmartControllerGroup &contGroup);

    void updateClimber(double dt);
    void disabledClimber();
    void setState(ClimberState _climberState);

    void Update(double dt) override;

  private:
    ClimberState _state{ClimberState::kStowed};
    RobotMap::ClimberSystem &_climberSystem;
    wml::controllers::SmartControllerGroup &_contGroup;

};