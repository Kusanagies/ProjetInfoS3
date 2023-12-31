#include <stdio.h>

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

int main() {
    int taille = 50;
    int arr[50  ];
    int i, tmp;
    for (i = 0; i < taille; i++) {
        tmp = rand() % 100;
        arr[i] = tmp;
    }
    FILE *outputFile = fopen("output.csv", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < taille; i++) {
        fprintf(outputFile, "%d;", arr[i]);
    }
    fprintf(outputFile, "\n");

    gnomeSort(arr, taille, outputFile);

    for (int i = 0; i < taille; i++) {
        fprintf(outputFile, "%d;", arr[i]);
    }

    fclose(outputFile);

    return 0;
}
