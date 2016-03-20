#include <stdlib.h>
#include <stdio.h>
#include "graphs.h"
#include "graph-user-input.h"

void create_edge_option(Graph* input_graph) {
	int edge_quantity = 0;
	int node1 = 0;
	int node2 = 0;
	float weight = 0;
	
	printf("Digite a quanditade de arestas a serem criadas\n");
	scanf(" %d" , &edge_quantity);
	
	for(int i = 0 ; i < edge_quantity ; i++) {
		printf("Diginte as arestas e o custo de %d - (formato : vertice1 vertice2 custo)\n" , (i+1));
		scanf(" %d%d%f" , &node1 , &node2 , &weight);
		
		//Verify correct user input
		if(node1 > 0 && node2 > 0 && weight > 0 && node1 <= input_graph->node_count && node2 <= input_graph->node_count) {
			printf("Criando aresta de peso %f entre o vertice %d e o vertice %d\n" , weight , node1 , node2);
			create_edge(input_graph , (node1 - 1) , (node2 - 1), weight);
		} else {
			printf("Erro na hora de remover a aresta\n");
			break;
		}
		node1 = 0;
		node2 = 0;
		weight = 0;
	}
}


void remove_edge_option(Graph* input_graph) {
	int edge_quantity = 0;
	int node1 = 0;
	int node2 = 0;
	
	printf("Digite a quantidade de arestas a serem removidas\n");
	scanf("%d" , &edge_quantity);
	
	for(int i = 0 ; i < edge_quantity; i++) {
		printf("Digite a aresta a ser removida de %d- (formato : vertice1 vertice2)\n" , (i+1));
		scanf(" %d[^ ]%d" , &node1 , &node2);
		
		if(node1 > 0 && node2 > 0 && node1 <= input_graph->node_count && node2 <= input_graph->node_count) {
			printf("Removendo aresta de peso %f entre o vertice %d e o vertice %d\n" , input_graph->matrix[(node1-1)][(node2-1)] , node1 , node2);
			remove_edge(input_graph , (node1-1) , (node2-1));
		} else {
			printf("Erro na hora de remover a aresta\n");
			break;
		}
		node1 = 0;
		node2 = 0;
	}
}
void create_general_options(Graph* graph){
    int flag;
	printf("\nDigite o numero da opçao desejada, para sair do programa, digite 0.\n");
	printf("\n1. Inserir uma aresta\n2. Remover uma aresta\n3. Descobrir se um vertice s é assesivel a partir de um vertice d.\n4. Inserir um vertice\n5. Remover um vertice\n");
	while(scanf("%d",&flag) && flag!= 0) {
	 switch(flag){
		
			case 1:
				create_edge_option(graph);
				printf("Digite uma nova opção(1-5):\n");
				break;
			case 2:
				remove_edge_option(graph);
				printf("Digite uma nova opção(1-5):\n");
				break;
	 }
    }
    
}
