#pragma once

#include "Vector3D.h" // Dr. Brown's 3D vector class
#include "ATime.h"    // Your ATime header
#include "Order.h"    // A place holder for the Order class
#include <vector>

// We can use typedef to define more descriptive types
typedef std::pair<ATime, Vector3D> Location;
typedef std::vector<Location> LocationHistory;

class Movable {
public:
  Movable(std::string name, std::string id, int maxSpeed);
  virtual ~Movable() {}

  std::string getClassName() const;
  std::string getName() const;
  std::string getID() const;
  bool isDeployed() const;
  Vector3D getPosition() const;
  const LocationHistory& getHistory() const;

  // subclasses will be forced to implement these
  // for now leave them commented out
  // virtual void accept(const Order& order) = 0;
  // virtual void updatePosition(ATime t) = 0;

  friend std::ostream& operator<<(std::ostream& os, const Movable& movable);
  
protected:
  std::string className, name, id;
  bool deployed;
  int heading, speed, maxSpeed;
  Vector3D position, velocity;
  ATime time;
  LocationHistory history;

  // set the velocity vector from heading and speed
  void setVelocity(int heading, int speed);
};

