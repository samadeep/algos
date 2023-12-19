
## Topic 2 : Disjoint Set Union 

Link : https://cp-algorithms.com/data_structures/disjoint_set_union.html

### Disjoint Set Union Data Structure Template :

```cpp
// parent -> Rank Compression / Path 

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

        if( parent_u == parent_v ) return false;

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
    int getSize( int node )
    {
        int parent_node = parent[node];
        return nodes_count[parent_node];
    }

};

```
### Question 1 : 2685. Count the Number of Complete Components
Link : https://leetcode.com/problems/count-the-number-of-complete-components/description/

```cpp
// parent -> Rank Compression / Path 

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

        if( parent_u == parent_v ) return false;

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
    int getSize( int node )
    {
        int parent_node = parent[node];
        return nodes_count[parent_node];
    }

};

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
