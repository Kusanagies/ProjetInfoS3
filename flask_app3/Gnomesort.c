#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void gnomeSort(int arr[], int n, FILE *outputFile) {
    int index = 0;

    while (index < n) {
        if (index == 0) {
            index++;
        }

        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            // Swap arr[index] and arr[index - 1]
            swap(&arr[index], &arr[index - 1]);
            index--;

            // Print the array to the file after each swap
            for (int k = 0; k < n; k++) {
                fprintf(outputFile, "%d;", arr[k]);
            }
            fprintf(outputFile, "\n");
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

    gnomeSort(arr, taille, outputFile);

    // Close the CSV file
    fclose(outputFile);

    return 0;

    return 0;
}
