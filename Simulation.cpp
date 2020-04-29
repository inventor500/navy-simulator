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
#include <exception>
#include <string>
using namespace std;

class invalid_input : public runtime_error {
public:
  invalid_input(const string& message) :runtime_error(message){}
};
class object_not_found : public runtime_error {
public:
  object_not_found(const string& message) :runtime_error(message){}
};

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
  parse(input);
  current = start;
  // while there are orders to execute
  while (!orders.empty()) {      
    // 3) get a pointer of the next order
    Order* order = orders.top();
    // run time forward until until the current time is equal to the order->getTime()
    while (current < order->getTime()) {
      // 4) increment the time by one minute
      // 5) update all positions
      current += 60;
      for (auto [id, movable] : navy) {
	movable->updatePosition(current);
      }
    }

    // now it's time to execute the order
    // 6) get the id from the order
      string id = order->getID();
    // 7a) look up the recipient and, if found, call recipient->accept(*order)
      if (navy.find(id) != navy.end()) {
	Movable *recipient = navy[id];
	recipient->accept(*order);
      }
    // 7b) if not found, print a descriptive error message
      else {
	string msg = "The ship with id " + id + " was not found";
	throw object_not_found(msg);
      }
    // 8) remove the order from the priority_queue
      orders.pop();
    // 9) delete the order
      delete order;
  }

  // run until current time is equal to stop time, updating all positions
  while (current < stop) {
    current += 60;
    for (auto [id, movable] : navy) {
      movable->updatePosition(current);
    }
    // 10) increment the time by one minute
    // 11) update all positions
  }

  // write navy history to output file
  write(output);
}

void Simulation::parse(const std::string& filename) {
  ifstream fin;
  fin.open(filename);
  if (fin.fail()) {
    throw invalid_argument("Error opening file");
  }
  string line;
  while (getline(fin,line)) {
    cout << ">>> " << line << endl;
    
    //remove indentation
    while(isspace(line[0]) /*== ' ' || line[0] == '	'*/) {
      line.erase(0,1);
    }
    //ensure that line is not empty or comment
    if (line[0] == '#' || line[0] == '\n' || line.empty()) {
      continue;
    }
    istringstream ss(line);
    string order;
    ss >> order;
    //creation orders
    cout << order << endl;
    if (order == "CreateCruiser") {
      createCruiser(ss);
    }
    else if (order == "CreateAircraftCarrier") {
      createAircraftCarrier(ss);
    }
    else if (order == "CreateFighter") {
      createFighter(ss);
    }
    //start and stop simulation
    else if (order == "StartSim") {
      set_start(ss);
    }
    else if (order == "StopSim") {
      set_stop(ss);
    }
    //deployment orders
    else if (order == "DeployAircraft") {
      deployAircraft(ss);
    }
    else if (order == "DeployShip") {
      deployShip(ss);
    }
    else if (order == "LandAircraft") {
      landAircraft(ss);
    }
    //changing orders
    else if (order == "ChangeAircraftOrders") {
      changeAircraftOrders(ss);
    }
    else if (order == "ChangeShipOrders") {
      changeShipOrders(ss);
    }
    //unreacognized order
    else {
      string msg = order + " is not a recognized command.";
      throw runtime_error(msg);
    }
    
  }

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
  fin.close();
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
  string date,time;
  stream >> date >> time;
  start = Atime(date,time);
}

void Simulation::set_stop(std::istringstream& stream) {
  // set the private member variable: stop
  string date,time;
  stream >> date >> time;
  stop = Atime(date,time);
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
  string name, id;
  int missiles,speed;
  stream >> name >> id >> missiles >> speed;
  navy[id] = new Cruiser(name, id, missiles, speed);
}

void Simulation::createAircraftCarrier(std::istringstream& stream) {
  string name, id;
  int aircraft,speed;
  stream >> name >> id >> aircraft >> speed;
  navy[id] = new AircraftCarrier(name, id, aircraft,speed);
}

void Simulation::createFighter(std::istringstream& stream) {
  // remember to look up which ship that the Fighter belongs to
  string name, id, shipId;
  int speed, ceiling, bombs;
  stream >> name >> id >> shipId >> speed >> ceiling >> bombs;
  navy[id] = new Fighter(name, id, navy[shipId], speed, ceiling, bombs);
}

void Simulation::deployShip(std::istringstream& stream) {
  // 1) create local variables
  // 2) read from the stream
  // 3) add a new DeployShip to the orders vector
  string id;
  int x,y,heading,speed;
  Timer t;
  stream >> t >> id >> x >> y >> heading >> speed;
  orders.push(new DeployShip(t,id,x,y,heading,speed));
}

void Simulation::deployAircraft(std::istringstream& stream) {
    string id;
    Timer t;
    int heading, speed, altitude;
    stream >> t >> id >> heading >> speed >> altitude;
    orders.push(new DeployAircraft(t,id,heading,speed,altitude));
}

void Simulation::landAircraft(std::istringstream& stream) {
  // remember that you need to look up the ship in the navy map
  string id, shipId;
  Timer t;
  stream >> t >> shipId >> id;
  Movable *ship = navy[shipId];
  orders.push(new LandAircraft(t,id,ship));
}

void Simulation::changeShipOrders(std::istringstream& stream) {
  Timer t;
  string id;
  int heading,speed;
  stream >> t >> id >> heading >> speed;
  orders.push(new ChangeShipOrders(t,id,heading,speed));
}

void Simulation::changeAircraftOrders(std::istringstream& stream) {
    Timer t;
    string id;
    int heading, speed, altitude;
    stream >> t >> id >> heading >> speed >> altitude;
    orders.push(new ChangeAircraftOrders(t,id,heading,speed,altitude));
}
