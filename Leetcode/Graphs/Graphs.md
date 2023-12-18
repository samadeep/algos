Graph 

Topic 1 : Flood Fill and Related Problems

200 : Number of Islands
Link : https://leetcode.com/problems/number-of-islands/

Code :
```cpp
class Solution {
public:
    int numIslands( vector<vector<char>>& grid ) 
    {

        int N = grid.size();
        // vector<vector<int>> graph( N , vector<int>(N,0) );
        
        vector<vector<bool>> visited( N , vector<bool>(N,0) );

        // Adjacency Matrix
        // for( int i = 0 ; i < N ; i++ )
        // {
        //     for( int j = 0 ; j < N ; j++ )
        //     {
        //         graph[i][j] = (grid[i][j] == '1');
        //     }
        // }

        auto inside_graph = [&](int i , int j)
        {
            return i >= 0 && i <= N - 1 && j >= 0 && j <= N-1; 
        };

        vector<pair<int,int>> directions = { { 0 , 1 } , { 0 , -1 } , { 1 , 0 } , { -1 , 0 }  };

        function<void(int,int)> bfs = [&]( int x , int y )
        {
            
            visited[x][y] = 1 ;

            // Go into all 4 directions
            for( auto [ dx , dy ] : directions )
            {
                int new_x = x + dx ;
                int new_y = y + dy ;

                if( inside_graph( new_x , new_y ) && grid[new_x][new_y] == '1' && !visited[new_x][new_y] )
                {
                    visited[new_x][new_y] = 1 ;
                    bfs( new_x , new_y );
                }
            }
        };

        int islands = 0;
        for( int i = 0 ; i < N ; i++ )
        {
            for( int j = 0 ; j < N ; j++ )
            {
                if( !visited[i][j] && grid[i][j] == '1' )
                {
                    bfs( i , j  );
                    islands++;
                }
            }
        }

        return islands;
    }
};
```

Related Problems :
Number of Provinces : https://leetcode.com/problems/number-of-provinces/
Max Area of Islands : https://leetcode.com/problems/max-area-of-island/description/
SUrrorunded Regions : https://leetcode.com/problems/surrounded-regions/description/
Rotting Oranges :     https://leetcode.com/problems/rotting-oranges/description/
