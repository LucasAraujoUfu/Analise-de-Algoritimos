#ifndef GRAPH_C
#define GRAPH_C

#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

struct node{
	int w;
	node *next;
};

struct graph{
	node *root;
	node *leaf;
	int size;
};

graph* createGraph(){
	graph *g = (graph*) malloc(sizeof(graph));
	if(g != NULL){
		g->root = NULL;
		g->leaf = NULL;
		g->size = 0;
	}
	return g;
}

void destructGraph(graph *g){
	while(g->root!=NULL){
		node *n = g->root;
		g->root = g->root->next;
		free(n);
	}
	free(g);
}

int addNodeGraph(graph *g, int w){
	if(g==NULL)return 1;
	node *n = (node*) malloc(sizeof(node));
	if(n==NULL)return 1;
	n->next = NULL;
	n->w = w;
	if(g->root==NULL){
		g->root = n;
		g->leaf = n;
	}
	else{
		g->leaf->next = n;
		g->leaf = g->leaf->next;
	}
	g->size++;
	return 0;
}

int value(graph *g, int n){
	if(g==NULL)return 0;
	if(g->root==NULL)return 0;
	if(n>g->size)return 0;
	int i=1;
	node *nd = g->root;
	while(i<n){
		nd = nd->next;
	}
	return nd->w;
}


int sizeGraph(graph* g){
	if(g==NULL)return 0;
	return g->size;
}

#endif
