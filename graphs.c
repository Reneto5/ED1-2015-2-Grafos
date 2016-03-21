#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"
#include <limits.h>
#define  bool int
#include <float.h>

void create_graph(Graph* input_graph, int node_count) {

    input_graph->matrix = (float**) calloc(node_count, sizeof (float*));
    for (int i = 0; i < node_count; i++) {
        input_graph->matrix[i] = (float*) calloc(node_count, sizeof (float));
    }
    input_graph->node_count = node_count;
}

void destroy_graph(Graph* input_graph) {
    for (int i = 0; i < input_graph->node_count; i++) {
        free(input_graph->matrix[i]);
    }
    free(input_graph->matrix);
    input_graph->node_count = 0;
}

int contains_edge(Graph* input_graph, int node1, int node2) {
    return input_graph->matrix[node1][node2] > 0;
}

void create_node(Graph* input_graph) {
    int node_count = (input_graph->node_count + 1);

    input_graph->matrix = (float**) realloc(input_graph->matrix, sizeof (float*) * node_count);
    //End of each Column
    for (int i = 0; i < node_count; i++) {
        input_graph->matrix[i] = (float*) realloc(input_graph->matrix[i], sizeof (float) * node_count);
        input_graph->matrix[i][(node_count) - 1] = 0;
    }
    
    //New column
    for (int i = 0; i < node_count; i++) {
        input_graph->matrix[(node_count - 1)][i] = 0;
    }
    input_graph->node_count = node_count;
}

void remove_node(Graph* input_graph, int node) {
    int node_count = input_graph->node_count;

    //Substitute the removed node to the others on the column
    for (int i = 0; i < node_count; i++) {
        for (int y = 0; y < (node_count - node); y++) {
            input_graph->matrix[i][(node + y)] = input_graph->matrix[i][(node + y + 1)];
        }
        input_graph->matrix[i] = (float*) realloc(input_graph->matrix[i], sizeof (float) * (node_count - 1));
    }

    //Substitute the removed pointer
    for (int i = 0; i < (node_count - node); i++) {
        input_graph->matrix[(node + i)] = input_graph->matrix[(node + i + 1)];
    }
    input_graph->matrix = (float**) realloc(input_graph->matrix, sizeof (float*) * (node_count - 1));
    input_graph->node_count = (node_count - 1);
}

void create_edge(Graph* input_graph, int node1, int node2, float weight) {
    input_graph->matrix[node1][node2] = weight;
    input_graph->matrix[node2][node1] = weight;
}

void remove_edge(Graph* input_graph, int node1, int node2) {
    input_graph->matrix[node1][node2] = 0;
    input_graph->matrix[node2][node1] = 0;
}

/* Deph first search */
void dfs(Graph* g, int v, bool visited[]) {

    float** matrix = g->matrix;
    visited[v] = 1;
    for (int i = 1; i <= g->node_count; i++) {
        if (matrix[v][i] > 0 && !visited[i]) {
            dfs(g, i, visited);
        }
    }

}

int degree(Graph* graph, int v) {
    int count = 0;
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->matrix[v][i] > 0) {
            count++;
        }
    }
    return count;
}

int isConnected(Graph* graph, int visited[]) {

    for (int i = 0; i < graph->node_count; i++) {
        visited[i] = 0;
    }
    dfs(graph, 1, visited);
    int count = 0;

    for (int i = 1; i <= graph->node_count; i++) {
        if (visited[i])
            count++;
    }
    return count == graph->node_count;
}

void printEdges(Graph* graph) {

    for (int i = 0; i < graph->node_count; i++) {
        for (int j = 0; j < (i+1); j++) {
            if (contains_edge(graph, i, j)) {
                printf("Edge: %d<->%d\tWeight: %f\n", i, j, (graph->matrix)[i][j]);
            }
        }
    }
}
