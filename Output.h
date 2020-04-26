#pragma once

#include <sstream>

std::string quote(std::string s) {
  return "\"" + s + "\"";
}

std::string keyvalue(std::string k, std::string v) {
  return quote(k) + ": " + quote(v);
}

template <typename T>
std::string keyvalue(std::string k, std::vector<T> v) {
  std::stringstream ss;
  ss << quote(k) << ": [";
  if (v.size() > 0) {
    for (std::size_t i = 0; i < v.size()-1; i++) {
      ss << v[i] << ", ";
    }
    ss << v.back();
  }
  ss << "]";
  return ss.str();
}
