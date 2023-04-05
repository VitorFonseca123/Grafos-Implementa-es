#include <stdio.h>
#include <stdlib.h>

#include "Grafo_listaAdj.h"

bool inicializaGrafo(Grafo *grafo, int nv){
    if(nv<=0){
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Número de vertices deve ser positivo");
        return false;
    }
    grafo->numVertices = nv;
    if (!(grafo->listaAdj = (Aresta**)calloc(nv+1, sizeof(Aresta*))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao inicializaGrafo");
        return false;
    }
    grafo->numArestas=0;
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
bool listaAdjVazia(Grafo* grafo, int v){
    if(!verificavalidadeVertice(v, grafo)) return false;
    return (grafo->listaAdj[v]==NULL);
}
