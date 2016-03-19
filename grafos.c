/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "grafos.h"

struct grafo {
    int quantVertice;
    int ** matriz;
};

void cria_grafo(Grafo* entrada , int quantVertice) {
    
    entrada->matriz = calloc(quantVertice , sizeof(int*));
    for(int i = 0; i < quantVertice; i++) {
        entrada->matriz[i] = calloc(quantVertice , sizeof(int));
    }
    entrada->quantVertice = quantVertice;
}

void destroi_grafo(Grafo* entrada) {
    for(int i = 0; i < entrada->quantVertice; i++) {
        free(entrada->matriz[i]);
    }
    free(entrada->matriz);
    entrada->quantVertice = 0;
}

int contem_aresta(Grafo* entrada , int vertice1 , int vertice2) {
    return entrada->matriz[vertice1][vertice2] == 1;
}

void criar_aresta(Grafo* entrada , int vertice1 , int vertice2) {
    entrada->matriz[vertice1][vertice2] = 1;
    entrada->matriz[vertice2][vertice1] = 1;
}

void remover_aresta(Grafo* entrada , int vertice1 , int vertice2) {
    entrada->matriz[vertice1][vertice2] = 0;
    entrada->matriz[vertice2][vertice1] = 0;
}