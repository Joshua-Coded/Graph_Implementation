#include <stdio.h>
#include <stdlib.h>
#include "../include/dfs.h"

DFSNode* createDFSNode(int vertex) {
    DFSNode* newNode = (DFSNode*)malloc(sizeof(DFSNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

DFSGraph* createDFSGraph(int vertices) {
    DFSGraph* graph = (DFSGraph*)malloc(sizeof(DFSGraph));
    graph->vertices = vertices;
    graph->adjacencyList = (DFSNode**)malloc((vertices + 1) * sizeof(DFSNode*));
    graph->visited = (bool*)calloc(vertices + 1, sizeof(bool));

    for(int i = 0; i <= vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addDFSEdge(DFSGraph* graph, int src, int dest) {
    DFSNode* newNode = createDFSNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createDFSNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

static void DFSUtil(DFSGraph* graph, int vertex, FILE* fp) {
    graph->visited[vertex] = true;
    fprintf(fp, "%d ", vertex);

    DFSNode* temp = graph->adjacencyList[vertex];
    while(temp) {
        if(!graph->visited[temp->vertex]) {
            DFSUtil(graph, temp->vertex, fp);
        }
        temp = temp->next;
    }
}

void DFS(DFSGraph* graph, int startVertex) {
    FILE* fp = fopen("dfs_output.txt", "w");
    if(!fp) {
        printf("Failed to open output file\n");
        return;
    }

    for(int i = 0; i <= graph->vertices; i++) {
        graph->visited[i] = false;
    }

    DFSUtil(graph, startVertex, fp);
    fclose(fp);
}

void freeDFSGraph(DFSGraph* graph) {
    for(int i = 0; i <= graph->vertices; i++) {
        DFSNode* current = graph->adjacencyList[i];
        while(current) {
            DFSNode* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjacencyList);
    free(graph->visited);
    free(graph);
}
