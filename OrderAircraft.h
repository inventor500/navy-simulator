#pragma once

#include "Order.h"
#include "time.h"
typedef Timer Atime;
// forward declaration
class Movable;
class Aircraft;


// concrete orders
class DeployAircraft : public Order {
public:
  DeployAircraft(ATime time, std::string id, int heading, int speed, int altitude);

  // This order only can be executed on Aircraft
  void execute(Aircraft& aircraft) const override;
  
private:
  int heading, speed, altitude;
};


class LandAircraft : public Order {
public:
  LandAircraft(ATime time, std::string aircraftID, Movable* ship);
  void execute(Aircraft& aircraft) const override;
  
private:
  Movable* ship;
};


class ChangeAircraftOrders : public Order {
public:
  ChangeAircraftOrders(ATime time, std::string id, int heading, int speed, int altitude);
  void execute(Aircraft& aircraft) const override;

private:
  int heading, speed, altitude;
};

