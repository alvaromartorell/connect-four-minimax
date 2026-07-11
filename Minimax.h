#define N 8


typedef struct node{
    struct node **fills;
    int n_fills; //tamany de l'array din�mic
    int tauler[N][N];
    double valor;
    int niv;
}Node;


int verificarVictoriaNode(int tauler[N][N],int col,int fil);

double analizarTaulerNode(int tauler[N][N],int col,int fil,int tot);

void f_Heuristica_2(Node *fulla,int fil,int col);

//void impTau1(int tauler[N][N]);

//void TauChar1(int tauler[N][N]);

void inicializarTauler(int tauler[N][N]);

int calculaNumFills(int tauler[N][N]);

void copiarTauler(int destino[N][N], int origen[N][N]);

void ferTirada(int tauler[N][N],int col,int nivell);

int transformaFillAColumna(int tauler[N][N], int numDeFill);

Node* crearNode(Node *pare, int nivell, int numDeFill,int MAXnivell,int valor_node);

void crearNivellrecursiu(Node *pare, int nivell, int MAXnivell);

void crearArbre(Node* arrel,int MAXnivell);

void recorreArbreRecursiu(Node *p,int nivell,int MAXnivell);

double minimax(Node *nodo, int nivel,int profMAX);

Node* minimaxSeleccionarMejorHijo(Node *arrel, int nivel,int profMAX);

void liberarArbol(Node *nodo,int PF);

