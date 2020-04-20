#include "OrderShip.h"
#include "Ship.h"
using namespace std;

//DeployShip
DeployShip::DeployShip(Timer time, string id, int x, int y, int heading, int speed) : Order("DeployShip",time,id),x(x),y(y),heading(heading),speed(speed){}
void DeployShip::execute(Ship &ship) const{
  ship.deploy(time, x, y, heading, speed);
}

//ChangeShipOrders
ChangeShipOrders::ChangeShipOrders(Timer time, string id, int heading, int speed) :Order("ChangeShipOrders",time, id),heading(heading),speed(speed){}
void ChangeShipOrders::execute(Ship &ship) const{
  ship.updatePosition(time);
  ship.changeOrders(heading, speed);
}
