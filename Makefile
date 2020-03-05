Navy: time.o time.h test.cpp
	g++ -Wall -g -o Navy time.o test.cpp
time.o: time.h time.cpp
	g++ -Wall -g -Wall -c -o time.o time.cpp

clean :
	rm -f time.o Navy
