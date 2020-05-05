#pragma once

#include "Order.h"
#include "time.h"

// forward declarations
class Ship;


// concrete orders
class DeployShip : public Order {
public:
  DeployShip(Timer time, std::string id, int x, int y, int heading, int speed);
  void execute(Ship& ship) const override;
  
private:
  int x, y, heading, speed;
};


class ChangeShipOrders : public Order {
public:
  ChangeShipOrders(Timer time, std::string id, int heading, int speed);
  void execute(Ship& ship) const override;

private:
  int heading, speed;
};

 
