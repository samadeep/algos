
## Topic 2 : Disjoint Set Union 

Link : https://cp-algorithms.com/data_structures/disjoint_set_union.html

### Disjoint Set Union Data Structure Template :

```cpp
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

        if( parent_u == parent_v ) return false; // Merged 

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
```


### Question 1 : 2685. Count the Number of Complete Components
Link : https://leetcode.com/problems/count-the-number-of-complete-components/description/

```cpp
// parent -> Rank Compression / Path 
int64_t ncr( int64_t n , int64_t r )
{
    int64_t res = 1;
    if( r > n ) return 0;

    if( r > n - r ) r = n - r;

    for( int64_t i = 1 ; i <= r ; i++ )
    {
        res *= ( n - i + 1 );
        res /= i;
    }
    return res;
}

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DSU dsu(n);

        for ( auto e : edges )
        {
            dsu.merge( e[0] , e[1] );
        }

        map<int,int> parent_count ; // 0 0 0 2 2 2

        for( auto par : dsu.parent )
        {
            parent_count[par] = 0;
        }

        for( auto e : edges )
        {
            parent_count[dsu.parent[e[0]]]++;
        }

        int count = 0;

        for( auto [ p , edge_count ] : parent_count )
        {
            int64_t req = ncr( dsu.nodes_count[p] , 2 );
            // int64_t req = (dsu.nodes_count[p] * ( dsu.nodes_count[p] - 1 )) / 2; <<<<< Can use this instead of NC2
            // As any two nodes must have atleast 1 node so N * (  N - 1 ) nodes must exist so we use NC2 to calculate number of edges required
            if( edge_count >= req ) count++;
        }
        return count;
    }
};  
```



### DSU for a Matrix-Based Graph

```cpp
class Solution {
public:
    // Use The DSU Template 
    
    int countServers(vector<vector<int>>& grid) 
    {
        int N = grid.size(); int M = grid[0].size();

        DSU dsu(N*M);

        for( int row = 0 ; row < N ; row++ )
        {
            for( int col = 0 ; col < M ; col++ )
            {
                if( grid[row][col] == 1 )
                {
                    int iD1 = row * M + col ; // Use IDs for identifying the nodes as rows and columns

                    while( col < M )
                    {
                        if( grid[row][col] == 1 )
                        {
                            int iD2 = row * M + col ;

                            dsu.merge( iD1,iD2 );
                        }
                        col++;
                    }
                }
            }
        }

        for( int col = 0 ; col < M ; col++ )        
        {
            for( int row = 0 ; row < N ; row++ )
            {
                if( grid[row][col] == 1 )
                {
                    int iD1 = row * M + col ;

                    while( row < N )
                    {
                        if( grid[row][col] == 1 )
                        {
                            int iD2 = row * M + col ;

                            dsu.merge( iD1,iD2 );
                        }
                        row++;
                    }
                }
            }
        }

        map<int,int> parents;

        for( int i = 0 ; i < N * M ; i++ ) 
            parents[dsu.find_parent(i)] = 0;

        int count = 0;

        // Nodes -> 0 .. N * M - 1
        for( auto [ par , c ] : parents )
        {
            int size_component = dsu.get_component_size(par);
            if( size_component > 1 )
            {
                count += size_component;
            }
        }

        return count;


        
    }
};

/*

Matrix -> Graph
Nodes -> (N * M)

Unique  Number which represents which row and which column for each cell : 
    i * M + J -> iD 
    id % M = j and iD / M = i 

   [1] 0 0 0 1 1 0 1 0 1
    0
    0
    0
    0
    1
    0
    1
```

### More Related Problems :
-  **Evaluate Division** : https://leetcode.com/problems/evaluate-division/description/
-  **Redundant Connection** : https://leetcode.com/problems/redundant-connection/description/ [ Cycle Detection using Union Find ]
-  **Number of Operations to Make Network Connected** : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/ 

### Hard Problems :
-   **Safest Path in Grid** : https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
-   **Minimum Score of a Path Between Two Cities** : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
-   **Checking Existence of Edge Length Limited Paths** : https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/description/

