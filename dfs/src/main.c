#include <stdio.h>
#include "../include/dfs.h"

#define VERTICES 12
#define EDGES 15

int main() {
    DFSGraph* graph = createDFSGraph(VERTICES);

    int edges[EDGES][2] = {
        {1,2}, {1,3}, {2,4}, {2,5}, {3,4}, 
        {3,6}, {4,7}, {5,7}, {5,9}, {6,8}, 
        {7,10}, {8,10}, {9,11}, {10,12}, {11,12}
    };

    for(int i = 0; i < EDGES; i++) {
        addDFSEdge(graph, edges[i][0], edges[i][1]);
    }

    printf("Performing DFS traversal starting from vertex 1...\n");
    DFS(graph, 1);
    printf("DFS traversal saved to dfs_output.txt\n");

    freeDFSGraph(graph);
    return 0;
}
