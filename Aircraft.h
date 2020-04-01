#pragma once

#include "Movable.h"

// forward declaration
class Ship;

class Aircraft : public Movable {
public:
  Aircraft(std::string name, std::string id, Movable* ship, int maxSpeed, int maxAltitude);

  void takeoff(ATime t, int heading, int speed, int altitude);
  void land(Movable* ship);
  void changeOrders(int heading, int speed, int altitude);
  virtual void accept(const Order& order) override;
  virtual void updatePosition(ATime t);

private:
  Movable* ship;
  int maxAltitude;
};
