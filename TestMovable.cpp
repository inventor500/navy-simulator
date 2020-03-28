#include "Movable.h"
#include <cmath>


int main() {
  // Create a Movable class
  Movable mov("USS_Texas", "CGN-39", 60);

  // Place test code here
  cout << mov << endl;
  cout << "The new heading should be " << 0 << ", and the speed should still be zero:\n";
  mov.setVelocity(0, -1);
  cout << mov << endl;
  mov.setVelocity(-1,20);
  cout << "The new heading should be " << 0 << ", and the new speed should be 20:\n";
  cout << mov << endl;
}
