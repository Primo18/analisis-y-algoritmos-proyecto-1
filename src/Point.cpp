#include "Point.h"

// Calcula la distancia Euclidiana entre dos puntos en 3D
double calculateDistance3D(const Point &p1, const Point &p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  double dz = p1.z - p2.z;
  return std::sqrt(dx * dx + dy * dy + dz * dz);
}

// Función para comparar dos puntos basada en su coordenada x (usada para
// std::sort)
bool compareX(const Point &a, const Point &b) { return a.x < b.x; }

// Función para comparar dos puntos basada en su coordenada y (usada para
// std::sort)
bool compareY(const Point &a, const Point &b) { return a.y < b.y; }
