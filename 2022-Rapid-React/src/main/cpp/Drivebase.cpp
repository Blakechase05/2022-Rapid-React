#include "Drivebase.h"

DrivetrainManual::DrivetrainManual(std::string name, wml::Drivetrain &drivetrain, wml::controllers::SmartControllerGroup &contGroup) : Strategy(name), _drivetrain(drivetrain), _contGroup(contGroup) {
  Requires(&drivetrain);
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
}

void DrivetrainManual::OnUpdate(double dt) {
  double leftPower = fabs(_contGroup.Get(ControlMap::leftDrive)) > ControlMap::xboxDeadzone ? _contGroup.Get(ControlMap::leftDrive) : 0;
  double rightPower = fabs(_contGroup.Get(ControlMap::rightDrive)) > ControlMap::xboxDeadzone ? _contGroup.Get(ControlMap::rightDrive) : 0;

  leftPower *= ControlMap::Drivetrain::maxDrivetrainPower; // never trust the drivers
  rightPower *= ControlMap::Drivetrain::maxDrivetrainPower;

  _drivetrain.Set(leftPower, rightPower);
}