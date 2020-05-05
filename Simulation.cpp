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
  parse(input); //parse all input
  current = start;
  while (!orders.empty()) {      
    Order* order = orders.top();
    while (current < order->getTime()) {
      current += 60; //advance by 1 minute
      for (auto [id, movable] : navy) {
	movable->updatePosition(current); //update all positions every second
      }
    }
      string id = order->getID();
      if (navy.find(id) != navy.end()) { //double dispatch
	Movable *recipient = navy[id];
	recipient->accept(*order);
      }
      else {
	string msg = "The ship with id " + id + " was not found";
	throw object_not_found(msg);
      }
      orders.pop();
      delete order;
  }

  // run until stop time
  while (current < stop) {
    current += 60;
    for (auto [id, movable] : navy) {
      movable->updatePosition(current);
    }
  }
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
    while(isspace(line[0])) {
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
  fin.close();
}

void Simulation::write(const std::string& filename) {
  // export history
  std::ofstream output(filename);
  output << "{" << std::endl;
  size_t counter = 0;
  size_t N = navy.size()-1;
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
  //set start time
  string date,time;
  stream >> date >> time;
  start = Atime(date,time);
}

void Simulation::set_stop(std::istringstream& stream) {
  //set stop time
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
  string name, id, shipId;
  int speed, ceiling, bombs;
  stream >> name >> id >> shipId >> speed >> ceiling >> bombs;
  navy[id] = new Fighter(name, id, navy[shipId]/*find ship fighter is on*/, speed, ceiling, bombs);
}

void Simulation::deployShip(std::istringstream& stream) {
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
  string id, shipId;
  Timer t;
  stream >> t >> shipId >> id;
  Movable *ship = navy[shipId]; //find ship to land on
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
