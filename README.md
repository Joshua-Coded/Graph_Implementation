# Graph Traversal Project

This project contains separate implementations of DFS and BFS algorithms for graph traversal.

## Project Structure
```
graph_traversal/
├── dfs_project/
│   ├── include/
│   │   └── dfs.h
│   ├── src/
│   │   ├── dfs.c
│   │   └── main.c
│   ├── Makefile
│   └── README.md
├── bfs_project/
│   ├── include/
│   │   └── bfs.h
│   ├── src/
│   │   ├── bfs.c
│   │   └── main.c
│   ├── Makefile
│   └── README.md
└── README.md
```

## Building and Running

### For DFS Implementation
```bash
cd dfs_project
make
./build/dfs_traversal
```

### For BFS Implementation
```bash
cd bfs_project
make
./build/bfs_traversal
```

## Time Complexity
Both implementations have:
- Time Complexity: O(V + E)
- Space Complexity: O(V)

## Related Algorithms
- Shortest Path Finding
- Connected Components
- Cycle Detection
- Topological Sorting

## Requirements
- GCC compiler
- Make utility
