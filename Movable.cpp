#include "Movable.h"
#include "Vector3D.h"
#include <cmath>
#include <iostream>
using namespace std;

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
  if (newSpeed != -1) {
    speed = newSpeed;
  }
  if (newHeading != -1) {
    newHeading = newHeading % 360;
    heading = newHeading;
  }
  double headingUnit = (heading - 90.0) * -1;
  double radians = (M_PI / 180) * headingUnit;
  double x = cos(radians) * speed;
  double y = sin(radians) * speed;
  Vector3D temp(x,y,0);
  velocity = temp;
}

std::ostream& operator<<(std::ostream& os, const Movable& m) {
  os << m.getClassName() << " (" << m.getID() << " \"" << m.getName() << "\"" << ") ";
  os << m.getPosition() << ". Velocity: " << m.velocity << " ";
  os << "Speed: " << m.speed << " Heading: " << m.heading << ".";
  if (m.isDeployed() == false) {
    os << " Not Deployed.";
  }

  return os;
}
