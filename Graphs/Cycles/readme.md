# For Directed Graphs:
## DFS:
1. We use concept of 0,1,2 states for each vertex, initally status of all vertices is 0.
2. In recursion of $v$, we mark it status[$v$]=$1$ and mark it status[$v$]=$2$ once it completes.
3. if in recursion we encounter any vertex status as $1$, then it is a cycle.

## BFS:
1. We use concept of Topological sort of kahn's algorithm
2. Initially we have inorder[] for each vertex and insert vertex to queue having inorder[i]=0;
3. With given graph, we try to construct a topological order(topo_order).
4. if len(topo_order)==size_vertices, then no cycle.
5. else we have a cycle, i.e., len(topo_order) $<$ size_vertices.

# For Undirected Graphs:
## DFS:
### In DFS, once recursion starts from a vertex $v$, then it never again visited by DFS, because we will initiate recursions for all its neighbours when we first visited it.
1. We will convert the $status$ array to $visited$ array.
2. In recursion, if we encounter a neighbour which is already visited, then we have a cycle.

## BFS:
### In BFS, we will visit all the neighbours and insert in queue for a particular vertex, so if any neighbour of a particular vertex is in queue, then we have a cycle.
### Hence, we will have multiple ways to detect whether the vertex is already in queue.
### Method-1:
1. So here we can use concept of 0,1,2 $status$ array, where 0 is not visited, 1 is visited and in queue and 2 completely visited.
### Method-2 (preferable):
1. We can use $visited$ array and in queue we store information of parent when a vertex is inserted in it.
2. so if the neighbour node is already visited, then it might be a parent or else, the vertex is already visited by a some other node in same level of current node. That means whose parent is different. 

# Shortest Cycle:
## BFS:
### 1. Directed + Unweighted
### 2. Undirected + Unweighted 

## APSP - Floyd Warshall Algo
### 1. UnDirected + Weighted
### 2. Directed + Weighted - no idea