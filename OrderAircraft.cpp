#include "OrderAircraft.h"
#include "Aircraft.h"
using namespace std;

//DeployAircraft
DeployAircraft::DeployAircraft(Timer time, string id, int heading, int speed, int altitude) : Order("DeployAircraft",time,id),heading(heading),speed(speed),altitude(altitude) {}
void DeployAircraft::execute(Aircraft &aircraft) const{
  aircraft.takeoff(time,heading,speed,altitude);
}

//LandAircraft
LandAircraft::LandAircraft(Timer time, string aircraftID, Movable* ship) : Order("LandAircraft",time,aircraftID),ship(ship) {}
void LandAircraft::execute(Aircraft& aircraft) const {
  aircraft.updatePosition(time);
  aircraft.land(ship);
}

//ChangeAircraft Orders
ChangeAircraftOrders::ChangeAircraftOrders(Timer time, string id, int heading, int speed, int altitude) : Order("ChangeAircraftOrders",time,id), heading(heading),speed(speed),altitude(altitude) {}
void ChangeAircraftOrders::execute(Aircraft &aircraft) const {
  aircraft.updatePosition(time);
  aircraft.changeOrders(heading, speed, altitude);
}
