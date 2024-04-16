#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Point.h"
#include <utility> // Para std::pair
#include <vector>

// Define un tipo para hacer el código más claro
using PointPairDist = std::pair<double, std::pair<Point, Point>>;

std::vector<PointPairDist> paresCercanosFB(const std::vector<Point> &points,
                                           double d);
std::vector<PointPairDist> paresCercanosDC(std::vector<Point> &points,
                                           double d);

#endif // ALGORITHMS_H
