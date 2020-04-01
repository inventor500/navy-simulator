#include "Ship.h"
#include "ATime.h"

#include <iostream>

int main() {
  // Write some test code to verify that Ships and Aircraft move correctly
  // Here is an example of a ship moving North, then turning East
  // My advice is to write many tests to check all the functionality
  // Check Aircraft as well, takeoff and land
  Ship ship("USS_Texas", "CGN-39", 60);
  ATime time("3/30/2020", "10:00:00"); // start time
  ship.deploy(time, 0, 0, 0, 60);
  for (int i = 0; i < 5; i++) {
    time += 60; // add one minute
    ship.updatePosition(time);
    std::cout << ship << std::endl;
  }

  ship.changeOrders(90, 30);
  for (int i = 0; i < 5; i++) {
    time += 60; // add one minute
    ship.updatePosition(time);
    std::cout << ship << std::endl;
  }
}
