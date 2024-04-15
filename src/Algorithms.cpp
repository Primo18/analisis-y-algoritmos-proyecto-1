#include "Algorithms.h"
#include "Point.h"
#include <algorithm>
#include <chrono>
#include <cmath> // Include cmath for fabs and other functions
#include <fstream>
#include <iostream> // Include iostream for std::cout

// Función auxiliar para el método de dividir y conquistar
void paresCercanosAux(std::vector<Point> &points, double d,
                      std::ofstream &outFile, const std::string &method) {
  if (points.size() <= 3) {
    for (size_t i = 0; i < points.size(); ++i) {
      for (size_t j = i + 1; j < points.size(); ++j) {
        double dist = calculateDistance3D(points[i], points[j]);
        if (dist <= d) {
          outFile << method << "," << points.size() << "," << dist << std::endl;
        }
      }
    }
    return;
  }

  int mid = points.size() / 2;
  Point midPoint = points[mid];

  std::vector<Point> left(points.begin(), points.begin() + mid);
  std::vector<Point> right(points.begin() + mid, points.end());

  paresCercanosAux(left, d, outFile, method);
  paresCercanosAux(right, d, outFile, method);

  std::vector<Point> strip;
  for (const auto &point : points) {
    if (fabs(point.x - midPoint.x) < d) {
      strip.push_back(point);
    }
  }

  std::sort(strip.begin(), strip.end(), compareY);

  for (size_t i = 0; i < strip.size(); ++i) {
    for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d;
         ++j) {
      double dist = calculateDistance3D(strip[i], strip[j]);
      if (dist <= d) {
        outFile << method << "," << strip.size() << "," << dist << std::endl;
      }
    }
  }
}

// Fuerza bruta
void paresCercanosFB(const std::vector<Point> &points, double d,
                     const std::string &outputFilename) {
  std::ofstream outFile(outputFilename, std::ios::app); // Append mode
  auto start = std::chrono::high_resolution_clock::now();

  for (size_t i = 0; i < points.size(); ++i) {
    for (size_t j = i + 1; j < points.size(); ++j) {
      double dist = calculateDistance3D(points[i], points[j]);
      if (dist <= d) {
        outFile << "FB," << points.size() << "," << dist << std::endl;
      }
    }
  }

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  std::cout << "FB Time taken: " << duration.count() << " nanoseconds"
            << std::endl;
}

// Dividir y conquistar
void paresCercanosDC(std::vector<Point> &points, double d,
                     const std::string &outputFilename) {
  std::ofstream outFile(outputFilename, std::ios::app);
  auto start = std::chrono::high_resolution_clock::now();

  std::sort(points.begin(), points.end(), compareX);
  paresCercanosAux(points, d, outFile, "DC");

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  std::cout << "DC Time taken: " << duration.count() << " nanoseconds"
            << std::endl;
}
