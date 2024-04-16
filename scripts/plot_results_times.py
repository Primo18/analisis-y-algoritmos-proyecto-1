import matplotlib.pyplot as plt
import pandas as pd

# Carga los datos desde el archivo CSV
data = pd.read_csv("./data/results_times.csv")


# Convertir tiempos de nanosegundos a milisegundos
data["FB_AverageTime(ms)"] = data["FB_AverageTime(ns)"] / 1e6
data["DC_AverageTime(ms)"] = data["DC_AverageTime(ns)"] / 1e6

# Crear gráfico con escalas logarítmicas en ambos ejes
plt.figure(figsize=(12, 7))
plt.plot(
    data["Size"],
    data["FB_AverageTime(ms)"],
    marker="o",
    linestyle="-",
    label="Fuerza Bruta",
)
plt.plot(
    data["Size"],
    data["DC_AverageTime(ms)"],
    marker="o",
    linestyle="-",
    label="Dividir y Conquistar",
)
plt.xscale("log")  # Escala logarítmica para el eje X
plt.yscale("log")  # Escala logarítmica para el eje Y
plt.title("Análisis de Rendimiento de Algoritmos para el Par de Puntos Más Cercano")
plt.xlabel("Número de Puntos (escala logarítmica)")
plt.ylabel("Tiempo (milisegundos, escala logarítmica)")
plt.grid(True, which="both", linestyle="--", linewidth=0.5)
plt.legend()
plt.show()
