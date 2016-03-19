/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   grafos.h
 * Author: Maloca
 *
 * Created on March 8, 2016, 8:17 PM
 */

typedef struct grafo Grafo;

void cria_grafo(Grafo* entrada , int quantVertice);
void destroi_grafo(Grafo* entrada);

int contem_aresta(Grafo* entrada , int vertice1 , int vertice2);
void criar_aresta(Grafo* entrada , int vertice1 , int vertice2);
void remover_aresta(Grafo* entrada , int vertice1 , int vertice2);