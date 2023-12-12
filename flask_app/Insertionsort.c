#include <stdio.h>


void insertionSort(int arr[], int n, FILE *outputFile) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Print the array to the file at the end of each iteration
        for (int k = 0; k < n; k++) {
            fprintf(outputFile, "%d", arr[k]);

            // Print a semicolon after each number, except the last one
            if (k < n - 1) {
                fprintf(outputFile, ";");
            }
        }
        fprintf(outputFile, "\n");
    }
}

//Le main va nous donner un fichier csv pour pouvoir donner les données des itérations aux fichiers python
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

    insertionSort(arr, taille, outputFile);

    for (int i = 0; i < taille; i++) {
        fprintf(outputFile, "%d;", arr[i]);
    }

    fclose(outputFile);

    return 0;
}