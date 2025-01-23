#include <stdio.h>
#include <stdlib.h>
#include "../include/bfs.h"

static Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    return queue;
}

static void enqueue(Queue* queue, int value) {
    if(queue->rear == MAX_QUEUE-1) return;
    if(queue->front == -1) queue->front = 0;
    queue->rear++;
    queue->items[queue->rear] = value;
}

static int dequeue(Queue* queue) {
    if(queue->front == -1) return -1;
    int item = queue->items[queue->front];
    queue->front++;
    if(queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

BFSNode* createBFSNode(int vertex) {
    BFSNode* newNode = (BFSNode*)malloc(sizeof(BFSNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

BFSGraph* createBFSGraph(int vertices) {
    BFSGraph* graph = (BFSGraph*)malloc(sizeof(BFSGraph));
    graph->vertices = vertices;
    graph->adjacencyList = (BFSNode**)malloc((vertices + 1) * sizeof(BFSNode*));
    graph->visited = (bool*)calloc(vertices + 1, sizeof(bool));

    for(int i = 0; i <= vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

void addBFSEdge(BFSGraph* graph, int src, int dest) {
    BFSNode* newNode = createBFSNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createBFSNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void BFS(BFSGraph* graph, int startVertex) {
    Queue* queue = createQueue();

    for(int i = 0; i <= graph->vertices; i++) {
        graph->visited[i] = false;
    }

    printf("\nBFS Traversal starting from vertex %d:\n", startVertex);
    
    graph->visited[startVertex] = true;
    enqueue(queue, startVertex);

    while(queue->front != -1) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        BFSNode* temp = graph->adjacencyList[currentVertex];
        while(temp) {
            if(!graph->visited[temp->vertex]) {
                graph->visited[temp->vertex] = true;
                enqueue(queue, temp->vertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(queue);
}

void freeBFSGraph(BFSGraph* graph) {
    for(int i = 0; i <= graph->vertices; i++) {
        BFSNode* current = graph->adjacencyList[i];
        while(current) {
            BFSNode* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjacencyList);
    free(graph->visited);
    free(graph);
}
