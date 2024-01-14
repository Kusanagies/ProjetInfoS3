#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, FILE *csvFile) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Écrire l'étape dans le fichier CSV
        fprintf(csvFile, "%d", arr[0]);
        for (int i = 1; i <= high; i++) {
            fprintf(csvFile, ";%d", arr[i]);
        }
        fprintf(csvFile, "\n");

        quickSort(arr, low, pi - 1, csvFile);
        quickSort(arr, pi + 1, high, csvFile);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <array_size>\n", argv[0]);
        return 1;
    }

    int taille = atoi(argv[1]);  // Convert the command-line argument to an integer
    int i, tmp;
    int arr[taille];

    int n = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < taille; i++) {
        tmp = rand() % 100;
        arr[i] = tmp;
    }

    FILE *outputFile = fopen("output.csv", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Écrire le tableau initial dans le fichier CSV
    fprintf(outputFile, "%d", arr[0]);
    for (int i = 1; i < n; i++) {
        fprintf(outputFile, ";%d", arr[i]);
    }
    fprintf(outputFile, "\n");

    quickSort(arr, 0, n - 1, outputFile);

    // Fermer le fichier CSV
    fclose(outputFile);

    return 0;
}
