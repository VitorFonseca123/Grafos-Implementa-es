#include "GrafoMatriz.h"
// #include "Grafo_listaAdj.h"
#include <stdio.h>

int main()
{
    Grafo g1;
    int numVertices;
    int v1, v2;
    Peso peso;
    // inicializaGrafo(&g1, 10);

    do
    {
        printf("Digite o numero de vertices do Grafo\n");
        scanf("%d", &numVertices);
    } while (!(inicializaGrafo(&g1, numVertices)));

    for (int i = 0; i <= numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", g1.mat[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i <= numVertices; i++)
    {
        printf("Digite a linha\n");
        scanf("%d", &v1);
        printf("Digite a coluna\n");
        scanf("%d", &v2);
        printf("Digite o peso da aresta\n");
        scanf("%d", &peso);
        insereAresta(v1, v2, peso, &g1);
    }
    for (int i = 0; i <= numVertices; i++)
    {
        for (int j = 0; j <= numVertices; j++)
        {
            printf("%d ", g1.mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
