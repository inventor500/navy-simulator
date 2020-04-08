#pragma once

#include "Aircraft.h"

class Fighter : public Aircraft {
public:
  Fighter(std::string name, std::string id, Movable* ship, int maxSpeed, int maxAltitude, int bombs);

private:
  int bombs;
};
