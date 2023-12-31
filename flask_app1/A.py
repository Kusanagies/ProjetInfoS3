import csv

# Spécifiez le chemin vers votre fichier CSV
chemin_du_fichier = '/root/projects/flask_app/output.csv'

# Initialisez un tableau pour stocker les données
tableau_de_valeurs = []

# Ouvrez le fichier CSV en mode lecture
with open(chemin_du_fichier, 'r') as fichier_csv:
    # Créez un objet lecteur CSV
    lecteur_csv = csv.reader(fichier_csv)

    # Parcourez les lignes du fichier CSV et ajoutez-les au tableau
    for ligne in lecteur_csv:
        tableau_de_valeurs.append(ligne)

# Affichez le tableau de valeurs
print(tableau_de_valeurs)