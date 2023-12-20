## Topic 3 : Shortest Paths 


Graph Dense or Sparse 


#### Shortest Paths : Dijkstra's Algorithm 

Take infinity distance as 
const int inf = 1e17;
-> 	[ src , dst , W ]
```cpp
struct Edge
{
	
	int src , dst , w;
	
};
```


```cpp
void dijkstra( adj_time , int src , int dst )
{
	
	// priority_queue < type , vector<type> , greater<type> > 
	
	priority_queue < pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
	// multiset<pair<int,int>> pq;
	
	// Priority Queue is created on the basis of distance from the all the next nodes available
	// dis1 , nxt1 | dis2 , nxt2 | dis3 , nxt3 | dis4 , nxt4
	// dis1 <= dis2 <= ... <= disk
	

	pq.push( { 0 , src } ); 
	vector<bool> vis( N , false );
	
	vector<int> dist( N , inf );
	
	dist[src] = 0;
	
	// pq -> E * logV + V 
	
	while( !pq.empty() )
	{
		
		auto [ new_cost , node ] = pq.top(); pq.pop(); // next time 
		// pq.begin() ; 
		// pq.erase(*pq.begin());
		
		vis[node] = 1 ;
		
		if( dist[node] < new_cost ) continue; // No need to update // 1
		
		for( auto [ nxt , cost ] : adj_time[node] ) 
		{
			
			if( vis[nxt] ) continue; // 1
			
			// I have already reached in previous iterations
			
			if( dist[nxt] > dist[node] + cost )
			{
				dist[nxt] = dist[node] + cost;
				
				pq.push( { dist[nxt] , nxt  } );
			}
		}
	}
	
}
```


## Related :

### Shortest Paths : Bellman Ford Algorithm 
- Only Detects the negative weight 
Time Comeplexity : $$O( V * E )$$

```cpp
vector<int> dist( N , inf );
vector<int> dist_upd( N , inf );

for( int i = 1 ; i <= V - 1 ; i++ )
{

	dist_upd = dist;
	for( int j = 0 ; j < E ; j++ )
	{
		int src = edges[i][0] , dst = edges[i][1] , w = edges[i][2];
		
		if( dist_upd[src] != inf && dist_upd[src] + w < dist_upd[dst]  )
		{
			 dist_upd[dst] = dist_upd[src] + w ;
		}
	}
	
	if( dist_upd == dist ) break; 
	
}

for( int i = 0 ; i < E ; i++ )
{
	int src = edges[i][0] , dst = edges[i][1] , w = edges[i][2];
	
	if( dist_upd[src] + w < dist_upd[dst] ) 
	{
		cout << "Negative Cycle Detected..." << endl;
	}
}
```

### 743. Network Delay Time

Max Time to reach a destination and -1 if one of them is unreachable

```cpp
const int inf = 1e9;

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        // u , v , weight
        // adj[u].push_back( { v , weight } ) ;

        vector<vector<pair<int,int>>> adj_time(n+1);
        
        vector<bool2> vis(n+1,false);
        vector<int> d(n+1,inf);

        for( vector<int> &t : times ) 
            adj_time[t[0]].push_back({t[1],t[2]});

        priority_queue< pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>> > pq;
        // distance , node 

        d[k] = 0;

        pq.push({0,k});

        while( !pq.empty() )
        {
            auto [ cost , curr_node ] = pq.top();
            pq.pop();

            vis[curr_node] = true; 

            if( cost > d[curr_node] ) continue;

            for( auto [ next , next_cost  ] : adj[curr_node] )
            {
                if( vis[next] == true ) continue;

                if( d[next] > d[curr_node] + next_cost )
                {
                    d[next] = d[curr_node] + next_cost;
                    pq.push({ d[next] , next });
                }
            }
        }

        int res = 0;
        for( int i = 1 ; i <= n ; i++ )
        {
            if( res == inf ) return -1 ;
            res = max( res , d[i] );
        }

        return res;
        
    }
};
```




























