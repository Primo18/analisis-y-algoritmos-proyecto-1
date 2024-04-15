#include "ExperimentRunner.h"
#include "Algorithms.h"
#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;

// Constantes
const double MIN_DISTANCE = 5.0; // Distancia mínima entre dos puntos
const int RUNS = 3; // Número de veces que se ejecutará cada algoritmo

// Estructura para representar pares de puntos de forma ordenada
struct OrderedPair {
  Point first;
  Point second;
  OrderedPair(const Point &a, const Point &b) {
    if (a.x != b.x) {
      first = a.x < b.x ? a : b;
      second = a.x < b.x ? b : a;
    } else if (a.y != b.y) {
      first = a.y < b.y ? a : b;
      second = a.y < b.y ? b : a;
    } else {
      first = a.z < b.z ? a : b;
      second = a.z < b.z ? b : a;
    }
  }
  bool operator<(const OrderedPair &o) const {
    if (first.x != o.first.x)
      return first.x < o.first.x;
    if (first.y != o.first.y)
      return first.y < o.first.y;
    if (first.z != o.first.z)
      return first.z < o.first.z;
    if (second.x != o.second.x)
      return second.x < o.second.x;
    if (second.y != o.second.y)
      return second.y < o.second.y;
    return second.z < o.second.z;
  }
};

void runExperiments(const vector<Point> &allPoints, const vector<int> &sizes,
                    const string &outputFile) {
  ofstream out(outputFile + "_times.csv", ios::app);
  ofstream distOut(outputFile + "_distances.csv", ios::app);

  out << "Size,FB_AverageTime(ns),DC_AverageTime(ns)\n"; // CSV header for times
  distOut << "Size,Method,X1,Y1,Z1,X2,Y2,Z2,Distance\n";

  set<OrderedPair> allPairs; // Para evitar duplicados

  for (int size : sizes) {
    vector<Point> points(allPoints.begin(), allPoints.begin() + size);
    long long fbTotalTime = 0, dcTotalTime = 0;

    for (int run = 0; run < RUNS; ++run) {
      auto fbStart = chrono::high_resolution_clock::now();
      auto fbResults = paresCercanosFB(points, MIN_DISTANCE);
      auto fbEnd = chrono::high_resolution_clock::now();
      fbTotalTime +=
          chrono::duration_cast<chrono::nanoseconds>(fbEnd - fbStart).count();

      for (const auto &result : fbResults) {
        OrderedPair op(result.second.first, result.second.second);
        if (allPairs.insert(op).second) {
          distOut << size << ",FB," << op.first << "," << op.second << ","
                  << result.first << "\n";
        }
      }

      auto dcStart = chrono::high_resolution_clock::now();
      auto dcResults = paresCercanosDC(points, MIN_DISTANCE);
      auto dcEnd = chrono::high_resolution_clock::now();
      dcTotalTime +=
          chrono::duration_cast<chrono::nanoseconds>(dcEnd - dcStart).count();

      for (const auto &result : dcResults) {
        OrderedPair op(result.second.first, result.second.second);
        if (allPairs.insert(op).second) {
          distOut << size << ",DC," << op.first << "," << op.second << ","
                  << result.first << "\n";
        }
      }
    }

    long long fbAverage = fbTotalTime / RUNS;
    long long dcAverage = dcTotalTime / RUNS;
    out << size << "," << fbAverage << "," << dcAverage << "\n";
  }
}
