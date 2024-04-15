#include "ExperimentRunner.h"
#include "FileOperations.h"
#include <iostream>

using namespace std;

int main() {
  vector<Point> points = readPointsFromFile("./data/points_data.csv");
  // Tamaños de los conjuntos de puntos a evaluar
  vector<int> sizes = {10, 100, 500, 1000, 5000, 10000, 25000, 50000};
  runExperiments(points, sizes, "./data/results");
  return 0;
}
