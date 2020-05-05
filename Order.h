#pragma once

#include "Time.h"
// forward declarations
class Ship;
class Aircraft;
//exceptions
class invalid_object;
// Abstract class to handle runtime orders
class Order {
public:
  Order(std::string name, Timer time, std::string id);
  virtual ~Order() {}

  Timer getTime() const;
  std::string getID() const;
  std::string getName() const;
   
  // Define a virtual function that throws an exception for each type of
  // vessel.  It is up to subclasses of Order to override these member
  // functions for the concrete types that they can handle.
  virtual void execute(Ship& ship) const;
  virtual void execute(Aircraft& aircraft) const;

  // for sorting orders by time
  friend bool operator>(const Order& left, const Order& right);

  // printing orders, useful for debugging
  friend std::ostream& operator<<(std::ostream& os, const Order& order);
  
protected:
  // Common attributes for all Movable objects in simulation
  std::string name;
  Timer time;
  std::string id;
};

