// quicksort.c
#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int low, int high, int step);

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5}; // Votre tableau de données

    // Générez un graphique initial
    quicksort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, 0);

    return 0;
}

void quicksort(int arr[], int low, int high, int step) {
    // Implémentation du tri rapide ici...

    // Utilisez matplotlib pour générer un graphique et enregistrez-le
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "set terminal png\n");
    fprintf(gnuplotPipe, "set output 'quicksort_%d.png'\n", step);
    fprintf(gnuplotPipe, "plot '-' with lines\n");
    for (int i = low; i <= high; i++) {
        fprintf(gnuplotPipe, "%d %d\n", i, arr[i]);
    }
    fprintf(gnuplotPipe, "e\n");
    fflush(gnuplotPipe);
    fclose(gnuplotPipe);
}
