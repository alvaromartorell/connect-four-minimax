//#define N 8

int verificarVictoria(int tauler[N][N],int col,int fil);

void hacerTirada_2(int tauler[N][N],int *victoria, int jugador);

void hacerTirada(int tauler[N][N],int *victoria, int jugador, int fil,int col);

void impTau(int tauler[N][N]);

//void impTauChar(char tauler[N][N]);

void TauChar(int tauler[N][N]);

int tableroLleno(int tauler[N][N]);

int tableroVacio(int tauler[N][N]);

void jugar4eR_2(int tauler[N][N],int victoria);

void jugar4eR(int tauler[N][N],int victoria,int turno,int PF);
