#include <cstring>
#include "Simulation.h"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " orders-filename output-filename" << std::endl;
    return 1;
  }
  Simulation sim;
  if (argc > 3 && strcmp(argv[3],"-v") == 0) {
    sim.setVerbose(true);
  }
  try {
    sim.execute(argv[1], argv[2]);
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
