#include <stdio.h>
#include "../include/bfs.h"

#define VERTICES 12
#define EDGES 15

int main() {
    BFSGraph* graph = createBFSGraph(VERTICES);

    int edges[EDGES][2] = {
        {1,2}, {1,3}, {2,4}, {2,5}, {3,4}, 
        {3,6}, {4,7}, {5,7}, {5,9}, {6,8}, 
        {7,10}, {8,10}, {9,11}, {10,12}, {11,12}
    };

    for(int i = 0; i < EDGES; i++) {
        addBFSEdge(graph, edges[i][0], edges[i][1]);
    }

    printf("Performing BFS traversal starting from vertex 1...\n");
    BFS(graph, 1);
    printf("BFS traversal saved to bfs_output.txt\n");

    freeBFSGraph(graph);
    return 0;
}
