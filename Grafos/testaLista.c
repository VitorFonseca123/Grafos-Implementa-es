// #include "GrafoMatriz.h"
#include "GrafoLista.h"
#include <stdio.h>

int main()
{
    Grafo g1;
    int numVertices;
    int v1, v2;
    Peso peso;
    do
    {
        printf("Digite o numero de vertices do Grafo\n");
        scanf("%d", &numVertices);
    } while (!(inicializaGrafo(&g1, numVertices)));
    imprimeGrafo(&g1);
    printf("Digite o numero de arestas do Grafo\n");
    scanf("%d", &numVertices);
    int tipoMatriz=0;//0 direcional, 1 não direcional
    /*for (int i = 0; i < numVertices; i++)
    {
        printf("Digite a linha\n");
        scanf("%d", &v1);
        printf("Digite a coluna\n");
        scanf("%d", &v2);
        //printf("Digite o peso da aresta\n");
        //scanf("%d", &peso);
        //tipoMatriz
        if(tipoMatriz==0)insereAresta(v1, v2, 1, &g1);
        else insereArestaNDirecional(v1, v2, 1, &g1);
        

    }*/
    if(tipoMatriz==0){
            insereAresta(1, 2, 1, &g1);
            insereAresta(2, 3, 1, &g1);
            insereAresta(3, 1, 1, &g1);
            insereAresta(3, 3, 1, &g1);
            insereAresta(4, 3, 1, &g1);
        }
        else{
            insereAresta(1, 2, 1, &g1);
            insereAresta(2, 3, 1, &g1);
            insereAresta(3, 1, 1, &g1);
            insereAresta(3, 3, 1, &g1);
            insereAresta(4, 3, 1, &g1);
        } 
    imprimeGrafo(&g1);
    printf("\n");
    buscaProfundidade(&g1);
    

    return 0;
}