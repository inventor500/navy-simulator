#include "Fighter.h"

Fighter::Fighter(std::string name, std::string id, Movable* ship, int maxSpeed, int maxAltitude, int bombs)
  : Aircraft(name,id,ship,maxSpeed,maxAltitude),bombs(bombs) {
  className = "Fighter";
}
