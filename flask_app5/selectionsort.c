#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n, FILE *outputFile) {
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++) {
        // Assume the current index is the minimum
        minIndex = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(&arr[i], &arr[minIndex]);
        
        for (int k = 0; k < n; k++) {
            fprintf(outputFile, "%d", arr[k]);

            // Print a semicolon after each number, but not after the last one
            if (k < n - 1) {
                fprintf(outputFile, ";");
            }
        }
        fprintf(outputFile, ";\n");
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

    selectionSort(arr, taille, outputFile);

    fclose(outputFile);

    return 0;
}
