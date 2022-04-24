#include "Strategy/ClimberStrategy.h"
#include <iostream>

ClimberStrategy::ClimberStrategy(std::string name, Climber &climber, wml::controllers::SmartControllerGroup &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup) {
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
  Requires(&climber); // i hate you
}

void ClimberStrategy::OnUpdate(double dt) {
  if(_contGroup.Get(ControlMap::climberSwitch, wml::controllers::XboxController::ONFALL)) {
    if(_climberToggle) {
      _climberToggle = true;
    } else {
      _climberToggle = false;
    }
  }

  if(_climberToggle) {
    _climber.setState(ClimberState::kDeployed);
  } else {
    _climber.setState(ClimberState::kStowed);
  }
}

ClimberDisableStrategy::ClimberDisableStrategy(std::string name, Climber &climber) : Strategy(name), _climber(climber) {
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
  Requires(&climber);
}

void ClimberDisableStrategy::OnUpdate(double dt) {
  _climber.disabledClimber();
}