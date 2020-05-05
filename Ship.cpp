#include "Ship.h"

Ship::Ship(std::string name, std::string id, int maxSpeed)
  :Movable(name, id, maxSpeed) {
  className = "Ship";
}

void Ship::deploy(ATime t, int x, int y, int heading, int speed) {
  // place the ship at (x, y) with given heading and speed
  // remember to keep track of the ships history of locations
  position.x = x;
  position.y = y;
  setVelocity(heading, speed);
  //updatePosition(t);
  Location location(t, position);
  history.push_back(location);
  deployed = true;
  time = t;
}

void Ship::changeOrders(int heading, int speed) {
  setVelocity(heading, speed);
}

void Ship::accept(const Order& order) {
  // For use later, keep commented
  order.execute(*this);
}

void Ship::updatePosition(ATime t) {
  // update the ship's current position to the given ATime t
  //keep track of history here
  if (isDeployed()) {
    position += velocity * ((t - time) / 3600.0);
    Location location(t, position);
    history.push_back(location);
  }
  time = t;
}

