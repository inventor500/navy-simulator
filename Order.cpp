#include <iostream>
#include <exception>
#include "Order.h"
using namespace std;
//exceptions
class invalid_object : public runtime_error {
public:
  invalid_object(const string& message) :runtime_error(message){}
};
//friend operators
bool operator>(const Order& left, const Order& right) {
  return left.getTime() > right.getTime();
}
ostream& operator<<(std::ostream& os, const Order& order) {
  os << order.getName() << ": " << order.getID() << ": " << order.getTime();
  return os;
}
//query data
Timer Order::getTime() const {
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
void Order::execute(Ship&) const{
  string msg= "Cannot execute " + name + " on this object.";
  throw invalid_object(msg);
}
void Order::execute(Aircraft&) const{
  string msg = "Cannot execute " + name + " on this object.";
  throw invalid_object(msg);
}
