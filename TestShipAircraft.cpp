#include "Ship.h"
#include "Aircraft.h"
#include "time.h"

#include <iostream>

int main() {
  // Write some test code to verify that Ships and Aircraft move correctly
  // Here is an example of a ship moving North, then turning East
  // My advice is to write many tests to check all the functionality
  // Check Aircraft as well, takeoff and land
  Ship ship("USS_Texas", "CGN-39", 60);
  Aircraft aircraft("Chuck_Norris", "There used to be life on Mars...", &ship, 500, 400);
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
  std::cout << "\n\n\nAn aircraft takes off...\n\n";
  aircraft.takeoff(time, 0, 20, 50);
  for (int i = 0; i < 5; i++) {
    ship.updatePosition(time);
    aircraft.updatePosition(time);
    std::cout << ship << std::endl << aircraft << "\n";
    time += 60;
  }
  std::cout << "\nThe aircraft now changes course...\n\n";
  aircraft.changeOrders(20, 50, 10);
  for (int i = 0; i < 5; i++) {
    time += 60;
    ship.updatePosition(time);
    aircraft.updatePosition(time);
    std::cout << ship << std::endl << aircraft << "\n";
  }
  aircraft.land(&ship);
  std::cout << "\n\nAnd now it will try to land...\n\n";
  for (int i = 0; i < 20; i++) {
    time += 60;
    ship.updatePosition(time);
    aircraft.updatePosition(time);
    std::cout << ship << std::endl << aircraft << "\n";
  }
}

