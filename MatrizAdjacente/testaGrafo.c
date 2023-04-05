//#include "GrafoPonderado.h"
#include "Grafo_listaAdj.h"
#include <stdio.h>

int main(){
    Grafo g1;
    int numVertices;

    //inicializaGrafo(&g1, 10);

    do{
        printf("Digite o numero de vertices do Grafo\n");
        scanf("%d", &numVertices);
    }while(!(inicializaGrafo(&g1, numVertices)));

    return 0;
}
