#include <stdio.h>
#include <stdlib.h>

#include "Grafo_listaAdj.h"

bool inicializaGrafo(Grafo *grafo, int nv)
{
    if (nv <= 0)
    {
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Número de vertices deve ser positivo");
        return false;
    }
    grafo->numVertices = nv;
    if (!(grafo->listaAdj = (Apontador *)calloc(nv + 1, sizeof(Apontador))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao inicializaGrafo");
        return false;
    }
    grafo->numArestas = 0;
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
    if (v <= 0)
    {
        fprintf(stderr, "Erro: Numero de vertice (%d) deve ser positivo.\n", v);
        return false;
    }
    return true;
}
bool listaAdjVazia(Grafo *grafo, int v)
{
    if (!verificavalidadeVertice(v, grafo))
        return false;
    return (grafo->listaAdj[v] == NULL);
}
Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual)
{
    if (atual == NULL)
    {
        fprintf(stderr, "atual == NULL\n");
        return VERTICE_INVALIDO;
    }
    return (atual->prox);
}
Aresta *primeiroListaAdj(int v, Grafo *grafo)
{
    return (grafo->listaAdj[v]);
}
bool existeAresta(int v1, int v2, Grafo *grafo)
{
    Apontador q;
    // if(!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))return false;
    verificar;
    q = grafo->listaAdj[v1];
    while ((q != NULL) && (q->vdest != v2))
    {
        q = q->prox;
    }
    if (q != NULL)
        return true;
    return false;
}
Peso obtemPeso(int v1, int v2, Grafo *grafo)
{
    Apontador q;
    // if(!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))return false;
    verificar;
    q = grafo->listaAdj[v1];
    while ((q != NULL) && (q->vdest != v2))
    {
        q = q->prox;
    }
    if (q != NULL)
        return q->Peso;
    return AN;
}
void insereAresta(int v1, int v2, Peso peso, Grafo * grafo){
    Apontador p;
    verificar;
    if(!(p=(Apontador)calloc(1,sizeof(Aresta)))){
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao insereAresta\n");
        return;
    }
    p->vdest=v2;
    p->Peso= peso;
    p->prox = grafo->listaAdj[v1];
    grafo->listaAdj[v1]=p;
    grafo->numArestas++;
}

