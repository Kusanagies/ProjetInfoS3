#include <stdio.h>

// Fonction pour échanger deux éléments dans un tableau
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour partitionner le tableau et retourner l'index du pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choix du pivot (dans cet exemple, le dernier élément)
    int i = (low - 1);  // Index du plus petit élément

    for (int j = low; j <= high - 1; j++) {
        // Si l'élément courant est plus petit que ou égal au pivot
        if (arr[j] <= pivot) {
            i++;  // Incrémente l'index du plus petit élément
            swap(&arr[i], &arr[j]);  // Échange arr[i] et arr[j]
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Échange l'élément suivant du plus petit élément avec le pivot
    return (i + 1);  // Retourne l'index du pivot après partitionnement
}

// Fonction de tri rapide
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitionne l'index du pivot
        int pi = partition(arr, low, high);

        // Trie les éléments avant et après la partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fonction pour afficher un tableau
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Exemple d'utilisation
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <array_size>\n", argv[0]);
        return 1;
    }

    int taille = atoi(argv[1]);  // Convert the command-line argument to an integer
    int i, tmp;
    int arr[taille];

    // Initialize array with random values
    for (i = 0; i < taille; i++) {
        tmp = rand() % 100;
        arr[i] = tmp;
    }

    // Open a CSV file for writing
    FILE *outputFile = fopen("output.csv", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the original array to the CSV file
    for (int i = 0; i < taille; i++) {
        fprintf(outputFile, "%d;", arr[i]);
    }
    fprintf(outputFile, "\n");

    quickSort(arr, taille, outputFile);

    // Close the CSV file
    fclose(outputFile);

    return 0;

}
