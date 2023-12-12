import matplotlib.pyplot as plt
import matplotlib.animation as animation
import random

# Générer un tableau aléatoire
array = random.sample(range(1, 101), 20)

# Fonction pour effectuer le tri par sélection
def selection_sort(array):
    n = len(array)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if array[j] < array[min_index]:
                min_index = j
        array[i], array[min_index] = array[min_index], array[i]
        yield array.copy()

# Fonction d'animation pour le tri
def update(frame):
    plt.cla()
    plt.bar(range(len(frame)), frame, color='pink')

# Créer une figure
fig, ax = plt.subplots()
ax.bar(range(len(array)), array, color='skyblue')

# Utiliser FuncAnimation pour animer le tri
animation = animation.FuncAnimation(fig, update, frames=selection_sort(array), repeat=False)

# Afficher l'animation
plt.show()
