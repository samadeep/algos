## Minimim Spanning Tree

### 1584. Min Cost to Connect All Points
Link : https://leetcode.com/problems/min-cost-to-connect-all-points/

#### Kruskal's : Using DSU 

```cpp
class Solution {
public:
struct Edge
{
    public :
    int src , dst , cost;
    Edge(  int u , int v , int w ) : src(u) , dst(v) , cost(w) {};
};

class DSU
{
    public:
    int N ;// Number of Nodes
    vector<int> parent , nodes_count ;

    DSU( int n ) : N(n) , parent(n) , nodes_count(n)
    {
        iota( parent.begin() , parent.end() , 0 ); // parent[i] = i
        fill( nodes_count.begin() , nodes_count.end() , 1 ); // size[i] = 1
    }

    int find_parent( int node )
    {
        if( parent[node] == node ) 
            return node;

        return parent[node] = find_parent(parent[node]);

    }

    bool merge( int u , int v ) 
    {
        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        if( parent_u == parent_v ) return false; // Merged 

        if( nodes_count[parent_u] >= nodes_count[parent_v] )
        {
            parent[parent_v] = parent_u;
            nodes_count[parent_u] += nodes_count[parent_v];
        }
        else
        {
            parent[parent_u] = parent_v;
            nodes_count[parent_v] += nodes_count[parent_u];
        }
        return true;
    }

    int get_component_size( int node )
    {
        int parent_node = find_parent(node);
        return nodes_count[parent_node];
    }
};

    // custom comparator 
    // array -> 2nd element

    static bool comp( Edge &a , Edge &b )
    {
        return a.cost < b.cost ;
    }

    int minCostConnectPoints( vector<vector<int>>& p ) 
    {
        int N = p.size();
        vector<Edge> edges; 

        unordered_map< int, pair<int,int> > point_code;

        int code = 0;
        for( auto point : p )
        {
            point_code[code++] = make_pair( point[0] , point[1] );
        }

        // 1 , 2.  3, 4

        for( int i = 0; i < N ; i++ )
        {
            int ux = p[i][0] , uy = p[i][1];
            for( int j = i + 1 ; j < N ; j++ )
            {
                int vx = p[j][0] , vy = p[j][1];
                int w = abs( ux - vx ) + abs( uy - vy );
                edges.push_back( Edge(  i , j , w  ) );
                // vector push_back() -> custom
            }
        }

        // [ 0 , 1 , w ]
        // code[ 0 ] -> {x0 , y0}
        // code[ 1 ] -> {x1 , y1}

        sort( edges.begin() , edges.end() , comp );
        DSU dsu(N);
        int ans = 0;

        int tree_edges = 0 ;

        for( Edge e : edges )
        {
            // 0 , 1 , w
            int w = e.cost;
            // vector<Edge> mst_edge_included;
            if( dsu.merge( e.src , e.dst ) )
            {
                ans += w;
                tree_edges++;
                // mst_edge_included.push_back( e );
            } 

            if( tree_edges == N - 1 ) break;
        }

        return ans;
        
    }
};
```

#### Prim's : Using Min-Heap Data Structure

```cpp
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p ) {

        map< pair<int,int> , bool > vis;
        int N = p.size();

        priority_queue< tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>> > pq;

        map< pair<int,int> , vector<vector<int>> > adj;

        for( int i = 0 ; i < N ; i++ )
        {
            int x1 = p[i][0] , y1 = p[i][1];
            vis[ { x1 , y1 } ] = false;
            for( int j = i + 1 ; j < N ; j++ )
            {
                int x2 = p[j][0] , y2 = p[j][1];
                int dis = abs( x2 - x1) + abs( y2 - y1);
                adj[{x1,y1}].push_back({ x2 , y2 , dis });
                adj[{x2,y2}].push_back({ x1,y1,dis });
            }
        }

        // sort -> asc -> sort( , , greater<int> ) -> des
        // pq -> desc -> ( greater<int> ) -> asc
        pq.push( make_tuple( 0 , p[0][0] , p[0][1] ) );
        int mincost = 0;

        while( !pq.empty() )
        {
            auto [ cost , cx , cy ] = pq.top(); pq.pop();
            
            if( vis[{cx,cy}] == true ) continue;

            mincost += cost;
            vis[{cx,cy}] = true;

            for( auto nxt : adj[ { cx , cy } ] )
            {
                int nxt_x = nxt[0] , nxt_y = nxt[1] , nxt_dis = nxt[2];
                if( vis[ { nxt_x , nxt_y } ] == true ) continue;
                pq.push( make_tuple( nxt_dis , nxt_x , nxt_y ) );
            }
        }
        return mincost;
    }
};
```

