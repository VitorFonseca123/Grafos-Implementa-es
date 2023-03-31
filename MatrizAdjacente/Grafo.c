#include <stdio.h>
#include "GrafoPonderado.h"
#define verificar if(!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))return false;
#define vertice_invalido;
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
bool verificavalidadeVertice(int v, Grafo *grafo){
    if(v > grafo->numVertices){
        fprintf(stderr, "Erro: Numero do vertice (%d) maior que o numero total de vertices\
        (%d).\n", v, grafo->numVertices);
        return false;
    }
    if(v<=0){
        fprintf(stderr,"Erro: Numero de vertice (%d) deve ser positivo.\n", v);
        return false;
    }
    return true;

}
bool insereAresta(int v1, int v2, Peso peso, Grafo *grafo){
    verificar;
    grafo->mat[v1][v2]=peso;
    grafo->numArestas++;
    return true;
}
bool existeAresta(int v1, int v2, Grafo *grafo){
   verificar
    if(grafo->mat[v1][v2]==AN) return false;
    return true;
}
Peso obtemPesoAresta(int v1, int v2, Grafo *grafo){
    verificar;
    return grafo->mat[v1][v2];
}
bool removeAresta(int v1, int v2, Peso *peso, Grafo *grafo){
    verificar;

    if(grafo->mat[v1][v2]!=AN){
        *peso=grafo->mat[v1][v2];
        grafo->mat[v1][v2]=AN;
        grafo->numArestas--;
        return true;
    }
    return false;
}
bool listaAdjVazia(int v, Grafo *grafo){
    if(!verificavalidadeVertice(v, grafo)){
        return true;
    }
    int i;
    for(i=0;i<grafo->numVertices;i++){
        if(grafo->mat[v][i]!=AN)return false;
    }
    return true;
}
int proxListaAdj(int v, Grafo *grafo, int atual){
    if(!verificavalidadeVertice(v, grafo))return vertice_invalido;
    atual++;
    while((atual <= grafo->numVertices) && grafo->mat[v][atual]==AN){
        atual++;
    }
    if(atual>grafo->numVertices)return vertice_invalido;
    return atual;
}
/*int primeiroListaAdj(int v, Grafo *grafo){
    proxListaAdj(v, grafo, 0);
}*/
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