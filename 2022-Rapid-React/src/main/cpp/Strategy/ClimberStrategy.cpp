#include "Strategy/ClimberStrategy.h"
#include <iostream>

ClimberStrategy::ClimberStrategy(std::string name, Climber &climber, wml::controllers::SmartControllerGroup &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup) {
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
  Requires(&climber); // i hate you
}

void ClimberStrategy::OnUpdate(double dt) {

}

ClimberDisableStrategy::ClimberDisableStrategy(std::string name, Climber &climber) : Strategy(name), _climber(climber) {

}