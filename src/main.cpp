#include "ExperimentRunner.h"
#include "FileOperations.h"
#include <iostream>

int main() {
  std::vector<Point> points = readPointsFromFile("./data/points_data.csv");
  std::vector<int> sizes = {
      10,   100,   500,   1000,
      5000, 10000, 50000, 100000}; // Tamaños de los conjuntos de puntos
  runExperiments(points, sizes, "./data/results.csv");
  return 0;
}
