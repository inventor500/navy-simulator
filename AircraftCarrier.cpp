#include "AircraftCarrier.h"

AircraftCarrier::AircraftCarrier(std::string name, std::string id, int aircraft, int maxSpeed)
  :Ship(name,id,maxSpeed), aircraft(aircraft) {
  className = "AircraftCarrier";
  
}

