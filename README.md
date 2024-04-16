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
│   └── results_distances.csv        # Datos de distancia entre los puntos más cercanos
│   └── results_times.csv            # Datos de tiempos de ejecución de los algoritmos
│
├── scripts/                   # Scripts de utilidad, e.g., para graficación
│   ├── plot_results_times.py  # Grafica los tiempos de ejecución
│   ├── scatter_plot_distances.py   # Grafica las distancias entre los puntos más cercanos en 3D
│   └── generador_puntos.py         # Genera puntos aleatorios en 3D
│
├── build/                     # Archivos objeto y ejecutables
│
├── Makefile                   # Makefile para automatizar la compilación y otras tareas
│
└── README.md                  # Descripción del proyecto, instrucciones de uso
│   
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
    - Matplotlib (para graficación) 
    - Pandas (para manejo de datos tabulares) 
    - Numpy (para manejo de arreglos) 
    - mpl_toolkits (para graficación 3D) 

    ```bash
    pip install pandas numpy matplotlib mpl_toolkits
    ```


## Compilación y Ejecución

Para limpiar el proyecto, utiliza el siguiente comando en la terminal:

```bash
make clean
```

Para compilar el proyecto, utiliza el siguiente comando en la terminal:

```bash
make
```

Para ejecutar el programa compilado y realizar los experimentos:

```bash
make run
```

Este comando compilará el proyecto si es necesario y ejecutará el ejecutable resultante, almacenando los datos de rendimiento en los archivos `results_times.csv` y `results_distances.csv` en el directorio `data/`.

## Visualización de Datos

Para visualizar los datos de rendimiento con el script de Python proporcionado:

```python
python3 scripts/plot_results_times.py # Grafica los tiempos de ejecución
python3 scripts/scatter_plot_distances.py # Grafica las distancias entre los puntos más cercanos en 3D
```


## Autores

- Esteban Chandía
- Macarena Madrid
- [Daniel López](https://github.com/Primo18)

## Licencia

Este proyecto no tiene licencia.



