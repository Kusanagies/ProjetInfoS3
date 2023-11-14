#include <stdio.h>

void bubblesort(int * tab,int taille){
    int i,j,prout;
    for(i = 0;i < taille-1;i++){
        for(j = 0;j < taille-i-1;j++){
            if(tab[j] > tab[j+1]){
                prout = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = prout;
            }
        }
    }
}

void bubblesortOpt(int *tab,int taille){
    int lastswap;
    int swapped;
    int i,tmp;
    int n = taille;
    do{
	swapped = 0;
	lastswap = 0;
        for(i = 1;i < n;i++){
            if(tab[i-1] > tab[i]){
                tmp = tab[i-1];
                tab[i-1] = tab[i];
                tab[i] = tmp;
                lastswap = i;
                swapped = 1;
            }
        }
        n = lastswap;
    } while(swapped != 0);
}


int main() {
    printf("HELLO FROM SYLVAIN THE USER!\n");
    return 0;
}
