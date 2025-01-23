#ifndef BFS_H
#define BFS_H

#include <stdbool.h>

#define MAX_QUEUE 1000

typedef struct BFSNode {
    int vertex;
    struct BFSNode* next;
} BFSNode;

typedef struct Queue {
    int items[MAX_QUEUE];
    int front;
    int rear;
} Queue;

typedef struct BFSGraph {
    BFSNode** adjacencyList;
    bool* visited;
    int vertices;
} BFSGraph;

BFSGraph* createBFSGraph(int vertices);
void addBFSEdge(BFSGraph* graph, int src, int dest);
void BFS(BFSGraph* graph, int startVertex);
void freeBFSGraph(BFSGraph* graph);

#endif
