#include "FileOperations.h"
#include <fstream>
#include <sstream>

using namespace std;

vector<Point> readPointsFromFile(const string &filename) {
  vector<Point> points;
  ifstream file(filename); // Abre el archivo en modo lectura
  string line;             // Almacena cada línea del archivo
  while (getline(file, line)) {
    stringstream ss(line); // Convierte la línea en un flujo de entrada
    Point point;
    char delimiter; // Delimitador entre las coordenadas x, y, z
    if (ss >> point.x >> delimiter >> point.y >> delimiter >> point.z) {
      points.push_back(point);
    }
  }
  return points;
}
