### Defining Articulation Points

Let's define what an _articulation point_ is. We say that a vertex 𝑉 in a graph 𝐺 with 𝐶 connected components is an _articulation point_ if its removal increases the number of connected components of 𝐺 . 

In other words, let 𝐶 be the number of connected components after removing vertex 𝑉 and C increases on removing the edges.


![](https://codeforces.com/predownloaded/7f/31/7f31b30b9f0cdfd06bb884da64d2aebe2bc993e1.png)

#### Tarjan's approach to find the Articulation Points O(V + E)

![](https://codeforces.com/predownloaded/ba/03/ba03bbf48735da5993033073f1d53d617c491c45.png)

### Implementation

To know if some node 𝐴 is ancestor of some other node 𝑉, for this we can assign a `discovery time` to each vertex 𝑉 in the graph 𝐺 based on the DFS traversal, so that we can know which node was discovered before or after another. 

e.g. in a Graph `G` with the traversal `A -> B -> C` the **discovery** **times** for each node will be respectively 1, 2, 3; with this we know that **A** was discovered before **C** since `discovery_time[A] < discovery_time[C]`.


```cpp
// adj[u] = adjacent nodes of u
// ap = AP = articulation points
// parent = parent
// tin[u] = discovery time of u
// low[u] = 'low' node of u
vector<int> articulation_point(N,0);
int time = 0;
int dfs_Articulation_Points( int node, int par ) {
	tin[node] = timer++;
	low[node] = tin[node];

	for( auto next : graph[node] ){

		if( next == parent ) continue;

		// this means that next is an ancestor of node as its already been reached
		if( visited[next] ){
			low[node] = min( low[node] , tin[next] );
		}

		else{

			dfs( next , node );
			low[node] = min( low[node] , low[next] );
			if( low[next] > tin[node] ) // it cannot reach before the node so no back edge is there for fast reach
			{
				articulation_point[node] = 1;
				bridges.push_back({node , next});
			}
		}
	}
}
```

![](https://codeforces.com/predownloaded/a6/17/a617a63a6fa6f6591f6c69a860a68ba38d97a21f.png)

- Why `low[node] = min( low[node] , tin[next] )` instead of `low[node] = min( low[node] , low[next] )` ?

Let's consider node **C** in the graph above, in the DFS traversal the nodes after **C** are: **D** and **E**, when the DFS traversal reaches **E** we find **C** again, if we take its 𝑙𝑜𝑤 time, `low[E]` will be equal to `tin[A]` but at this point, when we return back to **C** in the DFS we will be omitting the fact that 𝑈� is the **root of a cycle** (which makes it an _articulation point_) and we will be saying that there is a path from **E** to some ancestor of **C** (in this case **A**) which does not require **C** and such path does not exist in the graph, therefore the algorithm will say that **C** is NOT an _articulation point_ which is totally false since the only way to reach **D** and **E** is passing through **C**.



#### Related Questions :
[1192. Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/)

#### Code :
```cpp
class Solution {
public:
    vector<vector<int>> criticalConnections(int N , vector<vector<int>>& connections) {

        // Articulation Points or Cut Vertex in a Graph

        vector<vector<int>> bridges;
        vector<vector<int>> graph(N);

        for( auto c : connections )
        {
            int src = c[0] , dst = c[1] ;
            graph[src].push_back(dst);
            graph[dst].push_back(src);
        }

        vector<int> low(N) , tin(N); vector<bool> visited(N,false);

        int timer = 0;

        std::function<void(int, int)> dfs = [&](int node , int parent = -1) -> void
        {
            visited[node] = true;
            tin[node] = timer++;
            low[node] = tin[node];

            for( auto to : graph[node] )
            {
                if( to == parent ) continue;

                if( visited[to] )
                {
                    low[node] = min( low[node] , tin[to] ); // already visited then take its low distance 
                }
                else
                {
                    dfs(to , node);
                    low[node] = min( low[node] , low[to] ); // otherwise take the low after its dfs is complete 
                    if( low[to] > tin[node] ) // it cannot reach before the node so no back edge is there for fast reach
                    {
                        bridges.push_back({node , to});
                    }
                }
            }


        };


        dfs(0,-1);

        return bridges ;

    }
};
```

