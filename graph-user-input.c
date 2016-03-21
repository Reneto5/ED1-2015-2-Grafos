#include <stdlib.h>
#include <stdio.h>
#include "graphs.h"
#include "graph-user-input.h"
#include "dijkstra.h"

void create_node_option(Graph* input_graph) {
    create_node(input_graph);
    printf("Vertice adicionado na posicao %d.\nQuantidade de vertices atual: %d\n", (input_graph->node_count - 1), input_graph->node_count);
}

void remove_node_option(Graph* input_graph) {
    int node = 0;

    printf("Digite o indice do vertice a ser removido:");
    scanf(" %d", &node);
    if (node >= 0 && node < input_graph->node_count) {
        remove_node(input_graph, node);
        printf("Vertice %d removido.\n" , node);
    } else {
        printf("Erro ao remover o vertice: indice invalido.\n");
    }
}

void create_edge_option(Graph* input_graph) {
    int edge_quantity = 0;
    int node1 = 0;
    int node2 = 0;
    float weight = 0;

    printf("Digite a quantidade de arestas a serem criadas\n");
    scanf(" %d", &edge_quantity);

    for (int i = 0; i < edge_quantity; i++) {
        printf("Digite os vertices e o custo da aresta #%d - (formato: vertice1 vertice2 custo)\n", (i + 1));
        scanf(" %d%d%f", &node1, &node2, &weight);

        //Verify correct user input
        if (node1 >= 0 && node2 >= 0 && weight > 0 && node1 < input_graph->node_count && node2 < input_graph->node_count) {
            printf("Criando aresta de peso %f entre o vertice %d e o vertice %d...\n", weight, node1, node2);
            create_edge(input_graph, node1, node2, weight);
        } else {
            printf("Erro ao criar a aresta #%d: argumentos invalidos.\n", (i + 1));
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

    printf("Digite a quantidade de arestas a serem removidas:");
    scanf(" %d", &edge_quantity);

    for (int i = 0; i < edge_quantity; i++) {
        printf("Digite a %da aresta a ser removida - (formato: vertice1 vertice2)\n", (i + 1));
        scanf(" %d%d", &node1, &node2);

        if (node1 >= 0 && node2 >= 0 && node1 < input_graph->node_count && node2 < input_graph->node_count) {
            printf("Removendo aresta de peso %f entre o vertice %d e o vertice %d...\n", input_graph->matrix[node1][node2], node1, node2);
            remove_edge(input_graph, node1, node2);
        } else {
            printf("Erro ao remover a aresta #%d: argumentos inválidos.\n", (i + 1));
            break;
        }
        node1 = 0;
        node2 = 0;
    }
}

void create_path_options(Graph* graph) {
    int v1, v2;
    printf("Digite o indice do primeiro vertice\n");
    scanf("%d", &v1);
    printf("Digite o indice do segundo vertice\n");
    scanf("%d", &v2);
    if (v1 >= 0 && v2 >= 0 && v2 < graph->node_count && v1 < graph->node_count)
        isThereAPath(graph, v1, v2);
    else
        printf("Erro: os indices dos vertices devem ser positivos e menores que %d.", graph->node_count);


}

void create_general_options(Graph* graph) {
    int flag;
    int visited[graph->node_count];
    printf("\nDigite o numero da opçao desejada; para sair do programa, digite 0.\n");
    printf("\n1. Inserir uma aresta\n2. Remover uma aresta\n3. Descobrir se um vertice s e acessivel a partir de um vertice d.\n4. Inserir um vertice\n5. Remover um vertice\n6. Verificar se o grafo e conexo\n7. Listar vertices e seus custos\n");
    while (scanf("%d", &flag) && flag != 0) {
        switch (flag) {

            case 1:
                create_edge_option(graph);
                printf("Digite uma nova opcao(1-7) ou 0 para abortar o programa.:\n");
                break;
            case 2:
                remove_edge_option(graph);
                printf("Digite uma nova opcao(1-7) ou 0 para abortar o programa.:\n");
                break;
            case 3:
                create_path_options(graph);
                printf("\nDigite uma nova opcao(1-7) ou 0 para abortar o programa.:\n");
                break;
            case 4:
                create_node_option(graph);
                printf("\nDigite uma nova opcao(1-7) ou 0 para abortar o programa.:\n");
                break;
            case 5:
                remove_node_option(graph);
                printf("\nDigite uma nova opcao(1-7) ou 0 para abortar o programa.:\n");
                break;
            case 6:
                if (isConnected(graph, visited)) printf("O grafo e conexo.");
                else printf("O grafo nao e conexo.");
                printf("\nDigite uma nova opcao(1-7) ou 0 para abortar o programa.:\n");
                break;
            case 7:
                printEdges(graph);
                printf("\nDigite uma nova opcao(1-7) ou 0 para abortar o programa.:\n");
                break;
            default:
                printf("Digite uma opcao valida(1-7).\n");
        }
    }

}

