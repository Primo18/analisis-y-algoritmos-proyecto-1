#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Point.h"

std::set<double> paresCercanosFB(const std::vector<Point> &points, double d);
std::set<double> paresCercanosDC(std::vector<Point> &points, double d);

#endif // ALGORITHMS_H
