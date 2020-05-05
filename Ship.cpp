#include "Ship.h"

Ship::Ship(std::string name, std::string id, int maxSpeed)
  :Movable(name, id, maxSpeed) {
  className = "Ship";
}

void Ship::deploy(Timer t, int x, int y, int heading, int speed) {
  position.x = x;
  position.y = y;
  setVelocity(heading, speed);
  Location location(t, position);
  history.push_back(location);
  deployed = true;
  time = t;
}

void Ship::changeOrders(int heading, int speed) {
  setVelocity(heading, speed);
}

void Ship::accept(const Order& order) {
  order.execute(*this);
}

void Ship::updatePosition(Timer t) {
  if (isDeployed()) {
    position += velocity * ((t - time) / 3600.0);
    Location location(t, position);
    history.push_back(location);
  }
  time = t;
}

