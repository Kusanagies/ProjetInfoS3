#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Custom comparison function for natural sort
int naturalCompare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    // Compare non-numeric parts lexicographically
    int result = strcmp(str1, str2);

    if (result == 0) {
        // If non-numeric parts are equal, compare the numeric parts
        int num1, num2;
        sscanf(str1, "%d", &num1);
        sscanf(str2, "%d", &num2);

        if (num1 < num2) {
            result = -1;
        } else if (num1 > num2) {
            result = 1;
        }
    }

    return result;
}

void naturalSort(char *arr[], int n, FILE *outputFile) {
    // Print the initial array to the file
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%s;", arr[i]);
    }
    fprintf(outputFile, "\n");

    // Sort and print at each step
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (naturalCompare(&arr[j], &arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }

        // Print the array to the file after sorting
        for (int k = 0; k < n; k++) {
            fprintf(outputFile, "%s;", arr[k]);
        }
        fprintf(outputFile, "\n");
    }
}

int main() {
    int taille = 100;
    char *arr[100];
    char buffer[256];

    // Generate random alphanumeric strings
    for (int i = 0; i < taille; i++) {
        sprintf(buffer, "%d", rand() % 100);
        arr[i] = strdup(buffer);
    }

    FILE *outputFile = fopen("output.csv", "w");
    if (outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Call naturalSort to perform sorting and print at each step
    naturalSort(arr, taille, outputFile);

    // Close the file
    fclose(outputFile);

    // Free memory
    for (int i = 0; i < taille; i++) {
        free(arr[i]);
    }

    return 0;
}
