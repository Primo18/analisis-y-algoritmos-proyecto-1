#include "ExperimentRunner.h"
#include "Algorithms.h"
#include <chrono>
#include <fstream>
#include <iostream>

void runExperiments(const std::vector<Point> &allPoints,
                    const std::vector<int> &sizes,
                    const std::string &outputFile) {
  std::ofstream out(outputFile);
  out << "Size,FB_AverageTime(ns),DC_AverageTime(ns)\n"; // CSV header

  for (int size : sizes) {
    if (size > static_cast<int>(allPoints.size())) {
      std::cout << "Requested size " << size
                << " is greater than the available number of points.\n";
      continue;
    }

    std::vector<Point> points(allPoints.begin(), allPoints.begin() + size);
    long long fbTotalTime = 0;
    long long dcTotalTime = 0;
    int runs = 10; // Número de veces que se ejecutará cada algoritmo

    for (int i = 0; i < runs; ++i) {
      // Tiempo del enfoque de fuerza bruta
      auto fbStart = std::chrono::high_resolution_clock::now();
      paresCercanosFB(points, 5.0, outputFile);
      auto fbEnd = std::chrono::high_resolution_clock::now();
      fbTotalTime +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(fbEnd - fbStart)
              .count();

      // Tiempo del enfoque de dividir y conquistar
      auto dcStart = std::chrono::high_resolution_clock::now();
      paresCercanosDC(points, 5.0, outputFile);
      auto dcEnd = std::chrono::high_resolution_clock::now();
      dcTotalTime +=
          std::chrono::duration_cast<std::chrono::nanoseconds>(dcEnd - dcStart)
              .count();
    }

    long long fbAverage = fbTotalTime / runs;
    long long dcAverage = dcTotalTime / runs;

    out << size << "," << fbAverage << "," << dcAverage
        << "\n"; // Escribir resultados en el archivo CSV
  }
}
