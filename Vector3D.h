#pragma once

#include <iostream>

class Vector3D {
public:
  double x, y, z;
  
  Vector3D();
  Vector3D(double x, double y, double z);
  
  Vector3D& operator+=(const Vector3D& rhs);
  Vector3D& operator-=(const Vector3D& rhs);
  Vector3D& operator*=(const Vector3D& rhs);
  Vector3D& operator*=(double s);
  Vector3D& operator/=(double s);
  
  double dot(const Vector3D& v) const;
  Vector3D cross(const Vector3D& v) const;
  double norm() const;
  Vector3D unit() const;

  friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec);
};

Vector3D operator+(Vector3D lhs, const Vector3D& rhs);
Vector3D operator-(Vector3D lhs, const Vector3D& rhs);
Vector3D operator*(Vector3D lhs, const Vector3D& rhs);
Vector3D operator*(Vector3D lhs, double scalar);
Vector3D operator*(double scalar, Vector3D rhs);
Vector3D pow(const Vector3D& base, double exponent);
