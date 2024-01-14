#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n, FILE *outputFile) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Print the array to the file at the end of each iteration
        for (int k = 0; k < n; k++) {
            fprintf(outputFile, "%d", arr[k]);

            // Print a semicolon after each number, but not after the last one
            if (k < n - 1) {
                fprintf(outputFile, ";");
            }
        }
        fprintf(outputFile, ";\n");  // Add a semicolon and a newline after each iteration
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

    // Print the initial array to the file
    for (int i = 0; i < taille; i++) {
        fprintf(outputFile, "%d", arr[i]);

        // Print a semicolon after each number, but not after the last one
        if (i < taille - 1) {
            fprintf(outputFile, ";");
        }
    }
    fprintf(outputFile, "\n");  // Add a semicolon and a newline after the initial array

    insertionSort(arr, taille, outputFile);

    fclose(outputFile);

    return 0;
}
