#include <stdbool.h>

#define AN -1                 // valor que representa uma aresta invalida
#define VERTICE_INVALIDO NULL // valor que representa uma vertice invalida
#define verificar                                                                    \
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo))) \
        return false;
typedef int Peso;
typedef struct str_aresta
{
    int vdest;
    Peso Peso;
    struct str_aresta *prox;

} Aresta;
typedef Aresta *Apontador;
typedef struct
{
    Apontador *listaAdj;
    int numVertices;
    int numArestas;
} Grafo;

bool inicializaGrafo(Grafo *grafo, int nv);
bool insereAresta(int v1, int v2, Peso peso, Grafo *grafo);
bool existeAresta(int v1, int v2, Grafo *grafo);
bool removeAresta(int v1, int v2, Grafo *grafo, Peso *peso);
bool listaAdjVazia(Grafo *grafo, int vertice);
Apontador primeiroListaAdj(int v, Grafo *grafo);
Apontador proxListaAdj(int vertice, Grafo *grafo, Apontador atual);
void liberaGrafo(Grafo *grafo);
void imprimeGrafo(Grafo *grafo);
