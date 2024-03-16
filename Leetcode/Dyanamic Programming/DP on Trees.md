
### DP on Trees 


#### Brute-Force:

You might want to treat it as a graph and iterate from 0 to n, where you have a function `dfs(source, destination)` that returns minimum distance of source to destination. This might be really-really slow, so you might want to do some memoization. But even after memoization, time complexity is going to be O(N2)O(N^2)O(N2) because we are going to run double loop for above specified function.

### Using DP on Trees :

For each child of root:  
`res[child] += (sum of distances of root from all nodes - sum of distances of root from the nodes of the child subtree) + count of all the nodes - count of the child subtree`

`res[child] += (res[root] - (res[i] + count[i])) + (N - count[i])`

`res[child] += res[root] - res[i] - count[i] + N - count[i]`

This can be further simplified to:

`res[child] = res[root] - count[i] + N - count[i]`

`res` is the final answer.


```cpp
  # First DFS
         [TREE] |      [COUNT]     [RET]
            0   |       10          [ ] = (1+0) + (7+10) +(1+0)  = 19      
          / | \ |      / | \       / | \ 
         1  2  3|     1  7  1     0  10 0       <--- ret[root] = sum(count[child])+sum(count[child])
           /|\  |       /|\         /|\                        sum(count[child]) = travel again 「count[child]」 many times of path root->child 
          4 5 6 |      4 1 1       4 0 0                       sum(count[child]) = prev traveled paths sum
         /|     |     /|          /|   
        7 8     |    1 2         0 1    
         /      |     /           /         
        9       |    1           0           
        
   # Second DFS           
         [RET]  |                  |                  
            19  |           19     |       19             
          / | \ |          / | \   |      / | \ 
         0  10 0| [19-1+10-1] 10 0 |  28 [19-7+10-7] 0       <---  = parent.ret - root.count 
           /|\  |           /|\    |       /|\                      + (N - root.count)*1 
          4 0 0 |          4 0 0   |      4 0 0                       Eveny node other than it's subtree node: become 1 step more far away
         /|     |         /|       |     /|   
        0 1     |        0 1       |    0 1    
         /      |         /        |     /         
        0       |        0         |    0         
        
    # Ans = [19,27,15,27,17,23,23,25,23,31] 
    --------------Example--------------------------------------------    
        
        Count         Ret         Dfs update ret...
          6            8            8              8     
         / \          / \          /  \           / \
        1   4        0   3    [8-1+N-1] 3       12   6
           /|\          /|\          /|\            /|\
          1 1 1        0 0 0        0 0 0        10 10 [6-1+N-1]   N=6
```


#### [834. Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree/)

#### Code : C++
```cpp
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> tree(n);
        for( auto e : edges ){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<int> subtree_size( n , 0);
        vector<int> ans(n,0);
        
        function<void(int,int,int)> subtree_DFS = [&]( int node , int parent , int depth )
        {
            ans[0] += depth;
            subtree_size[node] = 1 ;
            for( int next : tree[node] )
            {
                if( next == parent ) continue;
                subtree_DFS( next , node , depth + 1 );
                subtree_size[node] += subtree_size[next];
            }
        };

        function<void(int,int)> sum_of_distances = [&]( int node , int parent )
        {
            for( int next : tree[node] )
            {
                if( next == parent ) continue;
                ans[next] = ans[node] + ((n - subtree_size[next]) - (subtree_size[next]));
                sum_of_distances( next , node );
            }
        };
        subtree_DFS(0,-1,0);
        sum_of_distances(0,-1);
        
        return ans;

    }
};
```
