#pragma once

#include "Climber.h"
#include "controllers/Controller.h"

class ClimberManualStrategy : wml::Strategy {
  public:
    ClimberManualStrategy(std::string name, Climber &climber, wml::controllers::SmartControllerGroup &contGroup);

    void OnUpdate(double dt) override;

  private:
    Climber &_climber;
    wml::controllers::SmartControllerGroup &_contGroup;
};


class ClimberAutoStrategy : wml::Strategy {
  public:
    void OnUpdate(double dt) override;

  private:
    Climber &_climber;
    wml::controllers::SmartControllerGroup &_contGroup;
};


class ClimberDisableStrategy : wml::Strategy {
  public:
    void OnUpdate(double dt) override;

  private:
    Climber &_climber;
};