## Complete Graph Theory Notes 

### 1. Complexity of Graph

```
#Space Complexity:

Adjacency Matrix: O(V^2) &mdash; where V is the number of vertices. This is because an adjacency matrix is a 2D array of size V x V.
Adjacency List: O(V + E) &mdash; where V is the number of vertices and E is the number of edges. This is because an adjacency list is an array of lists, and each vertex is represented by a list containing its neighbors.


#Time Complexity:
 
Graph Traversal (BFS or DFS): O(V + E) &mdash; where V is the number of vertices and E is the number of edges. This is because each vertex and edge is visited once during traversal.
Checking for an Edge (Adjacency Matrix): O(1) &mdash; constant time access to the matrix.
Checking for an Edge (Adjacency List): O(degree(V)) &mdash; where degree(V) is the number of neighbors of vertex V.
Finding Neighbors (Adjacency Matrix): O(V) &mdash; need to iterate over an entire row or column.
Finding Neighbors (Adjacency List): O(degree(V)) &mdash; directly accessing the list of neighbors.
Specific Graph Algorithms:
 
Dijkstra's Algorithm: O((V + E) * log(V)) with binary heap or Fibonacci heap.
Bellman-Ford Algorithm: O(V * E).
Floyd-Warshall Algorithm: O(V^3).
Topological Sorting: O(V + E).
Finding Articulation Points and Bridges: O(V + E).
Prim's Algorithm (Minimum Spanning Tree): O((V + E) * log(V)) with a binary heap or Fibonacci heap.
Kruskal's Algorithm (Minimum Spanning Tree): O(E * log(V)) with sorting.-

```

### 2. Adjacency Matrix

```cpp
#include<bits/stdc++.h>
using namespace std;
int g[100][100];
int main() {
    int n, e; cin >> n >> e;
    while(e--) {
        int u, v; cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    if(g[4][2]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
```

### 3. Adjacency List

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> g[N];
int indgr[N], outdgr[N];
int main() {
    int n, e; cin >> n >> e;
    while(e--) {
        int u, v; cin >> u >> v;
        indgr[v]++;
        outdgr[u]++;
        g[u].push_back(v);
    }
    for(int i = 0; i <= n; i++) {
        cout << indgr[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i <= n; i++) {
        cout << outdgr[i] << " ";
    }
}
```

### 4. DFS

```cpp
#include<bits/stdc++.h>
#define itsmdshahin ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
using namespace std;
const int N = 1e5 + 9;
bool vis[N];
vector<int> g[N];
void dfs(int s) {
    vis[s] = true;
    for(auto it : g[s]) {
        if(!vis[it]) {
            cout << "VISITED " << it << endl;
            dfs(it);
        }
    }
}
int main() {
    int n, m; cin >> n >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int s; cin >> s;
    dfs(s);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout << "DISCONNECTED GRAPH\n";
            return 0;
        }
    }
}
```

### 5. Connected Components

```cpp
#include<bits/stdc++.h>
#define itsmdshahin ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
using namespace std;
const int N = 1e5 + 9;
bool vis[N];
vector<int> g[N];
void dfs(int s) {
    vis[s] = true;
    for(auto it : g[s]) {
        if(!vis[it]) {
            dfs(it);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            ++ans;
        }
    }
    cout << "Connected Components: " << ans << endl;
}
```

### 6. BFS Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> G[N];
bool Vis[N];
int main() {
    int n, e; cin >> n >> e;
    while(e--) {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    Vis[1] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto it : G[u]) {
            if(!Vis[it]) {
                q.push(it);
                Vis[v] = true;
            }
        }
    }
}
```

### 7. BFS Component Find in Graph

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> G[N];
bool Vis[N];
queue<int> q;
void bfs(int n) {
    q.push(n);
    Vis[n] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto it : G[u]) {
            if(!Vis[it]) {
                q.push(it);
                Vis[it] = true;
            }
        }
    }
}

int main() {
    int n, e; cin >> n >> e;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!Vis[i]) {
            bfs(i);
            ++ans;
        }
    }
    cout << ans << endl;
}
```

### 8. BFS Distance Find in Graph Theory

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> G[N];
bool Vis[N];
vector<int> dis(N);
int main() {
    int n, e; cin >> n >> e;
    queue<int> q;
    q.push(1);
    Vis[1] = true;
    dis[1] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto it : G[u]) {
            if(!Vis[it]) {
                q.push(it);
                dis[it] = dis[u] + 1;
                Vis[it] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
}
```

