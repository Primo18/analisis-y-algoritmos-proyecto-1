#include "Algorithms.h"
#include "Point.h"
#include <algorithm>

using namespace std;

// Método de fuerza bruta para encontrar pares cercanos
vector<PointPairDist> paresCercanosFB(const vector<Point> &points, double d) {
  vector<PointPairDist> results;

  for (size_t i = 0; i < points.size(); ++i) {
    for (size_t j = i + 1; j < points.size(); ++j) {
      double dist = calculateDistance3D(points[i], points[j]);
      if (dist <= d) {
        results.emplace_back(dist, make_pair(points[i], points[j]));
      }
    }
  }
  return results;
}

// Función auxiliar para el enfoque de dividir y conquistar
vector<PointPairDist>
paresCercanosAux(vector<Point> &points, double d,
                 vector<PointPairDist> &registeredDistances) {
  vector<PointPairDist> localDistances;

  if (points.size() <= 3) {
    auto baseCaseDistances = paresCercanosFB(points, d);
    registeredDistances.insert(registeredDistances.end(),
                               baseCaseDistances.begin(),
                               baseCaseDistances.end());
    return baseCaseDistances;
  }

  int mid = points.size() / 2;
  Point midPoint = points[mid];

  vector<Point> left(points.begin(), points.begin() + mid);
  vector<Point> right(points.begin() + mid, points.end());

  auto leftDistances = paresCercanosAux(left, d, registeredDistances);
  localDistances.insert(localDistances.end(), leftDistances.begin(),
                        leftDistances.end());

  auto rightDistances = paresCercanosAux(right, d, registeredDistances);
  localDistances.insert(localDistances.end(), rightDistances.begin(),
                        rightDistances.end());

  vector<Point> strip;
  for (const auto &point : points) {
    if (fabs(point.x - midPoint.x) < d) {
      strip.push_back(point);
    }
  }

  sort(strip.begin(), strip.end(), compareY);

  for (size_t i = 0; i < strip.size(); ++i) {
    for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d;
         ++j) {
      double dist = calculateDistance3D(strip[i], strip[j]);
      if (dist <= d) {
        localDistances.emplace_back(dist, make_pair(strip[i], strip[j]));
        registeredDistances.emplace_back(dist, make_pair(strip[i], strip[j]));
      }
    }
  }

  return localDistances;
}

// Método de dividir y conquistar para encontrar pares cercanos
vector<PointPairDist> paresCercanosDC(vector<Point> &points, double d) {
  vector<PointPairDist> distances;
  sort(points.begin(), points.end(), compareX);
  distances = paresCercanosAux(points, d, distances);
  return distances;
}
