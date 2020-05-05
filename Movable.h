#pragma once

#include "Vector3D.h" // Dr. Brown's 3D vector class
#include "time.h"
#include "Order.h"
#include <vector>

typedef std::pair<Timer, Vector3D> Location;
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
   virtual void accept(const Order& order) = 0;
   virtual void updatePosition(Timer t) = 0;

  friend std::ostream& operator<<(std::ostream& os, const Movable& movable);
  
  protected:
  std::string className, name, id;
  bool deployed;
  int heading, speed, maxSpeed;
  Vector3D position, velocity;
  Timer time;
  LocationHistory history;

  // set the velocity vector from heading and speed
  void setVelocity(int heading, int speed);
};

