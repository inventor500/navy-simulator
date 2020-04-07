#include "Ship.h"

Ship::Ship(std::string name, std::string id, int maxSpeed)
  :Movable(name, id, maxSpeed) {
  className = "Ship";
}

void Ship::deploy(ATime t, int x, int y, int heading, int speed) {
  // place the ship at (x, y) with given heading and speed
  // remember to keep track of the ships history of locations
  Location.x = x;
  Location.y = y;
  setVelocity(heading, speed);
  updatePosition(t);
}

void Ship::changeOrders(int heading, int speed) {
  setVelocity(heading, speed);
}

void Ship::accept(const Order& order) {p
  // For use later, keep commented
  //order.execute(*this);
}

void Ship::updatePosition(ATime t) {
  // update the ship's current position to the given ATime t
  //keep track of history here
  if (isDeployed()) {
    position.x += velocity.x * (t - time);
    position.y += velocity.y * (t - time);
    Location location(t, position);
    history.push_back(position);
    time = t;
  }
}

