
## Topological Sort 

![Topological Sorting](https://assets.leetcode.com/users/images/e482f21d-a612-4333-ac80-807eb90c1495_1613794550.934654.png)

In a directed acyclic graph (DAG), a topological sort is a linear ordering of all vertices such that for any edge (u, v), 
u comes before v. Another way to describe it is that when you put all vertices horizontally on a line, all of the edges are 
pointing from left to right.

#### Code :
```cpp
vector<int> topo_sort(int N, vector<int> adj[])
{

// topological sorting using bfs

// N = number of vertices in graph // adj = adjacency list
    queue<int> bfs;

    //  queue of vertices with no incoming edges
    vector<int> inDegree(N,0); 
    // inDegree[i] = number of incoming edges to vertex i

    for(int i=0;i<N;i++){
        for(auto it:adj[i]){ 
        // for each edge (i,j) in graph // it = j in this case
            inDegree[it]++; // inDegree[i] = # of edges that point to i
        }
    }

    for(int i=0;i<N;i++){
        if(inDegree[i]==0){ // if there is no edge pointing to i
            bfs.push(i);
        }
    }

// indegree[node] == 0 then insert into queue;

vector<int> topo_sorted;
while( !bfs.empty() )
{
	auto curr_node = bfs.front(); bfs.pop();
	topo_sorted.push_back(curr_node);

	for( auto next_node : graph[curr_node] )
	{
		indegree[next_node]--;
		if( indegree[next_node] == 0 )
			bfs.push(next_node);
	}
}

  return topo_sorted;
}
```






### Problems : 
- [207. Course Schedule](https://leetcode.com/problems/course-schedule/)
- [210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
- [269. Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)
- [329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)
- [444. Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction/)
- [1203. Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/)

