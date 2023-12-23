### DFS to find the size the of each Subtree of a node including itself

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
