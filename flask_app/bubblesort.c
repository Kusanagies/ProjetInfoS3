#include <stdio.h>

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
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // Print the array to the file at the end of each iteration
        for (int k = 0; k < n; k++) {
            fprintf(outputFile, "%d;", arr[k]);
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

    bubbleSort(arr, taille, outputFile);

    for (int i = 0; i < taille; i++) {
        fprintf(outputFile, "%d;", arr[i]);
    }

    fclose(outputFile);

    return 0;
}