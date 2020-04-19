#include <iostream>
#include "Order.h"
using namespace std;

int main() {
  Timer testtime("09/05/2004", "04:23:20");
  Order testOrder("test", testtime, "Chuck_Norris");
  return 0;
}
