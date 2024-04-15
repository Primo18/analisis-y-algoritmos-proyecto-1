#include "Algorithms.h"
#include "Point.h"
#include <algorithm>

using namespace std;

// Método de fuerza bruta para encontrar pares cercanos
set<double> paresCercanosFB(const vector<Point> &points, double d) {
  set<double> distances;

  for (size_t i = 0; i < points.size(); ++i) {
    for (size_t j = i + 1; j < points.size(); ++j) {
      double dist = calculateDistance3D(points[i], points[j]);
      if (dist <= d) {
        distances.insert(dist);
      }
    }
  }
  return distances;
}

// Función auxiliar para el enfoque de dividir y conquistar
set<double> paresCercanosAux(vector<Point> &points, double d,
                             set<double> &registeredDistances) {
  set<double> localDistances;

  if (points.size() <= 3) {
    // Utiliza la función de fuerza bruta para conjuntos pequeños y fusiona los
    // resultados.
    set<double> baseCaseDistances = paresCercanosFB(points, d);
    registeredDistances.insert(baseCaseDistances.begin(),
                               baseCaseDistances.end());
    return baseCaseDistances;
  }

  int mid = points.size() / 2;
  Point midPoint = points[mid];

  vector<Point> left(points.begin(), points.begin() + mid);
  vector<Point> right(points.begin() + mid, points.end());

  // Combina los resultados de las llamadas recursivas con localDistances.
  set<double> leftDistances = paresCercanosAux(left, d, registeredDistances);
  localDistances.insert(leftDistances.begin(), leftDistances.end());

  set<double> rightDistances = paresCercanosAux(right, d, registeredDistances);
  localDistances.insert(rightDistances.begin(), rightDistances.end());

  vector<Point> strip; // Franja de puntos que cruzan la línea central (Strip).
                       // Es un vector de puntos que están a una distancia menor
                       // o igual a d de la línea central.
  for (const auto &point : points) {
    if (fabs(point.x - midPoint.x) < d) {
      strip.push_back(point);
    }
  }

  sort(strip.begin(), strip.end(), compareY);

  // Revisa los puntos en la franja y agrega las distancias a localDistances.
  for (size_t i = 0; i < strip.size(); ++i) {
    for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d;
         ++j) {
      double dist = calculateDistance3D(strip[i], strip[j]);
      if (dist <= d) {
        localDistances.insert(dist);
        registeredDistances.insert(dist);
      }
    }
  }

  return localDistances;
}

// Método de dividir y conquistar para encontrar pares cercanos
set<double> paresCercanosDC(vector<Point> &points, double d) {
  set<double> distances;
  sort(points.begin(), points.end(), compareX);
  distances = paresCercanosAux(points, d, distances);
  return distances;
}
