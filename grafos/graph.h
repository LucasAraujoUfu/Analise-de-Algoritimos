#ifndef GRAPH_H
#define GRAPH_H

typedef struct node node;
typedef struct graph graph;

graph* createGraph();
void destructGraph(graph *g);
int addNodeGraph(graph *g, int w);
int value(graph *g, int n);
int sizeGraph(graph* g);

#endif
