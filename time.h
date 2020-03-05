#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#pragma once
//#include <string>
using namespace std;

class Timer {
public:
  Timer();
  Timer(string, string); //should be MM/DD/YY HH:MM:SS
  Timer(time_t t);
  string getSVal() const;

  //friend ostream& operator<<(ostream& os, Timer t);
  friend istream& operator>>(istream& is, Timer &);
  friend ostream& operator<<(ostream& os, Timer);
  //operators
  bool isValid() const;
  bool operator<(const Timer &) const;
  bool operator>(const Timer &) const;
  bool operator<=(const Timer &) const;
  bool operator>=(const Timer &) const;
  bool operator==(const Timer &) const;
  bool operator!=(const Timer &) const;
  //addition
  Timer operator+(const int) const;
  Timer operator++(); //preinc one second
  Timer operator++(int); //postinc one second
  Timer& operator+=(int); //adds seconds
  int operator-(const Timer&) const; //seconds between to times
  Timer operator-(const int) const; //take away from time
  Timer operator-=(int);
  private:
  time_t m_time;
  time_t toTime(string, string);
};

