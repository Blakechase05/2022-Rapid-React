#include "Climber.h"
#include <iostream>

Climber::Climber(RobotMap::ClimberSystem &climberSystem, wml::controllers::SmartControllerGroup &contGroup) : _climberSystem(climberSystem), _contGroup(contGroup) {}


void Climber::Update(double dt) {
  updateClimber(dt);
}

void Climber::updateClimber(double dt) {
  switch(_state) {
    case ClimberState::kDeployed: {
      double climberPower = fabs(_contGroup.Get(ControlMap::climberUpDown)) > ControlMap::triggerDeadzone ? _contGroup.Get(ControlMap::magUpDown) : 0;

      climberPower *= ControlMap::Climber::maxClimbPower;

      _climberSystem.leftClimbMotor.Set(climberPower);
      _climberSystem.rightClimbMotor.Set(climberPower);

      break;
    }

    case ClimberState::kStowed: {
      _climberSystem.leftClimbMotor.Set(0);
      _climberSystem.rightClimbMotor.Set(0);

      break;
    }

    default: {
      std::cout << "Climber is in default state, something is wrong\n";
      break;
    }
  }
}

void Climber::disabledClimber() {
  _state = ClimberState::kStowed;
}

void Climber::setState(ClimberState _climberState) {
  _state = _climberState;
}