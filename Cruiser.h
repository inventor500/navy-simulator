#pragma once

#include "Ship.h"

class Cruiser : public Ship {
public:
  Cruiser(std::string name, std::string id, int missles, int maxSpeed);

private:
  int missles;
};
