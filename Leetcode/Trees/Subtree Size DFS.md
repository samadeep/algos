

## DFS to find the size the of each Subtree of a node including itself

Code :

```cpp
    vector<int64_t> subtree_size( N + 1 , 0 );
    
    function<void(int,int)> subtree_DFS = [&]( int node , int parent )
    {
	      for( int next : graph[node] )
	      {
	          if( next == parent ) continue;
	          
	          subtree_DFS( next , node );
	          subtree_size[node] += subtree_size[next];
	      }
	      
		subtree_size[node] += 1 ; 
		
    };
```

### Subtree and Component Based Graph Questions :

**2973. Find Number of Coins to Place in Tree Nodes**
- Link : https://leetcode.com/problems/find-number-of-coins-to-place-in-tree-nodes/description/

**2872. Maximum Number of K-Divisible Components**
- Link : https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/

**2440. Create Components With Same Value**
- Link : https://leetcode.com/problems/create-components-with-same-value/description/
