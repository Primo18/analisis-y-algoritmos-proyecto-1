#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <string>
#include "Point.h"

void paresCercanosFB(const std::vector<Point>& points, double d, const std::string& outputFilename);
void paresCercanosDC(std::vector<Point>& points, double d, const std::string& outputFilename);

#endif
