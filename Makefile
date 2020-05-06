Compiler = g++
CFlags = -Wall -Wextra -g
Compile = $(Compiler) $(CFlags)
Navy: Cruiser.o AircraftCarrier.o Fighter.o OrderAircraft.o OrderShip.o Simulation.o TestSimulation.cpp
	$(Compile) -std=c++17 -o Navy Time.o Movable.o Vector3D.o Ship.o Aircraft.o Fighter.o AircraftCarrier.o Cruiser.o Order.o OrderAircraft.o OrderShip.o Simulation.o TestSimulation.cpp
Time.o: Time.h Time.cpp Time.h
	$(Compile) -c -o Time.o Time.cpp
Movable.o: Time.o Order.o Vector3D.o Movable.cpp Movable.h
	$(Compile) -c -o Movable.o Movable.cpp
Vector3D.o: Vector3D.cpp Vector3D.h
	$(Compile) -c -o Vector3D.o Vector3D.cpp
Ship.o:	Vector3D.o Movable.o Time.o Ship.cpp Ship.h
	$(Compile) -c -o Ship.o Ship.cpp
Aircraft.o: Vector3D.o Movable.o Time.o Aircraft.cpp Aircraft.h
	$(Compile) -c -o Aircraft.o Aircraft.cpp
Cruiser.o: Ship.o Cruiser.cpp Cruiser.h
	$(Compile) -c -o Cruiser.o Cruiser.cpp
AircraftCarrier.o: Ship.o AircraftCarrier.cpp AircraftCarrier.h
	$(Compile) -c -o AircraftCarrier.o AircraftCarrier.cpp
Fighter.o: Aircraft.o Fighter.cpp Fighter.h
	$(Compile) -c -o Fighter.o Fighter.cpp
Order.o: Time.o Order.cpp Order.h
	$(Compile) -c -o Order.o Order.cpp
OrderAircraft.o: Order.o OrderAircraft.cpp OrderAircraft.h
	$(Compile) -c -o OrderAircraft.o OrderAircraft.cpp
OrderShip.o: Order.o OrderShip.cpp OrderShip.h
	$(Compile) -c -o OrderShip.o OrderShip.cpp
Simulation.o: Movable.o Order.o OrderAircraft.o OrderShip.o Time.o Output.h Simulation.cpp Simulation.h
	$(Compile) -std=c++17 -c -o Simulation.o Simulation.cpp

clean :
	rm -f Navy Time.o Movable.o Vector3D.o Ship.o Aircraft.o Cruiser.o AircraftCarrier.o Fighter.o Order.o OrderAircraft.o OrderShip.o  Simulation.o
