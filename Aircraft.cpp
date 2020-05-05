#include "Aircraft.h"
#include <cmath>

const double feetToMiles = 6076.118; //the number of ft to 1 nautical mile

Aircraft::Aircraft(std::string name, std::string id, Movable* ship, int maxSpeed, int maxAltitude)
  :Movable(name, id, maxSpeed), ship(ship), maxAltitude(maxAltitude) {
  className = "Aircraft";
}

void Aircraft::takeoff(Timer t, int heading, int speed, int newAltitude) {
  position = ship->getPosition();
  ship = nullptr; //this is used again when landing
  deployed = true;
  Location takeOffLocation(t,position);
  history.push_back(takeOffLocation);
    //convert z to nautical miles
  if (newAltitude <= maxAltitude) {
    position.z = newAltitude / feetToMiles;
  }
  else {
    position.z = maxAltitude / feetToMiles;
  }
  time = t;
  Location location(t, position);
  history.push_back(location);
  setVelocity(heading, speed);
}

void Aircraft::land(Movable* newShip) {
  //angling toward ship is done in updatePosition(Timer)
  ship = newShip;
}

void Aircraft::changeOrders(int heading, int speed, int newAltitude) {
  if (isDeployed()) {
    double doubleAltitude = newAltitude;
    doubleAltitude /= feetToMiles;
    if (doubleAltitude <= maxAltitude) {
      position.z = doubleAltitude;
    }
    else {
      position.z = (maxAltitude / feetToMiles);
    }
    setVelocity(heading, speed);
  }
}

void Aircraft::accept(const Order& order) { //double dispatch
  order.execute(*this);
}

void Aircraft::updatePosition(Timer t) {
  int dt = t - time; //difference in time
  if (isDeployed()) {
    if (ship != nullptr) { //if aircraft is landing
      Vector3D direction = ship->getPosition() - position;
      velocity = direction.unit() * speed;
      double distance = (ship->getPosition() - position).norm();
      double aircraftDistanceCovered = (velocity*(dt/3600.0)).norm();
      if (distance <= aircraftDistanceCovered) { //if ship is close enough to land
	deployed = false;
	history.push_back({t, ship->getPosition()});
      }
    }
    //move forward
    position += (dt/3600.0) * velocity;
    Location location(t, position);
    history.push_back(location);
  }
  time = t;
}


