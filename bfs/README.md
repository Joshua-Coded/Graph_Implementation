# BFS Graph Traversal Implementation

Implementation of Breadth-First Search algorithm for the given graph structure.

## Compilation
```bash
make
```

## Execution
```bash
./build/bfs_traversal
```

## Output
The traversal path will be saved in `bfs_output.txt`

## Time Complexity
- Time: O(V + E)
- Space: O(V)
where V is the number of vertices and E is the number of edges.

## File Structure
- `include/bfs.h`: Header file containing graph structure and function declarations
- `src/bfs.c`: Implementation of BFS algorithm
- `src/main.c`: Main program demonstrating BFS traversal
- `Makefile`: Build configuration

## Cleanup
```bash
make clean
```
