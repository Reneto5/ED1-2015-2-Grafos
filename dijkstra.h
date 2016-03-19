#ifndef DIJKSTRA_H
#define DIJKSTRA_H
int minDistance(float dist[], bool sptSet[],int V);
void printPath(float parent[], int j);
float printSolution(float dist[], int n, float parent[],int src);
void shortestPathList(Graph* graph, int src);
#endif
