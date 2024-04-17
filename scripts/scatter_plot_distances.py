import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

# Cargar datos directamente en el formato adecuado
data = pd.read_csv(
    "./data/results_distances.csv",
    skiprows=1,
    names=["size", "method", "x1", "y1", "z1", "x2", "y2", "z2", "distance"],
)

# Convertir datos a numéricos (puede ser necesario dependiendo de cómo se estén leyendo los datos)
data[["x1", "y1", "z1", "x2", "y2", "z2", "distance"]] = data[
    ["x1", "y1", "z1", "x2", "y2", "z2", "distance"]
].apply(pd.to_numeric)

# Crear figura para gráficos
fig = plt.figure(figsize=(16, 8))

# Gráfico 3D de puntos
ax = fig.add_subplot(121, projection="3d")
ax.scatter(data["x1"], data["y1"], data["z1"], color="b", label="Point 1")
ax.scatter(data["x2"], data["y2"], data["z2"], color="r", label="Point 2")
ax.set_title("3D Scatter Plot de Puntos para una distancia menor a 3.0")
ax.set_xlabel("X Coordinate")
ax.set_ylabel("Y Coordinate")
ax.set_zlabel("Z Coordinate")
ax.legend()

# Histograma de distancias
ax2 = fig.add_subplot(122)
ax2.hist(data["distance"], bins=30, color="green", alpha=0.7)
ax2.set_title("Histogram of Distances")
ax2.set_xlabel("Distance")
ax2.set_ylabel("Frequency")

# Mostrar gráficos
plt.tight_layout()
plt.show()
