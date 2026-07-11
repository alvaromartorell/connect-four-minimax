#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#include "Minimax.h"
#include "connect4.h"

int verificarVictoria(int tauler[N][N],int col,int fil){
    int jugador = tauler[fil][col];
    int contador=0;
    //miramos fila de la jugada
    for(int k=0;k<N-3;k++){
        contador=0;
        for(int i=0;i<4;i++){
            if(tauler[fil][i+k]==jugador){
                contador++;
            }else{
                break;
            }
        }
        if(contador==4){
            return 1;
        }
    }
    //miramos columna de la jugada
    for(int k=0;k<N-3;k++){
        contador=0;
        for(int i=0;i<4;i++){
            if(tauler[i+k][col]==jugador){
                contador++;
            }else{
                break;
            }
        }
        if(contador==4){
            return 1;
        }
    }
    //diagonal de abajo-derecha a arriba-izquierda
    for(int k=0;k<N;k++){
        contador=0;
        for(int i=0;i<4;i++){
            if((col-i+k)>=0 && (col-i+k)<N && (fil-i+k)>=0 && (fil-i+k)<N && tauler[fil-i+k][col-i+k]==jugador){
                    contador++;
            }else{break;}
        if(contador==4){return 1;}
        }
    }
    //diagonal de abajo-izquierda a arriba-derecha
    for(int k=0;k<N;k++){
        contador=0;
        for(int i=0;i<4;i++){
            if((col+i-k)<N && (col+i-k)>=0 && (fil-i+k)>=0 && (fil-i+k)<N && tauler[fil-i+k][col+i-k]==jugador){
                contador++;
            }else{break;}
        }
        if(contador==4){return 1;}
    }
    return 0;//la partida sigue

}

void hacerTirada_2(int tauler[N][N],int *victoria, int jugador){
    int columnaElegida;
    int columnaValida = 0;
    while(!columnaValida){
    printf("\nJugador %i: Elige una columna entre 1 y %i: ", jugador, N);
    scanf("%i", &columnaElegida);
    int COL = columnaElegida-1;
    if (columnaElegida > 0 && columnaElegida <= N) {
        for(int i=N-1; i>=0; i--){
            if(tauler[i][COL]==0 && columnaValida == 0){
                tauler[i][COL]=jugador;
                columnaValida=1;
                *victoria=verificarVictoria(tauler,COL,i);
                return;
            }
        }
        if(!columnaValida){
            printf("Columna esta llena.\n");}
        }else{
            printf("Columna no v�lida. Elige una columna entre 1 y %i.\n", N);
        }
    }
    return;
}

void hacerTirada(int tauler[N][N],int *victoria, int jugador, int fil,int col){
    if(jugador==1){
        int columnaElegida;
        int columnaValida = 0;
        while(!columnaValida){
        printf("\nJugador %i: Elige una columna entre 1 y %i: ", jugador, N);
        scanf("%i", &columnaElegida);
        int COL = columnaElegida-1;
        if (columnaElegida > 0 && columnaElegida <= N) {
            for(int i=N-1; i>=0; i--){
                if(tauler[i][COL]==0 && columnaValida == 0){
                    tauler[i][COL]=jugador;
                    columnaValida=1;
                    *victoria=verificarVictoria(tauler,COL,i);
                    return;
                }
            }
            if(!columnaValida){
                printf("Columna esta llena.\n");}
            }else{
                printf("Columna no v�lida. Elige una columna entre 1 y %i.\n", N);
            }
        }
    }else if(jugador==2 && fil >= 0 && fil < N && col >= 0 && col < N){
        tauler[fil][col]=jugador;
        *victoria=verificarVictoria(tauler,col,fil);
    }
    return;
}

void impTau(int tauler[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %i ", tauler[i][j]);
        }
        printf("\n");
    }
}

void impTauChar(char **tauler) {
    for (int i = 0; i < N*2+1; i++) {
        for (int j = 0; j < N*2+1; j++) {
            if(j==0){
                if(i%2==0){
                printf("%c%c",tauler[i][j],'\315');
                }else{printf("%c ",tauler[i][j]);}
            }else if(j==2*N){
                if(i%2==0){
                    printf("%c%c",'\315',tauler[i][j]);
                }else{printf(" %c",tauler[i][j]);}
            }else if(tauler[i][j] == '\315') {
                printf("%c%c%c", tauler[i][j], tauler[i][j], tauler[i][j]);
            } else if (tauler[i][j] == '\316' || tauler[i][j]=='\312' || tauler[i][j]=='\313') {
                printf("%c%c%c",'\315', tauler[i][j], '\315');
            } else {
                printf(" %c ", tauler[i][j]);
            }
        }
        printf("\n");
    }
    printf(" ");
    for(int i=0;i<N;i++){
        printf("   %i  ",i+1);
    }
    printf("\n");
}

