# Graph Traversal Project

This project contains separate implementations of DFS and BFS algorithms for graph traversal.

## Project Structure
```
Graph_Implementation/
├── dfs/
│   ├── include/
│   │   └── dfs.h
│   ├── src/
│   │   ├── dfs.c
│   │   └── main.c
│   ├── Makefile
│   └── README.md
├── bfs/
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
cd dfs
make
./build/dfs_traversal
```

### For BFS Implementation
```bash
cd bfs
make
./build/bfs_traversal
```

## Time Complexity
Both implementations have:
- Time Complexity: O(V + E)
- Space Complexity: O(V)

## Requirements
- GCC compiler
- Make utility
