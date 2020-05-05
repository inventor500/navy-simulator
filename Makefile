Navy: Time.o Time.h TestShipAircraft.o Movable.o Ship.o Aircraft.o Cruiser.o AircraftCarrier.o Fighter.o Order.o OrderAircraft.o OrderShip.o Simulation.o TestSimulation.cpp
	g++ -Wall -Wextra -g -std=c++17 -o Navy Time.o Movable.o Vector3D.o Ship.o Aircraft.o Fighter.o AircraftCarrier.o Cruiser.o Order.o OrderAircraft.o OrderShip.o Simulation.o TestSimulation.cpp
Time.o: Time.h Time.cpp
	g++ -Wall -Wextra -g -c -o Time.o Time.cpp
Movable.o: Movable.h Time.o Time.h  Movable.cpp Order.h Vector3D.h Vector3D.o
	g++ -Wall -Wextra -g -c -o Movable.o Movable.cpp
Vector3D.o: Vector3D.h Vector3D.cpp
	g++ -Wall -Wextra -g -c -o Vector3D.o Vector3D.cpp
Ship.o:	Vector3D.cpp Movable.cpp Time.cpp Ship.cpp
	g++ -Wall -Wextra -g -c -o Ship.o Ship.cpp
Aircraft.o: Vector3D.cpp Movable.cpp Time.cpp Aircraft.cpp
	g++ -Wall -Wextra -g -c -o Aircraft.o Aircraft.cpp
Cruiser.o: Ship.cpp
	g++ -Wall -Wextra -g -c -o Cruiser.o Cruiser.cpp
AircraftCarrier.o: Ship.cpp
	g++ -Wall -Wextra -g -c -o AircraftCarrier.o AircraftCarrier.cpp
Fighter.o: Aircraft.cpp
	g++ -Wall -Wextra -g -c -o Fighter.o Fighter.cpp
Order.o: Time.o Order.cpp;
	g++ -Wall -Wextra -g -c -o Order.o Order.cpp
OrderAircraft.o: Order.o OrderAircraft.cpp
	g++ -Wall -Wextra -g -c -o OrderAircraft.o OrderAircraft.cpp
OrderShip.o: Order.o OrderShip.cpp
	g++ -Wall -Wextra -g -c -o OrderShip.o OrderShip.cpp
Simulation.o: Movable.o Order.o OrderAircraft.o OrderShip.o Time.o Output.h Simulation.cpp
	g++ -Wall -Wextra -std=c++17 -g -c -o Simulation.o Simulation.cpp

clean :
	rm -f Time.o Navy Movable.o Vector3D.o Ship.o Aircraft.o Cruiser.o AircraftCarrier.o Fighter.o Order.o OrderAircraft.o OrderShip.o TestShipAircraft.o Simulation.o
