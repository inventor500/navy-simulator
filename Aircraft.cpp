#include "Aircraft.h"
#include <cmath>

const double feetToMiles = 6076.118; //the number of ft to 1 nautical mile

Aircraft::Aircraft(std::string name, std::string id, Movable* ship, int maxSpeed, int maxAltitude)
  :Movable(name, id, maxSpeed), ship(ship), maxAltitude(maxAltitude) {
  className = "Aircraft";
}

void Aircraft::takeoff(ATime t, int heading, int speed, int newAltitude) {
  // take off from the ship's position with given heading, speed, altitude
  // remember to "detach" yourself from the ship: ship = nullptr;
  position = ship->getPosition();
  ship = nullptr;
  deployed = true;
  //convert z to nautical miles
  if (newAltitude <= maxAltitude) {
    position.z = newAltitude / feetToMiles;
  }
  else {
    position.z = maxAltitude / feetToMiles;
  }
    
  setVelocity(heading, speed);
  time = t;
  history.push_back({t, position});
}

void Aircraft::land(Movable* newShip) {
  ship = newShip;
  // attach yourself to this ship
  //find the direction towards the ship, set velocity to that, and land when the distance between ship and aircraft is what will be covered in one second
}

void Aircraft::changeOrders(int heading, int speed, int newAltitude) {
  if (isDeployed()) {
    setVelocity(heading, speed);
    double doubleAltitude = newAltitude;
    doubleAltitude /= feetToMiles;
    if (doubleAltitude <= maxAltitude) {
      position.z = doubleAltitude;
    }
    else {
      position.z = (maxAltitude / feetToMiles);
    }
  }
}

void Aircraft::accept(const Order& order) {
  // will be used for double dispatch when implemented, leave commented out
  order.execute(*this);
}

void Aircraft::updatePosition(ATime t) {
  int dt = t - time;
  // you have to handle two cases here:
  // 1. flying in a straight line (when not attached to a ship)
  // 2. landing (when attached to a ship)
  // when landing always update your velocity to point to the ship's
  // current location
  if (isDeployed()) {
    if (ship != nullptr) {
      //angle towards ship for landing
      /*Vector3D distance = ship->getPosition() - getPosition();
      Vector3D v = distance.unit();
      setVelocity(v.unit(),speed);*/
      Vector3D direction = ship->getPosition();
      velocity = direction.unit() * speed;
      //double distance = (ship->getPosition() - position).norm();
      //land
      //Vector3D distance = position + dt/3600.0 * velocity;
      double distance = (ship->getPosition() - position).norm();
      double aircraftDistanceCovered = (velocity*(dt/3600.0)).norm();
      if (distance <= aircraftDistanceCovered) {
	deployed = false;
	history.push_back({t, ship->getPosition()});
      }
      //new velocity towards ship, close enough to land
    }
    
    position += (dt/3600.0) * velocity;
    Location location(t, position);
    history.push_back(location);
  }
  time = t;
}

