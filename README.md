# Proyecto 1 de Análisis de Algoritmos (2024-1) UdeC

Este proyecto implementa y compara dos enfoques diferentes para encontrar pares de puntos con una distancia mínima en un conjunto de datos tridimensional. Los métodos implementados son el algoritmo de fuerza bruta y el algoritmo de dividir para conquistar.

## Estructura del Directorio

```
MyProject/
│
├── src/                   # Todos los archivos de código fuente (.cpp)
│   ├── main.cpp
│   ├── Algorithms.cpp
│   ├── ExperimentRunner.cpp
│   ├── FileOperations.cpp
│   └── Point.cpp
│
├── include/               # Todos los archivos de cabecera (.h)
│   ├── Point.h
│   ├── Algorithms.h
│   ├── FileOperations.h
│   └── ExperimentRunner.h
│
├── data/                  # Datos usados y generados por el programa
│   ├── points_data.csv    # Datos de entrada
│   └── results.csv        # Datos de salida
│
├── scripts/               # Scripts de utilidad, e.g., para graficación
│   └── plot_results.py
│
├── build/                 # Archivos objeto y ejecutables
│
├── Makefile               # Makefile para automatizar la compilación y otras tareas
│
└── README.md              # Descripción del proyecto, instrucciones de uso
```

## Dependencias

El proyecto requiere las siguientes herramientas y bibliotecas:

- C++ Compiler (GCC recomendado, versión 11 o superior)
- GNU Make
- Python 3 (para scripts de análisis y visualización)

## Compilación y Ejecución

Para compilar el proyecto, utiliza el siguiente comando en la terminal:

```bash
make
```

Para ejecutar el programa compilado y realizar los experimentos:

```bash
make run
```

Este comando compilará el proyecto si es necesario y ejecutará el ejecutable resultante, almacenando los datos de rendimiento en `data/results.csv`.

## Visualización de Datos

Para visualizar los datos de rendimiento con el script de Python proporcionado:

```bash
python3 scripts/plot_results.py
```


## Autor

- [Daniel López](https://github.com/Primo18)

## Licencia

Este proyecto no tiene licencia.



