Navy: time.o time.h TestMovable.cpp Movable.o
	g++ -Wall -g -o Navy time.o Movable.o TestMovable.cpp Vector3D.o
time.o: time.h time.cpp
	g++ -Wall -g -Wall -c -o time.o time.cpp
Movable.o: Movable.h time.o time.h  Movable.cpp Order.h Vector3D.h Vector3D.o
	g++ -Wall -g -c -o Movable.o Movable.cpp
Vector3D.o: Vector3D.h Vector3D.cpp
	g++ -Wall -g -c -o Vector3D.o Vector3D.cpp


clean :
	rm -f time.o Navy Movable.o Vector3D.o
