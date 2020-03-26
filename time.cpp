#include "time.h"
using namespace std;

Timer::Timer() {
  m_time = -1;
}

Timer::Timer(string date, string time) {
  m_time = toTime(date, time);
}

Timer::Timer(time_t t) {
  m_time = t;
}
string Timer::getSVal() const {
  stringstream ss;
  string theTime;
  ss << m_time;
  ss >> theTime;
  return theTime;
}
//test if valid time
bool Timer::isValid() const {
  return (m_time != -1);
}

//operators
bool Timer::operator<(const Timer &b) const {
  return (m_time < b.m_time);
}
bool Timer::operator==(const Timer &b) const {
    return (m_time == b.m_time);
}
bool Timer::operator>(const Timer &b) const {
  return !(*this <= b);
}
bool Timer::operator<=(const Timer &b) const {
  return (*this < b) || (*this == b);
}
bool Timer::operator>=(const Timer &b) const {
  return !(*this < b);
}
bool Timer::operator!=(const Timer &b) const {
  return !(*this == b);
}
//addition
Timer Timer::operator+(const int seconds) const {
  Timer temp(m_time + seconds);
  return temp;
}
Timer Timer::operator++() {
  m_time += 1;
  return *this;
}
Timer Timer::operator++(int) {
  Timer temp = *this;
  ++*this;
  return temp;
}
Timer& Timer::operator+=(int seconds) {
  m_time += seconds;
  return *this;
}
//io
ostream& operator<<(ostream& os, Timer t) {
  os << put_time(localtime(&t.m_time), "%m/%d/%Y %H:%M:%S");
  return os;
}
istream& operator>>(istream& is, Timer &t) {
  string dateIn, timeIn, temp;
  is >> dateIn >> timeIn;
  t.m_time = t.toTime(dateIn, timeIn);
  return is;
}
//subtraction
int Timer::operator-(const Timer &b) const {
  int seconds = m_time - b.m_time;
  return seconds;
}
Timer Timer::operator-(const int seconds) const {
  Timer temp(m_time - seconds);
  return temp;
}
Timer Timer::operator-=(int seconds) {
  m_time -= seconds;
  return *this;
}


time_t Timer::toTime(string inDate, string inTime) {
  stringstream ss;
  int month = 0, day = 0, year = 0;
  char slash;
  int hour = 0, minute = 0, second = 0;
  string combined = inDate + ' ' + inTime;
  ss << combined;
  ss >> month >> slash >> day >> slash >> year;
  ss >> hour >> slash >> minute >> slash >> second;
  struct tm date;
  date.tm_year = year - 1900; //years since 1900
  date.tm_mon = month - 1;
  date.tm_mday = day;
  date.tm_hour = hour;
  date.tm_min = minute;
  date.tm_sec = second;
  date.tm_isdst = -1;
  time_t timeValue = mktime(&date);
  return timeValue;
}
