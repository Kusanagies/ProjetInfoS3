#include <stdio.h>

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
            fprintf(outputFile, "%d;", arr[k]);
        }
        fprintf(outputFile, "\n");
    }
}

int main() {
    int taille = 100;
    int arr[100];
    int i,tmp;
    for(i = 0;i < taille;i++){
        tmp = rand()%100;
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

    selectionSort(arr, taille, outputFile);

    for (int i = 0; i < taille; i++) {
        fprintf(outputFile, "%d;", arr[i]);
    }

    fclose(outputFile);

    return 0;
}

