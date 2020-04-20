#pragma once

#include "Order.h"
#include "time.h"
typedef Timer Atime;
// forward declarations
class Ship;


// concrete orders
class DeployShip : public Order {
public:
  DeployShip(ATime time, std::string id, int x, int y, int heading, int speed);

  // This order can only be executed on Ships
  void execute(Ship& ship) const override;
  
private:
  int x, y, heading, speed;
};


class ChangeShipOrders : public Order {
public:
  ChangeShipOrders(ATime time, std::string id, int heading, int speed);
  void execute(Ship& ship) const override;

private:
  int heading, speed;
};

 
