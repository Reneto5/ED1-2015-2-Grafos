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
void create_edge(Graph* input_graph , int node1 , int node2, float weight);
void remove_edge(Graph* input_graph , int node1 , int node2);
void dfs(Graph* g,int v,bool visited[]);
int isConnected(Graph* graph,int visited[]);
int degree(Graph* graph,int v);
#endif /* GRAPHS_H */
