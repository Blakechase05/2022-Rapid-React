#include "Intake.h"
#include <iostream>

void Intake::setMagState(MagState state) {
  state = _magState;
}

void Intake::updateIntake(double dt) {
  switch(_magState) {
    case MagState::kEmpty: {
      _indexSpeed = _intakeSpeed * 0.5;
      _magSpeed = -0.5;
      break;
    }


    case MagState::kOne: { 
      // only break this if the lim switch is 0, colour sensor is activated or fire button
      break;
    }

    case MagState::kTwo: {
      // Wait to fire button
      break;
    }

    case MagState::kEjectFirst: {
      _indexSpeed = -0.5;
      _intakeSpeed = 0.5;
      break;
    }

    case MagState::kEjectSecond: {
      // Eject the ball and keep in this state until the lower ball hits the lim switch, then break
    }

    case MagState::kManual: {
      _indexSpeed = _indexManualSpeed;
      _magSpeed = _magManualSpeed;
      break;
    }

    default: {
      std::cout << "magazine/intake in manual state lmao something is wrong\n";
      break;
    }

    _intakeSystem.intakeMotor.Set(_intakeSpeed);
    _intakeSystem.magazineIndexMotor.Set(_indexSpeed);
    _intakeSystem.magazineMotor.Set(_magSpeed);

  }
}

void Intake::setIntakeSpeed(double intake) {
  if(_magState != MagState::kEjectFirst) {
    _intakeSpeed = intake;
  }
}

void Intake::setIndexSpeed(double index) {
  _indexManualSpeed = index;
}

void Intake::setMagSpeed(double mag) {
  _magManualSpeed = mag;
}

void Intake::Update(double dt) {
  updateIntake(dt);
}