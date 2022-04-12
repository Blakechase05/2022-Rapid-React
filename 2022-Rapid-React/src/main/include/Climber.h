#pragma once

#include "RobotMap.h"
#include "controllers/Controller.h"

enum class ClimberState {
  kStowed = 0,
  kDeployed,
  kAuto
};

class Climber : public wml::StrategyController, public wml::loops::LoopSystem {
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