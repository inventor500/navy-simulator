#include <iostream>
#include "Fighter.h"
#include "AircraftCarrier.h"
#include "OrderAircraft.h"
#include "OrderShip.h"
using namespace std;

int main() {
  Timer testtime("09/05/2004", "04:23:20");
  AircraftCarrier testCarrier("C4pitalism","9780891073895",20,50);
  Fighter testAircraft("Chuck_Norris","9780758651679",&testCarrier,500,500,20);
  DeployAircraft testTakeOrder(testtime, "9780758651679", 20,20,20);
  DeployShip testShipDeploy(testtime-1, "9780891073895",20,20,20,20);
  ChangeAircraftOrders changeAircraftOrders(testtime+5,"9780758651679",50,500,500);
  ChangeShipOrders changeShipOrders(testtime+5,"9780891073895",40,1);
  LandAircraft landAircraft(testtime+50,"9780758651679",&testCarrier);
  testCarrier.accept(testShipDeploy);
  testCarrier.updatePosition(testtime);
  cout << testCarrier << endl;
  testAircraft.accept(testTakeOrder);
  testAircraft.updatePosition(testtime + 1);
  cout << testAircraft << endl;
  testAircraft.accept(changeAircraftOrders);
  testAircraft.updatePosition(testtime + 20);
  cout << testAircraft << endl;
  testCarrier.accept(changeShipOrders);
  testCarrier.updatePosition(testtime+20);
  cout << testCarrier << endl;
  testAircraft.accept(landAircraft);
  testAircraft.updatePosition(testtime+51);
  Timer newTime = testtime+100;
  while (testAircraft.isDeployed() == true) {
    newTime++;
    testAircraft.updatePosition(newTime);
  }
  testCarrier.updatePosition(newTime);
  cout << testAircraft << endl << testCarrier << endl;
  return 0;
}
