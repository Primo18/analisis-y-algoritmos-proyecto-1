#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <ostream> // Incluir para std::ostream
#include <set>
#include <string>
#include <utility> // Para std::pair
#include <vector>

struct Point
{
  double x, y, z;

  // Se define el operador << para permitir imprimir puntos directamente.
  friend std::ostream &operator<<(std::ostream &os, const Point &p)
  {
    return os << p.x << ", " << p.y << ", " << p.z;
  }
};

double calculateDistance3D(const Point &p1, const Point &p2);
bool compareX(const Point &a, const Point &b);
bool compareY(const Point &a, const Point &b);

#endif // POINT_H