void TauChar(int tauler[N][N]){
    char **TAULER = malloc((2*N+1) * sizeof(char *));
    for(int i=0;i<(2*N+1);i++){
        TAULER[i]=malloc((2*N+1) * sizeof(char));
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i==0){
                if(j==0){
                    TAULER[2*i][2*j]='\311';
                }else if(j==N){
                    TAULER[2*i][2*j]='\273';
                }else{
                    TAULER[2*i][2*j]='\313';
                }
            }else if(i==N){
                if(j==0){
                    TAULER[2*i][2*j]='\310';
                }else if(j==N){
                    TAULER[2*i][2*j]='\274';
                }else{
                    TAULER[2*i][2*j]='\312';
                }
            }else if(j==0 && i!=0 && i!=N){
                TAULER[2*i][2*j]='\314';
            }else if(j==N && i!=0 && i!=N){
                TAULER[2*i][2*j]='\271';
            }else{TAULER[2*i][2*j]='\316';}
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<N;j++){
            TAULER[2*i][2*j+1]='\315';
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<=N;j++){
            TAULER[2*i+1][2*j]='\272';
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(tauler[i][j]==1){
                TAULER[2*i+1][2*j+1]='X';
            }else if(tauler[i][j]==2){
                TAULER[2*i+1][2*j+1]='O';
            }else{TAULER[2*i+1][2*j+1]=' ';}
        }
    }
    impTauChar(TAULER);

    for(int i=0;i<(2*N+1);i++){
        free(TAULER[i]);
    }
    free(TAULER);

}

int tableroLleno(int tauler[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tauler[i][j] == 0) {
                return 0; // Aun hay espacios disponibles
            }
        }
    }
    return 1; // El tablero esta lleno
}

int tableroVacio(int tauler[N][N]) {
    int contador=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tauler[i][j] == 0) {
                contador++;
            }
        }
    }
    if(contador == N*N){return 1;} //tablero vacio
    return 0;
}

void jugar4eR(int Tauler[N][N],int victoria,int turno, int PF){
    int jugador;

    if(turno==1){
    while(!tableroLleno(Tauler) && !victoria){
        printf("\n");
        jugador=1;
        hacerTirada(Tauler,&victoria,jugador,-1,-1);
        TauChar(Tauler);
        if(victoria){
            printf("\n\n!!!El jugador humano ha ganado!!!\n\n");
            break;
        }

        jugador=2;

        //Pas 2:
        Node arrel;
        arrel.niv=0;
        arrel.fills=malloc(N*sizeof(Node*));
        printf("\n\nERROR 1\n\n");
        arrel.n_fills=N;
        inicializarTauler(arrel.tauler);


        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                arrel.tauler[i][j]=Tauler[i][j];
            }
        }
        crearArbre(&arrel,PF);

        double MEJOR_VALOR = minimax(&arrel,0,PF);
        printf("\n\nMejor valor es: %f\n",MEJOR_VALOR);

        Node *jugadaIA = minimaxSeleccionarMejorHijo(&arrel,0,PF);

        printf("\n\nMejor valor es: %f\n",jugadaIA->valor);
        if (jugadaIA == NULL) {
            printf("Error: No se encontr� una jugada para la IA.\n");
            break;
        }
        int filIA=-1, colIA=-1;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(Tauler[i][j] == 0 && Tauler[i][j]!=jugadaIA->tauler[i][j]){
                    filIA = i;
                    colIA = j;
                    break;
                }
            }
            if (filIA != -1 && colIA != -1) {break;}
        }
        printf("\nLa IA tira en la columna %i\n\n",colIA+1);
        hacerTirada(Tauler,&victoria,jugador,filIA,colIA);

        TauChar(Tauler);
        if(victoria){
            printf("\n\n!!!La IA ha ganado!!!\n\n");
            break;
        }
        liberarArbol(&arrel,PF);
    }
    }else if(turno==2){
    while(!tableroLleno(Tauler) && !victoria){
        printf("\n");

        jugador=2;

        Node arrel;
        arrel.niv=0;
        arrel.fills=malloc(N*sizeof(Node*));
        arrel.n_fills=N;
        inicializarTauler(arrel.tauler);



        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                arrel.tauler[i][j]=Tauler[i][j];
            }
        }

        if(tableroVacio(Tauler)){
            int CL = (int)(N/2) + rand()%((int)(N/2)) - 2;
            hacerTirada(Tauler,&victoria,jugador,N-1,CL);
            TauChar(Tauler);
        }else{
        crearArbre(&arrel,PF);

        double MEJOR_VALOR = minimax(&arrel,0,PF);
        printf("\n\nMejor valor es: %f\n",MEJOR_VALOR);

        Node *jugadaIA = minimaxSeleccionarMejorHijo(&arrel,0,PF);

        printf("\n\nMejor valor es: %f\n",jugadaIA->valor);

        if (jugadaIA == NULL) {
            printf("Error: No se encontró una jugada para la IA.\n");
            break;
        }
        int filIA=-1, colIA=-1;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(Tauler[i][j] == 0 && Tauler[i][j]!=jugadaIA->tauler[i][j]){
                    filIA = i;
                    colIA = j;
                    break;
                }
            }
            if (filIA != -1 && colIA != -1) {break;}
        }
        printf("\nLa IA tira en la columna %i\n\n",colIA+1);

        hacerTirada(Tauler,&victoria,jugador,filIA,colIA);
        TauChar(Tauler);
        if(victoria){
            printf("\n\n!!!La IA ha ganado!!!\n\n");
            break;
        }
        liberarArbol(&arrel,PF);
        }

        jugador=1;
        hacerTirada(Tauler,&victoria,jugador,-1,-1);
        TauChar(Tauler);
        if(victoria){
            printf("\n\n!!!El jugador humano ha ganado!!!\n\n");
            break;
        }

        printf("\n");
    }
    }
}

