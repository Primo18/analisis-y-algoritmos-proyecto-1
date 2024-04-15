#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <set>
#include <string>
#include <utility> // Para std::pair
#include <vector>

struct Point {
  double x, y, z;
};

double calculateDistance3D(const Point &p1, const Point &p2);
bool compareX(const Point &a, const Point &b);
bool compareY(const Point &a, const Point &b);

#endif // POINT_H
