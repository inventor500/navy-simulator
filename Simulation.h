#pragma once

#include "ATime.h"
#include <queue>
#include <unordered_map>

// forward declarations
class Movable;
class Order;

// need a way to compare pointers to orders, so we make a comparison
// class that dereferences the two points that it's comparing
class PointerCompare {
public:
  template<typename T>
  bool operator()(T* left, T* right) {
    return *left > *right;
  }
};

// typedefs for better naming of data structures
typedef std::priority_queue<Order*, std::deque<Order*>, PointerCompare> Orders;
typedef std::unordered_map<std::string, Movable*> Navy;

class Simulation {
public:
  Simulation();
  ~Simulation();

  void execute(const std::string& input, const std::string& output);
  
private:
  // interacting with files
  void parse(const std::string& filename);
  void write(const std::string& filename);
  
  // simulation control
  void set_start(std::istringstream& stream);
  void set_stop(std::istringstream& stream);
  void updatePositions();

  // create ship or aircraft
  void createCruiser(std::istringstream& stream);
  void createAircraftCarrier(std::istringstream& stream);
  void createFighter(std::istringstream& stream);
  
  // create runtime order
  void deployShip(std::istringstream& stream);
  void deployAircraft(std::istringstream& stream);
  void landAircraft(std::istringstream& stream);
  void changeShipOrders(std::istringstream& stream);
  void changeAircraftOrders(std::istringstream& stream);
  
  ATime start, stop, current;
  Orders orders;
  Navy navy;
};
