# navy-simulator
Will not compile, because TestMovable.cpp contains code that accesses a protected function. To compile and test this program, make setVelocity public in Movable.h. I had this public while testing the code (the purpose of TestMovable.cpp) but then made it private after testing, which is what it should be.
