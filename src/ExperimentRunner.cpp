#include "ExperimentRunner.h"
#include "Algorithms.h"
#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;

// Constantes
const double MIN_DISTANCE =
    5.0;            // Distancia mínima entre dos puntos para d = 5.0
const int RUNS = 3; // Número de veces que se ejecutará cada algoritmo

void runExperiments(const vector<Point> &allPoints, const vector<int> &sizes,
                    const string &outputFile) {
  ofstream out(outputFile + "_times.csv", ios::app);
  ofstream distOut(outputFile + "_distances.csv", ios::app);

  out << "Size,FB_AverageTime(ns),DC_AverageTime(ns)\n"; // CSV header
  distOut << "Size,Method,Distances\n"; // CSV header for distances

  set<double> allDistances; // Conjunto para registrar todas las distancias y
                            // evitar duplicados

  for (int size : sizes) {
    vector<Point> points(allPoints.begin(), allPoints.begin() + size);
    long long fbTotalTime = 0;
    long long dcTotalTime = 0;

    for (int i = 0; i < RUNS; ++i) {
      // Tiempo del enfoque de fuerza bruta
      auto fbStart = chrono::high_resolution_clock::now();
      auto fbDistances = paresCercanosFB(points, MIN_DISTANCE);
      auto fbEnd = chrono::high_resolution_clock::now();
      fbTotalTime +=
          chrono::duration_cast<chrono::nanoseconds>(fbEnd - fbStart).count();

      for (double dist : fbDistances) {
        // Verifica si la distancia es nueva
        if (allDistances.insert(dist).second) {
          distOut << size << ",FB," << dist << "\n";
        }
      }

      // Tiempo del enfoque de dividir y conquistar
      auto dcStart = chrono::high_resolution_clock::now();
      auto dcDistances = paresCercanosDC(points, MIN_DISTANCE);
      auto dcEnd = chrono::high_resolution_clock::now();
      dcTotalTime +=
          chrono::duration_cast<chrono::nanoseconds>(dcEnd - dcStart).count();

      for (double dist : dcDistances) {
        // Verifica si la distancia es nueva
        if (allDistances.insert(dist).second) {
          distOut << size << ",DC," << dist << "\n";
        }
      }
    }

    long long fbAverage = fbTotalTime / RUNS;
    long long dcAverage = dcTotalTime / RUNS;

    // Escribir resultados de tiempo en el archivo CSV
    out << size << "," << fbAverage << "," << dcAverage << "\n";
  }
}
