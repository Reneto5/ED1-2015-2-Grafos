#include "graphs.h"

struct edge{
	int node1;
	int node2;
	float weight;
};

typedef struct edge EdgeBuffer;

Graph* load_graph(char* filename);
