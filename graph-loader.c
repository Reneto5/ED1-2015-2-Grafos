#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "graph-loader.h"

Graph* load_graph(char* filename){
	
	char line[256]; // Line buffer
	int size = 256; // For dynamic allocation of the edge buffer
	int read_lines = 0; 
	int highest_node_number_read = 0; // For determining the number of nodes in the graph
	EdgeBuffer* edge_buffer = malloc(size * sizeof(EdgeBuffer));
	FILE* graph_file = fopen(filename, "r");
	//printf("opening file at %p\n", graph_file);
	if (graph_file == NULL){
		printf("[graph-loader] Error while reading file \"%s\": %s\n", filename, strerror(errno));
		exit(1);
	}
	//printf("[graph-loader] loaded file %s successfully\n", filename);
	Graph* graph = calloc(1, sizeof(Graph));
	int node1, node2;
	float weight;
	
	// Read all the lines, parse out the values and store them into the dynamically-allocated 'edge_buffer'.
	while(fgets(line, 256, graph_file) != NULL){
		if(read_lines == size){
			//printf("reallocating; size = %d", size);
			size = size * 2;
			edge_buffer = realloc(edge_buffer, size * sizeof(EdgeBuffer)); // Dynamically allocate the edge buffer depending on the number of lines read
		}
		//printf("reading line %7d\r", read_lines + 1);
		sscanf(line, "%d %d %f", &node1, &node2, &weight);
		if(node1 > highest_node_number_read){
			highest_node_number_read = node1;
		}
		if(node2 > highest_node_number_read){
			highest_node_number_read = node2;
		}
		edge_buffer[read_lines].node1 = node1;
		edge_buffer[read_lines].node2 = node2;
		edge_buffer[read_lines].weight = weight;
		read_lines++;
	}
	fclose(graph_file);
	
	/*
	for(int i = 0; i < read_lines; i++){
		printf("%d %d %f ", edge_buffer[i].node1);
	}
	*/
	
	create_graph(graph, highest_node_number_read + 1);
	for(int i = 0; i <= read_lines; i++){
		//printf("writing edge %7d\r", i);
		create_edge(graph, edge_buffer[i].node1, edge_buffer[i].node2, edge_buffer[i].weight);
	}
	
	free(edge_buffer);
	return graph;

}