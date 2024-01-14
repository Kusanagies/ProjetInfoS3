import matplotlib.pyplot as plt
import mpld3
import numpy as np

def selection_sort_animation(data):
    n = len(data)

    # Créer la figure et l'axe
    fig, ax = plt.subplots()
    ax.set_title("Tri par Sélection")

    # Barres représentant les éléments à trier
    bars = ax.bar(range(n), data, color='lightblue')

    def update(frame):
        if frame < n:
            # Recherche de l'index minimum dans la partie non triée
            min_index = frame
            for j in range(frame + 1, n):
                if data[j] < data[min_index]:
                    min_index = j

            # Échange des éléments
            data[frame], data[min_index] = data[min_index], data[frame]

            # Mettre à jour les barres pour montrer le nouvel état
            for bar, height in zip(bars, data):
                bar.set_height(height)

    # Créer l'animation
    mpld3_data = mpld3.fig_to_html(fig)

    # Extraire le code JavaScript généré
    js_code_start = mpld3_data.find('<script>') + len('<script>')
    js_code_end = mpld3_data.find('</script>', js_code_start)
    js_code = mpld3_data[js_code_start:js_code_end]

    # Imprimez le code JavaScript
    print(js_code)

# Exemple d'utilisation
data_to_sort = np.random.randint(1, 100, 10)  # Remplacez cela par vos données
selection_sort_animation(data_to_sort)
