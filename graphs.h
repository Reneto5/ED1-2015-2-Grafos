#ifndef GRAPHS_H
#define GRAPHS_H
#define bool int
struct graph {
    int node_count;
    float** matrix;
};

typedef struct graph Graph;

void create_graph(Graph* input_graph , int node_count);
void destroy_graph(Graph* input_graph);

int contains_edge(Graph* input_graph , int node1 , int node2);
void create_node(Graph* input_graph);
void remove_node(Graph* input_graph , int node);
void create_edge(Graph* input_graph , int node1 , int node2, float weight);
void remove_edge(Graph* input_graph , int node1 , int node2);
void dfs(Graph* g,int v,bool visited[]);
int isConnected(Graph* graph,int visited[]);
int degree(Graph* graph,int v);
void printEdges(Graph* graph);
#endif /* GRAPHS_H */
