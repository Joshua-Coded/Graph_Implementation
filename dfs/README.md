# DFS Graph Traversal Implementation

Implementation of Depth-First Search algorithm for the given graph structure.

## Compilation
```bash
make
```

## Execution
```bash
./build/dfs_traversal
```

## Output
The traversal path will be saved in `dfs_output.txt`

## Time Complexity
- Time: O(V + E)
- Space: O(V)
where V is the number of vertices and E is the number of edges.

## File Structure
- `include/dfs.h`: Header file containing graph structure and function declarations
- `src/dfs.c`: Implementation of DFS algorithm
- `src/main.c`: Main program demonstrating DFS traversal
- `Makefile`: Build configuration

## Cleanup
```bash
make clean
```
