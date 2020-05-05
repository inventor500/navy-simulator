#pragma once

#include "Movable.h"

class Ship : public Movable {
public:
  Ship(std::string name, std::string id, int maxSpeed);

  void deploy(Timer t, int x, int y, int heading, int speed);
  void changeOrders(int heading, int speed);
  virtual void accept(const Order& order) override;
  virtual void updatePosition(Timer t) override;
};
