#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Minimax.h"
#include "connect4.h"




int main(){

    /*int **tauler = malloc(N * sizeof(int *));
    for(int i=0;i<N;i++){
        tauler[i]=malloc(N * sizeof(int));
    }*/
    int tauler[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tauler[i][j]=0;
        }
    }

    printf("\nQue turno prefieres(1 o 2): ");
    int turnoHumano;
    scanf("%i",&turnoHumano);
    if(turnoHumano!=1 && turnoHumano!=2){
        printf("\nTurno elegido invalido.");
        return 0;
    }
    printf("\nElige la dificultad(2, 4 o 6): ");
    int profundidad;
    scanf("%i",&profundidad);
    if(profundidad!=2 && profundidad!=4 && profundidad!=6){
        printf("\nDificultad no valida.");
        return 0;
    }
    TauChar(tauler);
    int victoria=0;
    jugar4eR(tauler,victoria,turnoHumano,profundidad);

    return 0;
}