---

### 9. BFS Path Find in Graph Theory

```cpp

```

### 10. Bicoloring and Bipartite Graph

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> g[N];
bool vis[N], col[N], ok;

void dfs(int u) {
    vis[u] = true;
    for(auto v : g[u]) {
        if(!vis[v]) {
            col[v] = col[u] ^ 1;
            dfs(v);
        } else {
            if(col[u] == col[v]) ok = false;
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    while(e--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ok = true;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }
    if(ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
```

### 11. Articulation Points and Bridges

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

vector<int> g[N];
bool vis[N];
int in[N], low[N], timer;
set<int> articulationPoints;
set<pair<int, int>> bridges;

void dfs(int u, int par) {
    vis[u] = true;
    in[u] = low[u] = timer++;

    int children = 0;

    for (auto v : g[u]) {
        if (v == par) continue;

        if (vis[v]) {
            low[u] = min(low[u], in[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] >= in[u] && par != -1) {
                articulationPoints.insert(u);
            }

            if (low[v] > in[u]) {
                bridges.insert({min(u, v), max(u, v)});
            }

            children++;
        }
    }

    if (par == -1 && children > 1) {
        articulationPoints.insert(u);
    }
}

int main() {
    int n, e; cin >> n >> e;
    while (e--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    timer = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }

    cout << "Articulation Points: ";
    for (auto point : articulationPoints) {
        cout << point << " ";
    }
    cout << "\n";

    cout << "Bridges: ";
    for (auto bridge : bridges) {
        cout << bridge.first << "-" << bridge.second << " ";
    }
    cout << "\n";

    return 0;
}
```

### 12. Topological Sorting

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];
stack<int> order;

void dfs(int u) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    order.push(u);
}

int main() {
    int n, e; cin >> n >> e;
    while (e--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    cout << "Topological Sorting: ";
    while (!order.empty()) {
        cout << order.top() << " ";
        order.pop();
    }
    cout << "\n";

    return 0;
}
```

### 13. Dijkstra's Algorithm

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<pair<int, int>> g[N];
vector<int> dis(N, INT_MAX);

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dis[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (w > dis[u]) continue;

        for (auto it : g[u]) {
            int v = it.first;
            int weight = it.second;

            if (dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    int n, e; cin >> n >> e;
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int start; cin >> start;
    dijkstra(start);

    cout << "Shortest Distances from Node " << start << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": " << dis[i] << "\n";
    }

    return 0;
}
```

### 14. Bellman-Ford Algorithm

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<tuple<int, int, int>> edges;
vector<int> dis(N, INT_MAX);

void bellmanFord(int start) {
    dis[start] = 0;

    for (int i = 1; i <= edges.size() - 1; i++) {
        for (auto edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;

            if (dis[u] != INT_MAX && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
            }
        }
    }
}

int main() {
    int n, e; cin >> n >> e;
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int start; cin >> start;
    bellmanFord(start);

    cout << "Shortest Distances from Node " << start << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": " << dis[i] << "\n";
    }

    return 0;
}
```

### 15. Floyd-Warshall Algorithm

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int dis[N][N];

void floydWarshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dis[i][k] != INT_MAX && dis[k][j] != INT_MAX && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main() {
    int n, e; cin >> n >> e;
    memset(dis, 0x3f, sizeof(dis));

    for (int i = 1; i <= n; i++) dis[i][i] = 0;

    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = w;
    }

    floydWarshall(n);

    cout << "Shortest Distances between Nodes:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == INT_MAX) cout << "INF ";
            else cout << dis[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
```

### 16. Minimum Spanning Tree (Prim's Algorithm)

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<pair<int, int>> g[N];
bool vis[N];

int primMST(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    int mstWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (vis[u]) continue;

        mstWeight += w;
        vis[u] = true;

        for (auto it : g[u]) {
            int v = it.first;
            int weight = it.second;
            if (!vis[v]) {
                pq.push({weight, v});
            }
        }
    }

    return mstWeight;
}

int main() {
    int n, e; cin >> n >> e;
    while (e--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int start; cin >> start;
    int mstWeight = primMST(start);

    cout << "Minimum Spanning Tree Weight: " << mstWeight << "\n";

    return 0;
}
```

