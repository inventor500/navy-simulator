Navy: time.o time.h TestShipAircraft.o Movable.o Ship.o Aircraft.o Cruiser.o AircraftCarrier.o Fighter.o
	g++ -Wall -g -o Navy time.o Movable.o TestShipAircraft.cpp Vector3D.o Ship.o Aircraft.o Fighter.o AircraftCarrier.o Cruiser.o
time.o: time.h time.cpp
	g++ -Wall -g -Wall -c -o time.o time.cpp
Movable.o: Movable.h time.o time.h  Movable.cpp Order.h Vector3D.h Vector3D.o
	g++ -Wall -g -c -o Movable.o Movable.cpp
Vector3D.o: Vector3D.h Vector3D.cpp
	g++ -Wall -g -c -o Vector3D.o Vector3D.cpp
Ship.o:	Vector3D.cpp Movable.cpp time.cpp Ship.cpp
	g++ -Wall -g -c -o Ship.o Ship.cpp
Aircraft.o: Vector3D.cpp Movable.cpp time.cpp Aircraft.cpp
	g++ -Wall -g -c -o Aircraft.o Aircraft.cpp
Cruiser.o: Ship.cpp
	g++ -Wall -g -c -o Cruiser.o Cruiser.cpp
AircraftCarrier.o: Ship.cpp
	g++ -Wall -g -c -o AircraftCarrier.o AircraftCarrier.cpp
Fighter.o: Aircraft.cpp
	g++ -Wall -g -c -o Fighter.o Fighter.cpp

clean :
	rm -f time.o Navy Movable.o time.o Vector3D.o Ship.o Aircraft.o Cruiser.o AircraftCarrier.o Fighter.o
