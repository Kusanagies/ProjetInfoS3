#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void printArrayToFile(int arr[], int n, FILE *outputFile) {
    for (int k = 0; k < n; k++) {
        fprintf(outputFile, "%d", arr[k]);

        // Print a semicolon after each number, but not after the last one
        if (k < n - 1) {
            fprintf(outputFile, ";");
        }
    }
    fprintf(outputFile, ";\n");  // Add a semicolon and a newline after the array
}

void bogoSort(int arr[], int n, FILE *outputFile, int maxIterations) {
    int iterations = 0;
    while (!isSorted(arr, n) && iterations < maxIterations) {
        // Shuffle the array randomly
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() % (n - i);
            swap(&arr[i], &arr[j]);
        }

        // Print the array to the file after each shuffle
        printArrayToFile(arr, n, outputFile);

        iterations++;
    }

    if (iterations == maxIterations) {
        printf("Bogo Sort reached the maximum number of iterations (%d).\n", maxIterations);
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

    for (i = 0; i < taille; i++) {
        tmp = rand() % 100;
        arr[i] = tmp;
    }

    FILE *outputFile = fopen("output.csv", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Print the initial array to the file
    printArrayToFile(arr, taille, outputFile);

    // Perform Bogo Sort with a maximum of 100 iterations and print the array after each shuffle
    bogoSort(arr, taille, outputFile, 100);

    fclose(outputFile);

    return 0;
}
