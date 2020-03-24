#include "Movable.h"
#include <cmath>
#include <iostream>

Movable::Movable(std::string name, std::string id, int maxSpeed)
  :className("Movable"), name(name), id(id), deployed(false),
   heading(0), speed(0), maxSpeed(maxSpeed) {}

std::string Movable::getClassName() const {
  return className;
}

std::string Movable::getName() const {
  return name;
}

std::string Movable::getID() const {
  return id;
}

bool Movable::isDeployed() const {
  return deployed;
}

Vector3D Movable::getPosition() const {
  return position;
}

const LocationHistory& Movable::getHistory() const {
  return history;
}

void Movable::setVelocity(int newHeading, int newSpeed) {
  // check newSpeed against maxSpeed, adjust newSpeed accordingly

  // check if newSpeed or newHeading is -1
  // remember: -1 indicates that we do not wish to update this value

  
  // convert heading (N=0, E=90, S=180, W=270) to degrees on the unit
  // circle (E=0, N=90, W=180, S=270)
  // int degrees = ...
  // double radians = ...
  // more math
  // set the velocity to a Vector3D(vx, vy, 0)
}

std::ostream& operator<<(std::ostream& os, const Movable& m) {
  // stream a helpful text representation of the class
  // e.g. os << m.getClassName() << "(" << m.getName() << ", " << // more stuff


  
  return os;
}
