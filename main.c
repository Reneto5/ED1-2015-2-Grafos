#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"
#include "graph-loader.h"
#include "graph-user-input.h"

int main(int argc, char** argv) {
    if (argc == 2) {
        char* filename = argv[1];
        printf("Carregando...\n");
        Graph* graph = load_graph(filename);
        printf("Arquivo aberto: \"%s\".\n", filename);
        int node_count = graph->node_count;
        int edge_count = 0;
        printf("%d vertices encontrados.\n", node_count);
        for (int i = 0; i < node_count; i++) {
            for (int j = 0; j < node_count; j++) {
                if (contains_edge(graph, i, j)) {
                    edge_count++;
                }
                /*if(j == 0){
                        printf("Total edges found = %7d; checking edges from node %5d\r", edge_count >> 1, i);
                }*/
            }
        }
        printf("%d arestas encontradas.\n", edge_count >> 1);
        create_general_options(graph);
        return (EXIT_SUCCESS);
    } else {
        printf("Argumentos invalidos.\nUso: graphs [nome do arquivo]\n");
        return (EXIT_FAILURE);
    }
}

