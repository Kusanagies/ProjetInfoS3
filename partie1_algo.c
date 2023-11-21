#include <stdlib.h>
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp, swapped;
    do {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = 1;
                // Vous pouvez ajouter du code pour enregistrer l'état de l'array
            }
        }
    } while (swapped);
}


int main(){
    printf("hello\n ");
    return 0;
}
