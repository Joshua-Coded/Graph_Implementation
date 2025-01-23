#ifndef DFS_H
#define DFS_H

#include <stdbool.h>

typedef struct DFSNode {
    int vertex;
    struct DFSNode* next;
} DFSNode;

typedef struct DFSGraph {
    DFSNode** adjacencyList;
    bool* visited;
    int vertices;
} DFSGraph;

DFSGraph* createDFSGraph(int vertices);
void addDFSEdge(DFSGraph* graph, int src, int dest);
void DFS(DFSGraph* graph, int startVertex);
void freeDFSGraph(DFSGraph* graph);

#endif
