# Dijkstra on Dense Graph:
## works for both directed & undirected with weighted graphs.
    - used to find the shortest path from source $s$ to all other vertices.

## Algorithm: 
## 1. It runs for n iterations, at each iteration a vertex $v$ is choosen as unmarked vertex which has the least value.

## 2. The Selected vertex is marked and from vertex $v$, <b>relaxations</b> are performed.
## all edges from $(v,to)$, for each vertex $to$, the algorithm tries to improve the $d[to]$.

## After all such edges are relaxed, the iteration completes

## 3. Finally, after $n$  iterations, all vertices will be marked, and the algorithm terminates. We claim that the found values $d[v]$  are the lengths of shortest paths from $s$ to all vertices $v$ .
    
## Time Complexity: $O(n^2+m)$