#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D()
  :x(0), y(0), z(0) {}

Vector3D::Vector3D(double x, double y, double z)
  :x(x), y(y), z(z) {}

Vector3D& Vector3D::operator+=(const Vector3D& rhs) {
  x += rhs.x;
  y += rhs.y;
  z += rhs.z;
  return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& rhs) {
  x -= rhs.x;
  y -= rhs.y;
  z -= rhs.z;
  return *this;
}

Vector3D& Vector3D::operator*=(const Vector3D& rhs) {
  x *= rhs.x;
  y *= rhs.y;
  z *= rhs.z;
  return *this;
}

Vector3D& Vector3D::operator*=(double scalar) {
  x *= scalar;
  y *= scalar;
  z *= scalar;
  return *this;
}

Vector3D& Vector3D::operator/=(double scalar) {
  x /= scalar;
  y /= scalar;
  z /= scalar;
  return *this;
}

double Vector3D::dot(const Vector3D& v) const {
  return x*v.x + y*v.y + z*v.z;
}

Vector3D Vector3D::cross(const Vector3D& v) const {
  return Vector3D(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

double Vector3D::norm() const {
  return std::sqrt(x*x + y*y + z*z);
}

Vector3D Vector3D::unit() const {
  double n = norm();
  return Vector3D(x/n, y/n, z/n);
}

std::ostream& operator<<(std::ostream& os, const Vector3D& vec) {
  os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
  return os;
}

Vector3D operator+(Vector3D lhs, const Vector3D& rhs) {
  lhs += rhs;
  return lhs;
}

Vector3D operator-(Vector3D lhs, const Vector3D& rhs) {
  lhs -= rhs;
  return lhs;
}

Vector3D operator*(Vector3D lhs, const Vector3D& rhs) {
  lhs *= rhs;
  return lhs;
}

Vector3D operator*(Vector3D lhs, double s) {
  lhs *= s;
  return lhs;
}

Vector3D operator*(double s, Vector3D v1) {
  return v1 * s;
}

Vector3D pow(const Vector3D& v, double n) {
  return Vector3D(std::pow(v.x, n), std::pow(v.y, n), std::pow(v.z, n));
}
