#include <stdio.h>
#include "GrafoPonderado.h"

/*inicializar grafo
Chamada da função exemplo:
Grafo g;
inicializaGrafo(&g, 10);
*/
bool inicializaGrafo(Grafo *grafo, int nv)
{ // nv = numero de vertices
    int i, j;

    if (nv > MAXNUMVERTICES)
    {
        fprintf(stderr, "ERRO na chamada de inicicialização do grafo:\ 
            Numero de vértices é maior do que o máximo permitido de %d.\n",
                MAXNUMVERTICES);
        return false;
    }
    if (nv <= 0)
    {
        fprintf(stderr, "ERRO na chamada de inicicialização do grafo:\ 
            Numero de vertices negativo");
        return false;
    }
    grafo->numVertices = nv;
    grafo->numArestas = 0;

    for (i = 0; i <= grafo->numVertices; i++)
    {
        for (j = 0; j <= grafo->numVertices; j++)
        {
            grafo->mat[i][j] = AN;
        }
    }
    return true;
}
int main()
{
    Grafo g1;
    int numVert;
    inicializaGrafo(&g1, 10);
    // imprimeGrafo(&g1)

    do
    {
        printf("Digite o número de vértices do grafo\n");
        scanf("%d", &numVert);
    } while (!inicializaGrafo(&g1, numVert));

    return 0;
}