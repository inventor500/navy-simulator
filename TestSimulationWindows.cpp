#include "Simulation.h"

int main() {
  Simulation sim;
  try {
    std::cout << "Please enter the input and output filenames:" << std::endl;
    std::string input_filename, output_filename;
    std::cin >> input_filename >> output_filename;
    sim.execute(input_filename, output_filename);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
