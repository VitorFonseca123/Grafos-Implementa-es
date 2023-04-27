#include <stdio.h>
#include "GrafoMatriz.h"
#define branco 0
#define cinza 1
#define preto 2

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
        fprintf(stderr, "ERRO na chamada de inicicialização do grafo: Numero de vértices é maior do que o máximo permitido de %d.\n",
                MAXNUMVERTICES);
        return false;
    }
    if (nv <= 0)
    {
        fprintf(stderr, "ERRO na chamada de inicicialização do grafo: Numero de vertices negativo");
        return false;
    }
    grafo->numVertices = nv;
    grafo->numArestas = 0;

    for (i = 0; i < grafo->numVertices; i++)
    {
        for (j = 0; j < grafo->numVertices; j++)
        {
            grafo->mat[i][j] = AN;
        }
    }
    return true;
}
bool verificavalidadeVertice(int v, Grafo *grafo)
{
    if (v > grafo->numVertices)
    {
        fprintf(stderr, "Erro: Numero do vertice (%d) maior que o numero total de vertices\
        (%d).\n",
                v, grafo->numVertices);
        return false;
    }
    if (v < 0) // pode ser <= depende das regras do grafo. se ele começa em 0 ou 1
    {
        fprintf(stderr, "Erro: Numero de vertice (%d) deve ser positivo.\n", v);
        return false;
    }
    return true;
}
bool insereAresta(int v1, int v2, Peso peso, Grafo *grafo)
{
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return false;
    grafo->mat[v1][v2] = peso;
    grafo->numArestas++;
    return true;
}
bool insereArestaNDirecional(int v1, int v2, Peso peso, Grafo *grafo)
{
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return false;
    grafo->mat[v1][v2] = peso;
    grafo->mat[v2][v1] = peso;
    grafo->numArestas++;
    return true;
}
bool existeAresta(int v1, int v2, Grafo *grafo)
{
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return false;
    if (grafo->mat[v1][v2] == AN)
        return false;
    return true;
}
Peso obtemPesoAresta(int v1, int v2, Grafo *grafo)
{
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return false;
    return grafo->mat[v1][v2];
}
bool removeAresta(int v1, int v2, Peso *peso, Grafo *grafo)
{
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return false;

    if (grafo->mat[v1][v2] != AN)
    {
        *peso = grafo->mat[v1][v2];
        grafo->mat[v1][v2] = AN;
        grafo->numArestas--;
        return true;
    }
    return false;
}
bool listaAdjVazia(int v, Grafo *grafo)
{
    if (!verificavalidadeVertice(v, grafo))
    {
        return true;
    }
    int i;
    for (i = 0; i < grafo->numVertices; i++)
    {
        if (grafo->mat[v][i] != AN)
            return false;
    }
    return true;
}
Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual)
{
    if (!verificavalidadeVertice(v, grafo))
        return VERTICE_INVALIDO;
    atual++;
    while ((atual < grafo->numVertices) && grafo->mat[v][atual] == AN)
    {
        atual++;
    }
    if (atual >= grafo->numVertices)
        return VERTICE_INVALIDO;
    return atual;
}
Apontador primeiroListaAdj(int v, Grafo *grafo){
    int atual=0;
    if (!verificavalidadeVertice(v, grafo))
        return VERTICE_INVALIDO;
    while(grafo->mat[v][atual]==AN){
        atual++;
    }
    return atual;
}
/*int primeiroListaAdj(int v, Grafo *grafo){
    proxListaAdj(v, grafo, 0);
}*/

void imprimeGrafo(Grafo *grafo)
{
    for (int i = 0; i < grafo->numVertices; i++)
    {
        for (int j = 0; j < grafo->numVertices; j++)
        {
            printf("%d ", grafo->mat[i][j]);
        }
        printf("\n");
    }
}

void visitaBP(int v, Grafo *grafo, int *tempo, int *cor, int *tdesc, int *tterm, int *antecessor)
{
    cor[v] = cinza;
    tdesc[v] = ++(*tempo); // é realmente ponteiro?estranho
    
    Apontador u=primeiroListaAdj(v, grafo); //lembrar de implementar hoje!!!
   // printf("adj a %d: ",v);
    do{
        //printf("%d,",u);
         if (cor[u] == branco)
        {
            antecessor[u] = v;
            visitaBP(u, grafo, tempo, cor, tdesc, tterm, antecessor);
        }
        u=proxListaAdj(v,grafo,u); 
        
        //cont++;
    }while(u!=AN);
    tterm[v] = ++(*tempo); //??
    cor[v] = preto;
    //printf("\n");
}
void buscaProfundidade(Grafo *grafo)
{
    int cor[grafo->numVertices];   // branco 0, cinza 1, preto 2
    int tdesc[grafo->numVertices]; // tempo de descobrimento
    int tterm[grafo->numVertices]; // tempo de termino
    int antecessor[grafo->numVertices];

    int tempo = 0;

    for (int v = 0; v < grafo->numVertices; v++)
    {
        cor[v] = branco;
        tdesc[v] = tterm[v] = 0; // isso é válido?
        antecessor[v] = VERTICE_INVALIDO;      
    }

    
    for (int v = 0; v < grafo->numVertices; v++)
    {
        if (cor[v] == branco)
            visitaBP(v, grafo, &tempo, cor, tdesc, tterm, antecessor); //
    }
    for (int i = 0; i < grafo->numVertices; i++)
    {
        printf("%d: %d/%d\n", i, tdesc[i], tterm[i]);
    }
}
