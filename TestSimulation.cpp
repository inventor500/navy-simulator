#include "Simulation.h"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " orders-filename output-filename" << std::endl;
    return 1;
  }
  Simulation sim;
  try {
    sim.execute(argv[1], argv[2]);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
