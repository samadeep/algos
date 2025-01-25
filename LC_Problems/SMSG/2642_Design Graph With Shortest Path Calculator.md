[2642. Design Graph With Shortest Path Calculator](https://leetcode.com/problems/design-graph-with-shortest-path-calculator/)

There is a **directed weighted** graph that consists of `n` nodes numbered from `0` to `n - 1`. The edges of the graph are initially represented by the given array `edges` where `edges[i] = [fromi, toi, edgeCosti]` meaning that there is an edge from `fromi` to `toi` with the cost `edgeCosti`.

Implement the `Graph` class:

- `Graph(int n, int[][] edges)` initializes the object with `n` nodes and the given edges.
- `addEdge(int[] edge)` adds an edge to the list of edges where `edge = [from, to, edgeCost]`. It is guaranteed that there is no edge between the two nodes before adding this one.
- `int shortestPath(int node1, int node2)` returns the **minimum** cost of a path from `node1` to `node2`. If no path exists, return `-1`. The cost of a path is the sum of the costs of the edges in the path.

**Example 1:**

![](https://assets.leetcode.com/uploads/2023/01/11/graph3drawio-2.png)

**Input**
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
**Output**
[null, 6, -1, null, 6]

**Explanation**
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.

**Constraints:**

- `1 <= n <= 100`
- `0 <= edges.length <= n * (n - 1)`
- `edges[i].length == edge.length == 3`
- `0 <= fromi, toi, from, to, node1, node2 <= n - 1`
- `1 <= edgeCosti, edgeCost <= 106`
- There are no repeated edges and no self-loops in the graph at any point.
- At most `100` calls will be made for `addEdge`.
- At most `100` calls will be made for `shortestPath`.



Our problem says that we have a special class called Graph and we want to implement its methods to make a graph, add edges freely to it and calculate shortest path between any two nodes.
our bottleneck function will be to find the shortest path between any two node.

But for my I don't think it is a hard problem.

Let's focus on two important things:
We want to find a path between two nodes.
We want to minimize the cost of the path.
It looks like something that Dijkstra's Algorithm can solve, our hero today🦸‍♂️!

But what is DIJKSTRA ?!!
Dijkstra's Algorithm is an algorithm to find the shortest path between two nodes in a graph or two cells in a matrix or any problem that can be represented as a graph.📈

It's part of a family of algorithms designed to uncover the shortest path between nodes or cells like BFS, Bellman-Ford Algorithm, Floyd-Warsahll Algorithm. Each algorithm has its unique applications.

Let's focus on Dijkstra's Algorithm:
Nature: It's a single-source, multiple-destination algorithm. In simpler terms, it pinpoints the shortest path from a starting node to any other node in our graph.
Constraints: Dijkstra's Algorithm is suitable for graphs or problems featuring positive weights. If we encounter negative weights, we'd choose alternative algorithms such as Bellman-Ford.
And there you have it! Dijkstra's Algorithm is the key 🗝to our problem, well-known for tackling precisely these types of challenges.

We will construct our graph simply like any other graph problem and when we are required to calculate shortest path between two nodes we will call our svaior Dijkstra's Algorithm.

And this is the solution for our today'S problem I hope that you understood it🚀🚀

## Approach

### Graph Initialization:
Initializes the adjacency list by resizing it to the number of nodes and populates it with edges.
Adding an Edge:
Appends a new edge to the adjacency list based on the input vector edge representing the edge information.
Finding Shortest Path:
Calls the private dijkstra method to find the shortest path between two nodes (node1 and node2) using Dijkstra's algorithm.
Dijkstra's Algorithm Implementation:
Uses a priority queue to efficiently retrieve the node with the minimum distance.
The algorithm updates distances and explores neighbors until it finds the target node or completes the traversal.
Returns the minimum distance or -1 if no path exists.
## Complexity
### Time complexity:

Graph(int n, int[][] edges): O(E)

Initialization will require to loop over the edges to add them to the adjacent list which cost O(E).
addEdge(int[] edge): O(1)

It is only constant time since we simply add the edge to the adjacent list.

### Shortest Path Calculation: O(V+E∗log(E))
Since initializing the distances vector is linear operation with length V for all the elements and priority queue will cost log(E) in the single time to be called since it can have atmost E edges and at worst complexity it will be called for E time.
Space complexity:
The graph class: O(V+E)
Since the class will store adjacency list all the time for the graph which contains of N vectors for each node and all vectors have E elements.
Graph(int n, int[][] edges): O(1)
Doesn't require any additional space than the adjacency list to be called.
addEdge(int[] edge): O(1)
Doesn't require any additional space to add an edge.
Shortest Path Calculation: O(E)
The** priority queue** of the Dijkstra Algorithm will store at most E edges in it so the space complexity when calling this function is O(E).
Where V is number of nodes and E is number of edges.

Code

```cpp
class Graph {
public:
    // Adjacency list to represent the graph
    vector<vector<pair<int, int>>> adjacencyList;

    // Constructor to initialize the graph with nodes and edges
    Graph(int n, vector<std::vector<int>>& edges) {
        adjacencyList.resize(n);
        for (auto edge : edges)
            adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }

    // Add a new edge to the graph
    void addEdge(vector<int> edge) {
        adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }

    // Find the shortest path between two nodes using Dijkstra's algorithm
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }

private:
    // Dijkstra's algorithm to find the shortest path
    int dijkstra(int start, int end) {
        int n = adjacencyList.size();
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;

        // Priority queue to efficiently retrieve the node with the minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, start});

        while (!priorityQueue.empty()) {
            int currentNode = priorityQueue.top().second;
            int currentCost = priorityQueue.top().first;
            priorityQueue.pop();

            // Skip if a shorter path has already been found
            if (currentCost > distances[currentNode])
                continue;

            // If found the target node then return the cost
            if(currentNode == end)
                return currentCost ;

            // Explore neighbors and update distances
            for (auto edge : adjacencyList[currentNode]) {
                int neighbor = edge.first, edgeLength = edge.second;
                int newRouteCost = edgeLength + distances[currentNode];

                // Update distance if a shorter route is found
                if (distances[neighbor] > newRouteCost) {
                    distances[neighbor] = newRouteCost;
                    priorityQueue.push({newRouteCost, neighbor});
                }
            }
        }

        // Return the minimum distance or -1 if no path exists
        return ((distances[end] == INT_MAX) ? -1 : distances[end]);
    }
};
```
