#include <stdbool.h>
#define MAXNUMVERTICES 100
#define AN -1 // AN= aresta nula

typedef int Peso;
typedef struct
{
    bool mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
    int numVertices;
    int numArestas;
} Grafo;
bool inicializaGrafo(Grafo *grafo, int nv);