import pygame
import sys

# Initialisation de Pygame
pygame.init()

# Paramètres de la fenêtre
width, height = 400, 300

pygame.display.set_caption("Rond Vert")

# Couleurs
green = (0, 255, 0)

# Position du rond
x, y = width // 2, height // 2
radius = 50

# Boucle principale
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # Effacer l'écran
    screen.fill((255, 255, 255))

    # Dessiner le rond vert
    pygame.draw.circle(screen, green, (x, y), radius)

    # Mettre à jour l'affichage
    pygame.display.flip()
