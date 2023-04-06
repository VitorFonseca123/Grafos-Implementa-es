#include <stdbool.h>
#define MAXNUMVERTICES 100
#define AN -1 // AN= aresta nula

typedef int Peso;
typedef struct
{
    Peso mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
    int numVertices;
    int numArestas;
} Grafo;
typedef int Apontador;
bool inicializaGrafo(Grafo *grafo, int nv);
bool verificavalidadeVertice(int v, Grafo *grafo);
bool insereAresta(int v1, int v2, Peso peso, Grafo *grafo);
bool existeAresta(int v1, int v2, Grafo *grafo);
Peso obtemPesoAresta(int v1, int v2, Grafo *grafo);
bool removeAresta(int v1, int v2, Peso *peso, Grafo *grafo);
bool listaAdjVazia(int v, Grafo *grafo);
Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual);