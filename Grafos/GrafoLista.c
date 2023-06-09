#include <stdio.h>
#include <stdlib.h>

#include "Grafolista.h"
#define branco 0
#define cinza 1
#define preto 2
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
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return false;

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
    
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return false;
    q = grafo->listaAdj[v1];
    while ((q != NULL) && (q->vdest != v2))
    {
        q = q->prox;
    }
    if (q != NULL)
        return q->Peso;
    return AN;
}
bool insereAresta(int v1, int v2, Peso peso, Grafo *grafo)
{
    Apontador p;
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return false;
    if (!(p = (Apontador)calloc(1, sizeof(Aresta))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao insereAresta\n");
        return false;
    }
    p->vdest = v2;
    p->Peso = peso;
    p->prox = grafo->listaAdj[v1];
    grafo->listaAdj[v1] = p;
    grafo->numArestas++;
    return true;
}
bool insereArestaNDirecional(int v1, int v2, Peso peso, Grafo *grafo)
{
    Apontador p;
    Apontador p2;
    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return false;
    if (!(p = (Apontador)calloc(1, sizeof(Aresta))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao insereAresta\n");
        return false;
    }
    if (!(p2 = (Apontador)calloc(1, sizeof(Aresta))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao insereAresta\n");
        return false;
    }
    p->vdest = v2;
    p2->vdest = v1;
    p->Peso = peso;
    p2->Peso= peso;
    p->prox = grafo->listaAdj[v1];
    //p2->prox = grafo_listaAdj[v2];
    grafo->listaAdj[v1] = p;
   // grafo->listaAdj[v2] = p2;
    grafo->numArestas++;
    return true;
}
bool removeArestaObtendoPeso(int v1, int v2, Peso *peso, Grafo *grafo)
{
    Apontador p, ant;

    if (!(verificavalidadeVertice(v1, grafo) && verificavalidadeVertice(v2, grafo)))
        return AN;

    p = grafo->listaAdj[v1];

    while ((p != NULL) && p->vdest != v2)
    {
        ant = p;
        p = p->prox;
    }
    // aresta existe

    if (p != NULL)
    {
        if (grafo->listaAdj[v1] == p)
            grafo->listaAdj[v1] = p->prox;
        else
            ant->prox = p->prox;
        *peso = p->Peso;
        p->prox = NULL;
        free(p);
        p = NULL;
        return true;
    }
    return false;
}
void liberaGrafo(Grafo *grafo)
{
    int v;
    Apontador p;

    // libera a lista de adjacencia de cada vertice
    for (v = 0; v <= grafo->numVertices; v++)
    {
        while ((p = grafo->listaAdj[v]) != NULL)
        {
            grafo->listaAdj[v] = p->prox;
            p->prox = NULL;
            free(p);
        }
    }
    grafo->numVertices = 0;
    // libera o vetor de ponteiros as listas de adj
    free(grafo->listaAdj);
    grafo->listaAdj = NULL;
}
void imprimeGrafo(Grafo *grafo)
{
    Apontador p;
    for (int i = 1; i <= grafo->numVertices; i++)
    {
        printf("%d ", i);
        while ((p = grafo->listaAdj[i]) != NULL)
        {
            printf("%d ", grafo->listaAdj[i]->vdest);
            p=p->prox;
        }
        printf("\n");
    }
}
int retornaApontador(Apontador p){
    
    return (p->vdest);
}

void visitaBP(int v, Grafo *grafo, int *tempo, int *cor, int *tdesc, int *tterm, int *antecessor)
{
   
    cor[v] = cinza;
    tdesc[v] = ++(*tempo); // é realmente ponteiro?estranho
    
    Apontador u = primeiroListaAdj(v, grafo); 
    if(u != VERTICE_INVALIDO){
        printf("%d",u->vdest);
    }

    while(u!=VERTICE_INVALIDO){
        int Uapont = retornaApontador(u);
        if (cor[Uapont] == branco)
        {
            antecessor[Uapont] = v;
            visitaBP(Uapont, grafo, tempo, cor, tdesc, tterm, antecessor);
        }
        u=proxListaAdj(v,grafo,u);
    }
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
        tdesc[v] = tterm[v] = 0; 
        antecessor[v] = AN;     
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

