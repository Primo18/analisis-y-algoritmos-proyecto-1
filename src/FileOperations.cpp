#include "FileOperations.h"
#include <fstream>
#include <sstream>

std::vector<Point> readPointsFromFile(const std::string& filename) {
    std::vector<Point> points;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Point point;
        char delimiter;
        if (ss >> point.x >> delimiter >> point.y >> delimiter >> point.z) {
            points.push_back(point);
        }
    }
    return points;
}
