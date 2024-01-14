# main.py

import pygame
import ctypes
import os

# Chargement de la bibliothèque C partagée
lib_path = os.path.abspath("votre_lib_c.so")  # Remplacez par le chemin absolu de votre bibliothèque C partagée
lib = ctypes.CDLL(lib_path)

# Définition de la fonction tri_rapide en Python
def tri_rapide(tab, d, f):
    if d < f:
        pivot = lib.partition(tab, d, f)
        tri_rapide(tab, d, pivot - 1)
        tri_rapide(tab, pivot + 1, f)

# Initialisation de Pygame
pygame.init()

# Paramètres de l'écran
screen_width, screen_height = 800, 600
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Tri Rapide Animation")

# Couleurs
white = (255, 255, 255)
black = (0, 0, 0)
red = (255, 0, 0)

# Fonction d'affichage des barres
def afficher_barres(tab):
    screen.fill(white)
    bar_width = screen_width // len(tab)

    for i, height in enumerate(tab):
        pygame.draw.rect(screen, black, (i * bar_width, screen_height - height, bar_width, height))

    pygame.display.flip()

# Fonction principale pour l'animation
def animation_tri_rapide(tab, d, f):
    if d < f:
        pivot = lib.partition(tab, d, f)
        afficher_barres(tab)
        pygame.time.delay(500)  # Délai pour l'animation
        animation_tri_rapide(tab, d, pivot - 1)
        animation_tri_rapide(tab, pivot + 1, f)

# Fonction principale
def main():
    # Votre tableau de données
    data = [50, 30, 70, 20, 90, 40, 60, 10, 80]

    # Afficher l'état initial
    afficher_barres(data)
    pygame.time.delay(1000)  # Délai pour l'animation

    # Appeler la fonction de tri_rapide
    tri_rapide(data, 0, len(data) - 1)

    # Afficher l'état final
    afficher_barres(data)
    pygame.time.delay(2000)  # Délai pour l'animation

    pygame.quit()

# Exécuter le programme
if __name__ == "__main__":
    main()
