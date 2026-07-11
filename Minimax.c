#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "Minimax.h"
#include "connect4.h"



int verificarVictoriaNode(int tauler[N][N],int col,int fil){
    int jugador=tauler[fil][col];
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


double analizarTaulerNode(int tauler[N][N],int fil,int col,int tot){
    double total=0;
    double tapa;
    int jugador=tauler[fil][col];
    int contador=0;
    //miramos fila de la jugada
    for(int k=0;k<tot;k++){
        contador=0;
        tapa=0;
        int ventanaValida = (col-k>=0) && (col-k+tot-1<N);
        if(ventanaValida){
            for(int i=0;i<tot;i++){
                int c = col+i-k;
                if(tauler[fil][c]==jugador){
                    contador++;
                }else if(tauler[fil][c]!=0){
                    tapa++;
                }
            }
            total=total+contador-tapa;
        }

    }


    //miramos columna de la jugada
    for(int k=0;k<tot;k++){
        contador=0;
        tapa=0;
        int ventanaValida = (fil-k>=0) && (fil-k+tot-1<N);
        if(ventanaValida){
            for(int i=0;i<tot;i++){
                int f = fil+i-k;
                if(tauler[f][col]==jugador){
                    contador++;
                }else if(tauler[f][col]!=0){
                    tapa++;
                }
            }
            total=total+contador-tapa;
        }

    }
    //diagonal de abajo-derecha a arriba-izquierda
    for(int k=0;k<tot;k++){
        contador=0;
        tapa=0;
        int ventanaValida = (fil-tot+1+k>=0) && (fil+k<N) && (col-tot+1+k>=0) && (col+k<N);
        if(ventanaValida){
            for(int i=0;i<tot;i++){
                int f = fil-i+k;
                int c = col-i+k;
                if(tauler[f][c]==jugador){
                    contador++;
                }else if(tauler[f][c]!=0){
                    tapa++;
                }
            }
            total=total+contador-tapa;
        }
    }

    //diagonal de abajo-izquierda a arriba-derecha
    for(int k=0;k<tot;k++){
        contador=0;
        tapa=0;
        int ventanaValida = (fil-tot+1+k>=0) && (fil+k<N) && (col-k>=0) && (col-k+tot-1<N);
        if(ventanaValida){
            for(int i=0;i<tot;i++){
                int f = fil-i+k;
                int c = col+i-k;
                if(tauler[f][c]==jugador){
                    contador++;
                }else if(tauler[f][c]!=0){
                    tapa++;
                }
            }
            total=total+contador-tapa;
        }
    }
    return total;

}
/*
double analizarTaulerNode(int tauler[N][N],int fil,int col,int tot){
    double total=0;
    double tapa;
    int jugador=tauler[fil][col];
    int contador=0;
    //miramos fila de la jugada
    for(int k=0;k<tot;k++){
        contador=0;
        tapa=0;
        if(col-k>=0 && col+k<N){
            for(int i=0;i<tot;i++){
                if(tauler[fil][col+i-k]==jugador){
                    contador++;
                }else if(tauler[fil][col+i-k]!=0){
                    tapa++;
                }
            }
            total=total+contador-tapa;
        }

    }


    //miramos columna de la jugada
    for(int k=0;k<tot;k++){
        contador=0;
        tapa=0;
        if(fil+k<N && fil-k>=0){
            for(int i=0;i<tot;i++){
                if(tauler[fil+i-k][col]==jugador){
                    contador++;
                }else if(tauler[i+k][col]!=0){
                    tapa++;
                }
            }
            total=total+contador-tapa;
        }

    }
    //diagonal de abajo-derecha a arriba-izquierda
    for(int k=0;k<tot;k++){
        contador=0;
        tapa=0;
        if(fil+k<N && col+k<N && col-k>=0 && fil-k>=0){
            for(int i=0;i<tot;i++){
                if(tauler[fil-i+k][col-i+k]==jugador){
                    contador++;
                }else if(tauler[fil-i+k][col-i+k]!=0){
                    tapa++;
                }
            }
            total=total+contador-tapa;
        }
    }

    //diagonal de abajo-izquierda a arriba-derecha
    for(int k=0;k<tot;k++){
        contador=0;
        tapa=0;
        if(fil-k>=0 && fil+k<N && col-k>=0 && col+k<N){
            for(int i=0;i<tot;i++){
                if(tauler[fil-i+k][col+i-k]==jugador){
                    contador++;
                }else if(tauler[fil-i+k][col+i-k]!=0){
                    tapa++;
                }
            }
            total=total+contador-tapa;
        }
    }
    return total;

}
*/

void f_Heuristica_2(Node *fulla,int fil,int col){
    double vR = rand()/(double)RAND_MAX;
    int victoria = verificarVictoriaNode(fulla->tauler,col,fil);
    if(victoria){
        fulla->valor = -10000+vR;
    }else{
        double tot_dos =analizarTaulerNode(fulla->tauler,fil,col,2);
        double tot_tres =analizarTaulerNode(fulla->tauler,fil,col,3);
        double tot_quatre =analizarTaulerNode(fulla->tauler,fil,col,4);
        double valorfulla = vR-tot_dos-tot_tres*10-tot_quatre*100;
        fulla->valor = valorfulla;
    }
}
/*
void impTau1(int tauler[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %i ", tauler[i][j]);
        }
        printf("\n");
    }
}
*/

void inicializarTauler(int tauler[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tauler[i][j] = 0;
        }
    }
}


