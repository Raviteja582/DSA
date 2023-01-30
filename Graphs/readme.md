# DFS Usage : 
The algorithm works in $O(m + n)$ time where $n$ is the number of vertices and $m$ is the number of edges.
## 1. number of connected components 
## 2. To check Bipartite of graph
## 3. Check a vertex in tree is ancestor of another vertex
    
    - At the beginning and end of each search call we remember the entry and exit "time" of each vertex. Now you can find the answer for any pair of vertices (i, j) in  O(1) : 
    vertex  i is an ancestor of vertex  j if and only if - 
        
        - entry[i] < entry[j]  
        - exit[i] > exit[j]

## 4. Shortest path on trees, but not on graphs.
## 5. Finding any path between source to any vertex.
## 6. Find the lowest common ancestor (LCA) of two vertices.
## 7. To find cycles in graph and there lengths.
## 8. Strongly Connected components & bridges.

# BFS Usage:
The algorithm works in $O(m + n)$ time where $n$ is the number of vertices and $m$ is the number of edges.
    
    - Conditions:
            1. should be unweighted graph
            2. works same in directed & undirected graphs.
## 1. The Shortest Path from source to destination - BFS
## 2. The Shortest cycle in both directed/undirected with unweighted - BFS
## 3. Find All edges/vertices present in any shortest path between u to v:

    - Run Two BFS from a (da[]) and from b(db[]).
    - For each Edges (x-y): da[x]+1+db[y]=da[b]
    - For each vertex(x): da[x]+db[x]=da[b]
## 4. Find the shortest path of even length from a source vertex  $s$  to a target vertex  $t$  in an unweighted graph: 

### For this, we must construct an auxiliary graph, whose vertices are the state $(v, c)$ where $v$ - the current node, $c = 0$ or $c = 1$ - the current parity. Any edge $(a, b)$ of the original graph in this new column will turn into two edges $((u, 0), (v, 1))$ and $((u, 1), (v, 0))$. After that we run a BFS to find the shortest path from the starting vertex $(s, 0)$  to the end vertex $(t, 0)$ .

# Order of Learning:
### 1. DFS and its applications
### 2. Single source shortest paths:
<ol>
    <h3> Unweighted: </h3>
    <li>BFS and its applications</li>
    <li>0/1 - BFS</li>
</ol>
<ol>
    <h3> Weighted: </h3>
    <li>Dijkstra - Dense, Sparse(set, pq)</li>
    <li>Bellman Ford</li>
</ol>

### 3. All pair shortesh path - Floyd Warshall Algorithm

### 4. DAG - Topological sort - BFS, DFS

### 5. Disjoint Sets
<ol>
    <li>path compression</li>
    <li>union by rank - size, height</li>
    <li>combine above both</li>
</ol>

### 6. Spanning Trees:
<ol>
    <li>Prims - Dense, Sparse</li>
    <li>Krushkal - Dense, Sparse</li>
</ol>

### 7. Cycles:
<ol>
    <li>DFS - Directed, Undirected</li>
    <li>BFS - Directed, Undirected</li>
    <li>negative cycle - Bellmon ford, Floyd Warshall</li>
</ol>

### 8. Graph Paths:
<ol>
    <li>Eularian Path</li>
    <li>Hamiltan Path</li>
</ol>

### 9. Strongly Connected Components:
### 10. Graph Flows