#pragma once

#include <iostream>
#include "controllers/Controllers.h"
#include "RobotMap.h"

class DrivetrainManual : public wml::Strategy {
  public:
    DrivetrainManual(std::string name, wml::Drivetrain &drivetrain, wml::controllers::SmartControllerGroup &contGroup);
  
    void OnUpdate(double dt) override;

  private:
    wml::Drivetrain &_drivetrain;
    wml::controllers::SmartControllerGroup &_contGroup;
};