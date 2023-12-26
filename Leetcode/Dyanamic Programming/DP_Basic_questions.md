
### 746. Min Cost Climbing Stairs
Link : https://leetcode.com/problems/min-cost-climbing-stairs/description/
` dp[i] = the best cheapest code to reach upto ith stair including the cost to be paid in that stair`

Code : 
```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int N = cost.size();
        vector<int> dp( N , 0 );

        for( int i = 0 ; i < N ; i++ )
        {
            if( i < 2 ) dp[i] = cost[i];
            else dp[i] = cost[i] + min( dp[i-1] , dp[i-2] );
        }

        // dp[N-1]

        return min( dp[N-1] , dp[N-2] );
        
    }
};
```


### 70. Climbing Stairs
Link : https://leetcode.com/problems/climbing-stairs/description/

` dp[i] = the number of ways to reach the ith stair in the staircase`

```cpp
class Solution {
public:
    int climbStairs(int n) 
    {
        vector<int> dp(n+1, 0);
            dp[0]=1;
            dp[1]=1;
            
            for(int i=2; i<=n; i++)
            {
                dp[i] = dp[i-1]+dp[i-2];
            }

            return dp[n];
        
    }
};
```









