#include <stdlib.h>
#include <stdio.h>
#include "graphs.h"
#include "graph-user-input.h"



void create_edge_option(Graph* input_graph) {
	int edge_quantity=0;
	int node1 = 0;
	int node2 = 0;
	float weight = 0;
	
	printf("Digite a quanditade de arestas a serem criadas\n");
	scanf("%d" , &edge_quantity);
	
	for(int i = 0 ; i < edge_quantity ; i++) {
		printf("Diginte as arestas e o custo de %d - (formato : vertice1 vertice2 custo)\n" , (i+1));
		scanf(" %d%d%f" , &node1 , &node2 , &weight);
		
		//Verify correct user input
		if(node1 > 0 && node2 > 0 && weight > 0 && node1 <= input_graph->node_count && node2 <= input_graph->node_count) {
			printf("Criando aresta de peso %f entre o vertice %d e o vertice %d\n" , weight , node1 , node2);
			create_edge(input_graph , (node1 ) , (node2 ), weight);
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
		scanf("%d %d" , &node1 , &node2);
		
		if(node1 > 0 && node2 > 0 && node1 <= input_graph->node_count && node2 <= input_graph->node_count) {
			printf("Removendo aresta de peso %f entre o vertice %d e o vertice %d\n" , input_graph->matrix[(node1)][(node2)] , node1 , node2);
			remove_edge(input_graph , (node1) , (node2));
		} else {
			printf("Erro na hora de remover a aresta.\n");
			break;
		}
		node1 = 0;
		node2 = 0;
	}
}
void create_path_options(Graph* graph ){
    int v1,v2;
    printf("Digite o primeiro vértice\n");
    scanf("%d",&v1);
    printf("Digite o segundo vértice\n");
    scanf("%d",&v2);
    if( v1 > 0 && v2 > 0 && v2<graph->node_count && v1<graph->node_count)
        isThereAPath(graph,v1,v2);
        else
        printf("Erro! Vertices devem ser positivos e menores que %d.",graph->node_count);
     
    
}

void create_general_options(Graph* graph){
    int flag; int visited[graph->node_count];
	printf("\nDigite o numero da opçao desejada, para sair do programa, digite 0.\n");
	printf("\n1. Inserir uma aresta\n2. Remover uma aresta\n3. Descobrir se um vertice s é assesivel a partir de um vertice d.\n4. Inserir um vertice\n5. Remover um vertice\n6. Saber se o grafo é conexo\n7. Listar vertices e seus custos\n");
	while(scanf("%d",&flag) && flag!= 0) {
	 switch(flag){
		
			case 1:
				create_edge_option(graph);
				printf("Digite uma nova opção(1-7) ou 0 para abortar o programa.:\n");
				break;
			case 2:
				remove_edge_option(graph);
				printf("Digite uma nova opção(1-7) ou 0 para abortar o programa.:\n");
				break;
			case 3:
			    create_path_options(graph);
			    printf("\nDigite uma nova opção(1-7) ou 0 para abortar o programa.:\n");
				break;
			case 6:
			    if(isConnected(graph,visited)) printf("O grafo é conexo.");
			    else printf("O grafo não é conexo.");
			    printf("\nDigite uma nova opção(1-7) ou 0 para abortar o programa.:\n");
			    break;
			case 7:
			    printEdges(graph);
			    printf("\nDigite uma nova opção(1-7) ou 0 para abortar o programa.:\n");
			    break;
			default:
			    printf("Digite uma opção válida(1-7).\n");
	 }
	}
    
}