int calculaNumFills(int tauler[N][N]){
    int contador=0;
    for(int i=0;i<N;i++){
        if(tauler[0][i]==0){
            contador++;
        }
    }
    return contador;
}

void copiarTauler(int destino[N][N], int origen[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            destino[i][j] = origen[i][j];
        }
    }
}

void ferTiradaM(int tauler[N][N],int col,int nivell,int *fila){
    int jugador = (nivell%2)+1;
    for(int i=N-1; i>=0;i--){
        if(tauler[i][col]==0){
            tauler[i][col]=jugador;
            *fila=i;
            break;
        }
    }
}

int transformaFillAColumna(int tauler[N][N], int numDeFill) {
    if (tauler[0][numDeFill] == 0){
    return numDeFill;
    }
    return -1;
}

Node* crearNode(Node *pare, int nivell, int numDeFill,int MAXnivell,int valor_node){

    Node *p=malloc(sizeof(Node));
    if (p == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria para el nodo.\n");
        exit(EXIT_FAILURE);
    }


    copiarTauler(p->tauler,pare->tauler);
    p->niv = nivell;
    p->n_fills = 0;
    p->fills = NULL;
    p->valor = valor_node;

    int columna=transformaFillAColumna(p->tauler,numDeFill);

    if(columna == -1){
        free(p);
        return NULL;
    }

    int fil;
    ferTiradaM(p->tauler,columna,nivell,&fil);
    valor_node+=1;
    p->valor=valor_node;

    if (verificarVictoriaNode(p->tauler, columna, fil)) {
        if(nivell == 1)  {p->valor=1e6;}
        else{
            p->n_fills = 0;
            p->fills = NULL;
            f_Heuristica_2(p,fil,columna);
            if(p->niv %2 == 1){
                p->valor=-p->valor;
            }
        }
        return p;
    }

    if(nivell < MAXnivell){

        p->n_fills=calculaNumFills(p->tauler);
        if(p->n_fills>0){
            p->fills=malloc(p->n_fills*sizeof(Node*));
            if (p->fills == NULL) {
                fprintf(stderr, "Error: no se pudo asignar memoria para los hijos del nodo.\n");
                free(p);
                exit(EXIT_FAILURE);
            }

            for(int i=0;i<p->n_fills;i++){
                p->fills[i]=NULL;
            }
        }else{p->fills = NULL;}


    }else{
        f_Heuristica_2(p,fil,columna);
        p->n_fills=0;
        p->fills=NULL;
    }
    return p;
}

//Quan creem un nivell, suposem que el node pare ja t� l'array de fills creat i el tauler actualitzat/
void crearNivellrecursiu(Node *pare, int nivell, int MAXnivell){

    if(nivell > MAXnivell){
        return;
    }

    if (pare->fills == NULL) {
        pare->n_fills = calculaNumFills(pare->tauler); // Determina el n�mero de hijos
        if (pare->n_fills > 0) {
            pare->fills = malloc(pare->n_fills * sizeof(Node *));
            if (pare->fills == NULL) {
                fprintf(stderr, "Error: no se pudo asignar memoria para los hijos.\n");
                exit(EXIT_FAILURE);
            }
            for (int i = 0; i < pare->n_fills; i++) {
                pare->fills[i] = NULL; // Inicializa cada puntero a NULL
            }
        }
    }


    int valor_node=0;
    pare->n_fills = 0;

    for (int i = 0; i < N; i++) {
        // Intentar crear un nodo hijo para cada columna
        if(transformaFillAColumna(pare->tauler, i) != -1){
            Node* fill = crearNode(pare, nivell, i, MAXnivell,valor_node);
            if (fill != NULL) {
                pare->fills[pare->n_fills] = fill;
                pare->n_fills++;
                valor_node++;
            }
        }
    }

    for(int i=0;i<pare->n_fills;i++){
        if(pare->fills[i] != NULL){
            crearNivellrecursiu(pare->fills[i],nivell+1,MAXnivell);
        }
    }
}

