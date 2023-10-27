import numpy as np
import matplotlib.pyplot as plt
from noise import snoise2

# Taille de la carte
width = 400
height = 200

# Créez une grille de bruit de Perlin pour la topographie
scale = 100.0
octaves = 6
persistence = 0.5
lacunarity = 2.0

world_map = np.zeros((height, width))
for i in range(height):
    for j in range(width):
        x = i / width - 0.5
        y = j / height - 0.5
        world_map[i][j] = snoise2(x * scale, y * scale, octaves=octaves, persistence=persistence, lacunarity=lacunarity)

# Normalisation des valeurs entre 0 et 1
world_map = (world_map - world_map.min()) / (world_map.max() - world_map.min())

# Affichez la carte générée
plt.imshow(world_map, cmap='terrain', interpolation='bilinear')
plt.colorbar()
plt.show()
