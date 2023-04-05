#include <stdbool.h>

#define AN -1 //valor que representa uma aresta invalida
#define VERTICE_INVALIDO NULL //valor que representa uma vertice invalida
typedef Aresta* Apontador;
typedef int Peso;
typedef struct str_aresta
{
    int vdest;
    Peso Peso;
    struct  str_aresta *prox;
    
}Aresta;

typedef struct 
{
    Aresta **listaAdj;
    int numVertices;
    int numArestas;
}Grafo;

bool inicializaGrafo(Grafo* grafo, int nv);
bool insereAresta(Grafo* grafo, int in, int out, Peso peso);
bool existeAresta(Grafo* grafo, int in, int out);
bool removeAresta(Grafo* grafo, int in, int out, Peso* peso);
bool listaAdjVazia(Grafo* grafo, int vertice);
Apontador primeiroListaAdj(Grafo* grafo, int vertice);
Apontador proxListaAdj(Grafo* grafo, int vertice, Apontador atual);
void liberaGrafo(Grafo* grafo);
void imprimeGrafo(Grafo* grafo);

