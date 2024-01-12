#include <stdio.h>
#include <stdlib.h>  // Include this header for atoi function

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, FILE *outputFile) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                swap(&arr[j], &arr[j + 1]);

                // Write the current state of the array to the CSV file
                for (int k = 0; k < n; k++) {
                    fprintf(outputFile, "%d;", arr[k]);
                }
                fprintf(outputFile, "\n");
            }
        }
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

    // Write the original array to the CSV file
    for (int i = 0; i < taille; i++) {
        fprintf(outputFile, "%d;", arr[i]);
    }
    fprintf(outputFile, "\n");

    bubbleSort(arr, taille, outputFile);

    // Close the CSV file
    fclose(outputFile);

    return 0;
}
