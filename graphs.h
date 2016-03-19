typedef struct graph Graph;

void create_graph(Graph* input_graph , int node_count);
void destroy_graph(Graph* input_graph);

int contains_edge(Graph* input_graph , int node1 , int node2);
void create_edge(Graph* input_graph , int node1 , int node2);
void remove_edge(Graph* input_graph , int node1 , int node2);