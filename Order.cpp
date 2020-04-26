#include <iostream>
#include <exception>
#include "Order.h"
using namespace std;
//exceptions
class invalid_object : public runtime_error {
public:
  invalid_object(const string& message) :runtime_error(message){}
};
//friend operators - uses functions to get data, so that data storage method can change without changing function
bool operator>(const Order& left, const Order& right) {
  return left.getTime() > right.getTime();
}
ostream& operator<<(std::ostream& os, const Order& order) {
  os << order.getName() << ": " << order.getID() << ": " << order.getTime();
  return os;
}
//query data
ATime Order::getTime() const {
  return time;
}
string Order::getID() const{
  return id;
}
string Order::getName() const{
  return name;
}
//constructors
Order::Order(string name, Timer time, string id)
  :name(name), time(time), id(id){}
//virtual functions
void Order::execute(Ship& ship) const{
  string msg="Cannot execute " + name + " on " ship.getName();
  throw invalid_object(msg);
}
void Order::execute(Aircraft& aircraft) const{
  string msg = "Cannot execute " + name + " on " aircraft.getName();
  throw invalid_object(msg);
}
