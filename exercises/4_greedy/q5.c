#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TOWER_RADIUS 4
#define TOWER_DIAMETER 8

int main(){

    int *torres_local,
        *estrada,
        tamanho,
        torres=0,
        i=0;

    srand ( time(NULL) );

    printf("Insira o tamanho da estrada:\n");
    scanf("%d", &tamanho);

    torres_local = malloc(tamanho/TOWER_DIAMETER * (sizeof(int)));
    estrada = malloc(tamanho * (sizeof(int)));
    for (i=0; i< tamanho; i++) estrada[i] = rand() % 2;

    printf("\nEstrada preenchida randomicamente: 0 = km vazio, 1 = casa\n\n");
    for (i=0; i< tamanho; i++) printf("[%d]", estrada[i]);
    printf("\n");

    i=0;
    while(i<tamanho){
      if(estrada[i]==1){
        if(i+TOWER_RADIUS<tamanho) torres_local[torres] = i+TOWER_RADIUS;
        else torres_local[torres] = tamanho;
        torres++;
        i=i+TOWER_DIAMETER;
      }
      else i++;
    }

    printf("\n%d torres alocadas nos quilometros \n", torres);
    for(i=0; i<torres; i++) printf("%d, ", torres_local[i]);
  }
