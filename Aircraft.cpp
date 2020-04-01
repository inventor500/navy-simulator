#include "Aircraft.h"

Aircraft::Aircraft(std::string name, std::string id, Movable* ship, int maxSpeed, int maxAltitude)
  :Movable(name, id, maxSpeed), ship(ship), maxAltitude(maxAltitude) {
  className = "Aircraft";
}

void Aircraft::takeoff(ATime t, int heading, int speed, int newAltitude) {
  // take off from the ship's position with given heading, speed, altitude
  // remember to "detach" yourself from the ship: ship = nullptr;
}

void Aircraft::land(Movable* newShip) {
  // attach yourself to this ship
}

void Aircraft::changeOrders(int heading, int speed, int newAltitude) {
  // update velocity
}

void Aircraft::accept(const Order& order) {
  // will be used in the future, leave commented out
  //order.execute(*this);
}

void Aircraft::updatePosition(ATime t) {
  // you have to handle two cases here:
  // 1. flying in a straight line (when not attached to a ship)
  // 2. landing (when attached to a ship)
  // when landing always update your velocity to point to the ship's
  // current location
}

