#include <stdbool.h>
#define MAXNUMVERTICES 100

typedef struct
{
    bool mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
    int numVertices;
    int numArestas;
} Grafo;
bool inicializaGrafo(Grafo* grafo, int nv);
