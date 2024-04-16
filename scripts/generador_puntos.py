import pandas as pd
import numpy as np

np.random.seed(0)
num_points = 500000

x = np.random.randint(-1000, 1001, num_points)  # Coordenadas x
y = np.random.randint(-1000, 1001, num_points)  # Coordenadas y
z = np.random.randint(-1000, 1001, num_points)  # Coordenadas z

df = pd.DataFrame({"x": x, "y": y, "z": z})

# Eliminar duplicados
original_size = df.shape[0]
df = df.drop_duplicates()
new_size = df.shape[0]

# Guardar el DataFrame en un archivo CSV
df.to_csv("./data/points_data.csv", index=False)

print(
    f"Archivo CSV generado con éxito. Original size: {original_size}, After duplicates removed: {new_size}."
)
