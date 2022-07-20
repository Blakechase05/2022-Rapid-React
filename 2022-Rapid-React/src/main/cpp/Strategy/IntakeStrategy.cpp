#include "Strategy/IntakeStrategy.h"

#include <iostream>

IntakeStrategy::IntakeStrategy(std::string name, Intake &intake, Controllers &contGroup) : Strategy(name), _intake(intake), _contGroup(contGroup) {
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
  Requires(&intake);
}

void IntakeStrategy::OnUpdate(double dt) {
  double intakePower = fabs(_contGroup.Get(ControlMap::intakeInOut)) > ControlMap::triggerDeadzone ? _contGroup.Get(ControlMap::intakeInOut) : 0;
  intakePower *= ControlMap::Intake::maxIntakePower;

  _intake.setIntakeSpeed(intakePower);

  double indexPower = fabs(_contGroup.Get(ControlMap::indexManualSpin)) > ControlMap::triggerDeadzone ? _contGroup.Get(ControlMap::indexManualSpin) : 0;
  _intake.setIndexSpeed(indexPower);

  double magPower = fabs(_contGroup.Get(ControlMap::magManualUp)) > ControlMap::triggerDeadzone ? _contGroup.Get(ControlMap::magManualUp) : 0;
  _intake.setMagSpeed(magPower);

  // lim switch no colour
  
  // right colour no lim switch

  // wrong colour no lim switch

  // right colour and lim switch

  // wrong colour and lim switch

}