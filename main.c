#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"
#include "graph-loader.h"

int main(int argc, char** argv) {
	char* filename = "arestas.txt";
	printf("Loading...\n");
	Graph* graph = load_graph(filename);
	printf("Loaded file %s.\n", filename);
	int node_count = graph->node_count;
	int edge_count = 0;
	printf("Found %d nodes.\n", node_count);
	for(int i = 0; i < node_count; i++){
		for(int j = 0; j < node_count; j++){
			if(contains_edge(graph, i, j)){
				edge_count++;
			}
			/*if(j == 0){
				printf("Total edges found = %7d; checking edges from node %5d\r", edge_count >> 1, i);
			}*/
		}
	}
	printf("Found %d edges (%d matrix entries).\n", edge_count >> 1, edge_count);
    return (EXIT_SUCCESS);
}

