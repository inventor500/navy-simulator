#include "Cruiser.h"

Cruiser::Cruiser(std::string name, std::string id, int missles, int maxSpeed)
  :Ship(name,id,maxSpeed), missles(missles) {
  className = "Cruiser";
}
