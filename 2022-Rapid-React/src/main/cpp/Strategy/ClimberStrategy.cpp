#include "strategy/ClimberStrategy.h"

ClimberManualStrategy::ClimberManualStrategy(std::string name, Climber &climber, wml::controllers::SmartControllerGroup &contGroup) : Strategy(name), _climber(climber), _contGroup(contGroup) {
  SetCanBeInterrupted(true);
  SetCanBeReused(true);
  Requires(&climber);
}
