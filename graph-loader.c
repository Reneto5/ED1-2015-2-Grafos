#include <stdio.h>
#include <stdlib.h>
#include "graph-loader.h"
#include "graphs.h"

struct edge{
	int node1;
	int node2;
	float weight;
};

Graph* load_graph(char* filename){
	
	char line[255]; // Line buffer
	int size = 256; // For dynamic allocation of the edge buffer
	int read_lines = 0; 
	int highest_node_number_read = 0; // For determining the number of nodes in the graph
	edge_buffer = malloc(size * sizeof(EdgeBuffer));
	graph_file = fopen(filename, "r")
	graph* = calloc(sizeof(Graph));
	int node1, node2;
	float weight;
	
	// Read all the lines, parse out the values and store them into the dynamically-allocated 'edge_buffer'.
	while(fgets(line, 255, graph_file) != NULL){
		fscanf(graph_file, "%d %d %f", node1, node2, weight);
		if(node1 > highest_node_number_read){
			highest_node_number_read = node1;
		}
		edge_buffer[read_lines]->node1 = node1;
		edge_buffer[read_lines]->node2 = node2;
		edge_buffer[read_lines]->weight = weight;
		read_lines++;
		if(read_lines == size){
			size *= 2;
			realloc(edge_buffer, size * sizeof(EdgeBuffer)); // Dynamically allocate the edge buffer depending on the number of lines read
		}
	}
	fclose(graph_file);
	
	create_graph(graph, highest_node_number_read);
	for(int i = 0; i < read_lines; i++){
		create_edge(graph, edge_buffer->node1, edge_buffer->node2, edge_buffer->weight);
	}
	
	free(edge_buffer);
	return graph;

}