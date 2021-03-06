#pragma once 

#include "Climber.h"
#include "strategy/Strategy.h"

using Controllers = wml::controllers::SmartControllerGroup;

class ClimberStrategy : public wml::Strategy {
 public:
  ClimberStrategy(std::string name, Climber &climber, Controllers &contGroup);

  void OnUpdate(double dt) override;
 private:
  bool _climberToggle = false;
  Climber &_climber;
  Controllers &_contGroup;

};


class ClimberDisableStrategy : public wml::Strategy {
 public:
  ClimberDisableStrategy(std::string name, Climber &climber);

  void OnUpdate(double dt);
 private:
  bool _climberToggle = false;

  Climber &_climber;

};