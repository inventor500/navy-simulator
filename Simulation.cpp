#include "Simulation.h"

#include "Movable.h"
#include "Order.h"
#include "OrderShip.h"
#include "OrderAircraft.h"
#include "AircraftCarrier.h"
#include "Cruiser.h"
#include "Fighter.h"
#include "Output.h"

#include <fstream>
#include <sstream>

Simulation::Simulation() {}

Simulation::~Simulation() {
  for (auto [id, movable] : navy) {
    delete movable;
  }
  while (!orders.empty()) {
    delete orders.top();
    orders.pop();
  }
}

void Simulation::execute(const std::string& input, const std::string& output) {
  // 1) parse the contents of the filename "input"
  // 2) set the current time equal to start time

  // while there are orders to execute
  while (!orders.empty()) {      
    // 3) get a pointer of the next order

    
    // run time forward until until the current time is equal to the order->getTime()
    while (current < order->getTime()) {
      // 4) increment the time by one minute
      // 5) update all positions
    }

    // now it's time to execute the order
    // 6) get the id from the order
    // 7a) look up the recipient and, if found, call recipient->accept(*order)
    // 7b) if not found, print a descriptive error message

    // 8) remove the order from the priority_queue
    // 9) delete the order
  }

  // run until current time is equal to stop time, updating all positions
  while (current < stop) {
    // 10) increment the time by one minute
    // 11) update all positions
  }

  // write navy history to output file
  write(output);
}

void Simulation::parse(const std::string& filename) {
  // 1) open the file
  // 2) throw an error if you cannot open it

  // parse line by line
  // 3) for each line in file (use a while-loop)
  // 4) skip empty or commented lines (use continue)

  // 5) put the line of text into an input string stream

  // 5) read which opcode is at the beginning of the line
  
  // 6) call corresponding function for each opcode (large series of if-else)
  // else if (opcode == "StartSim") {
  //   set_start(stream);
  // }
  // else if (opcode == "StopSim") {
  //   set_stop(stream);
  // }

  // 7) throw error if opcode is unrecognized
}

void Simulation::write(const std::string& filename) {
  // export history
  std::ofstream output(filename);
  output << "{" << std::endl;
  int counter = 0;
  int N = navy.size()-1;
  for (auto [id, movable] : navy) {
    output << "  " << quote(id) << ": {" << std::endl;
    std::vector<int> time;
    std::vector<double> x, y, z;
    for (auto [t, position] : movable->getHistory()) {
      int elapsedMinutes = (t - start) / 60;
      time.push_back(elapsedMinutes);
      x.push_back(position.x);
      y.push_back(position.y);
      z.push_back(position.z);
    }
    output << "    " << keyvalue("t", time) << "," << std::endl;
    output << "    " << keyvalue("x", x) << "," << std::endl;
    output << "    " << keyvalue("y", y) << "," << std::endl;
    output << "    " << keyvalue("z", z) << std::endl;
    output << "  }";
    if (counter < N) output << ",";
    output << std::endl;
    counter++;
  }
  output << "}" << std::endl;
}

void Simulation::set_start(std::istringstream& stream) {
  // 1) make local string variables for date and time
  // 2) read these values from the stream
  // 3) set private member variable start = ATime(date, time)
}

void Simulation::set_stop(std::istringstream& stream) {
  // set the private member variable: stop
}

void Simulation::updatePositions() {
  for (auto [id, movable] : navy) {
    movable->updatePosition(current);
  }
}

void Simulation::createCruiser(std::istringstream& stream) {
  // 1) create the local variables name, id, missles, maxSpeed
  // 2) read these values from the stream
  // 3) add a new Cruiser to the navy map
}

void Simulation::createAircraftCarrier(std::istringstream& stream) {
  // implement me
}

void Simulation::createFighter(std::istringstream& stream) {
  // implement me
  // remember to look up which ship that the Fighter belongs to
}

void Simulation::deployShip(std::istringstream& stream) {
  // 1) create local variables
  // 2) read from the stream
  // 3) add a new DeployShip to the orders vector
}

void Simulation::deployAircraft(std::istringstream& stream) {
  // implement me
}

void Simulation::landAircraft(std::istringstream& stream) {
  // implement me
  // remember that you need to look up the ship in the navy map
}

void Simulation::changeShipOrders(std::istringstream& stream) {
  // implement me
}

void Simulation::changeAircraftOrders(std::istringstream& stream) {
  // implement me
}