void crearArbre(Node* arrel,int MAXnivell){
    srand(time(NULL));


    crearNivellrecursiu(arrel,1,MAXnivell);
}

void recorreArbreRecursiu(Node *p,int nivell,int MAXnivell){
    for(int i=0;i<nivell;i++){
        printf(" ");
    }
    printf("Nv: %i  ->  ",p->niv);
    printf("%f\n",(double)p->valor);

    //TauChar1(p->tauler);
    for(int i=0;i<p->n_fills;i++){
        if(nivell<MAXnivell){
            recorreArbreRecursiu(p->fills[i],nivell+1,MAXnivell);
        }
    }
}


double minimax(Node *nodo, int nivel,int profMAX) {
    // Caso base: Si el nodo no tiene hijos, devuelve su valor (es una hoja)
    if (nodo->n_fills == 0 && nivel>=profMAX) {
        return nodo->valor;
    }

    double mejorValor;

    if (nivel % 2 == 0) {  // Nivel par: maximizar
        mejorValor = -1e6; // Suponiendo que los valores son positivos y en el rango [0, 1]
        for (int i = 0; i < nodo->n_fills; i++) {
            double valorHijo = minimax(nodo->fills[i], nivel + 1,profMAX);

            if (valorHijo > mejorValor) {
                mejorValor = valorHijo;
            }
        }
    } else {  // Nivel impar: minimizar
        mejorValor = 1e6; // Suponiendo que los valores est�n en el rango [0, 1]
        for (int i = 0; i < nodo->n_fills; i++) {
            double valorHijo = minimax(nodo->fills[i], nivel + 1,profMAX);
            if(nivel==1 && valorHijo==-1e6){
                return valorHijo;
            }
            if (valorHijo < mejorValor) {
                mejorValor = valorHijo;
            }
        }
    }

    return mejorValor;
}

Node* minimaxSeleccionarMejorHijo(Node *arrel, int nivel,int profMAX) {
    if (arrel->n_fills == 0) {
        return arrel;  // Devuelve el propio nodo si no tiene hijos
    }

    Node *mejorHijo = NULL;
    double mejorValor = -1e6;

    for (int i = 0; i < arrel->n_fills; i++) {
        double valorHijo = arrel->fills[i]->valor;
        if (valorHijo == 1e6) {
            return arrel->fills[i];  // Victoria para el jugador IA en este nivel
        }
        valorHijo = minimax(arrel->fills[i], nivel + 1,profMAX);
        if (valorHijo > mejorValor) {
            mejorValor = valorHijo;
            mejorHijo = arrel->fills[i];
        }
    }
    if(mejorHijo==NULL){
        int indexAleatori = rand() % arrel->n_fills;
        return arrel->fills[indexAleatori];
    }
    return mejorHijo;
}


void liberarArbol(Node *nodo, int PF) {
    if (nodo == NULL) {
        return;
    }
    /*for(int i=0;i<nodo->niv;i++){
        printf("\t");
    }*/
    //printf("Nivel %i con %i hijos. Valor: %f\n", nodo->niv, nodo->n_fills,nodo->valor);

    if(nodo->n_fills!=0 && nodo->niv < PF){
    for (int i = 0; i < nodo->n_fills; i++) {
         if (nodo->fills[i] != NULL) {
            //printf("Liberando hijo %i del nodo nivel %i\n", i, nodo->niv);
            liberarArbol(nodo->fills[i],PF);
        }
    }
    }

    if (nodo->fills != NULL) {
        free(nodo->fills); // Libera el array de hijos
    }
    if(nodo->niv >0){
        //el nodo arrel lo liberaremos en otra parte del codigo, concretamente en la funcion jugar4eR
        //NO LO LIBERABA CORRECTAMENTE EL NODO ARREL
        //printf("Liberando nodo actual de nivel %i. Valor: %f\n",nodo->niv, nodo->valor);
        free(nodo); // Libera el nodo actual
        //x�printf("Liberado correctamente\n\n");
    }
}

