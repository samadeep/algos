[1235. Maximum Profit in Job Scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)

### Approach 1 : Pick and Not Pick Dynamic Programming using Binary Search
```cpp
class Solution {
public:
    int find( int i, vector<array<int, 3>>& esp, vector<int>& start, int N, vector<int>& dp) 
    {
        if (i >= N)
            return 0;
        
        if (dp[i] != -1)
            return dp[i];

        int next_index =
            lower_bound( start.begin(), start.end(), esp[i][1] ) - start.begin();


        int pick = esp[i][2] + find( next_index , esp, start, N, dp);
        int notpick = find(i + 1, esp, start, N, dp);

        return dp[i] = max(pick, notpick);

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {

        // dp[i][time] = max profit from the available jobs that can be done
        int N = startTime.size();
        vector<array<int, 3>> sep;
        vector<int> dp(N, -1);

        for (int i = 0; i < endTime.size(); i++) {
            sep.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(sep.begin(), sep.end()); // start , end , profit
        sort(startTime.begin(), startTime.end());

        return find(0, sep, startTime, N, dp);
    }
};
```
### Approach 2 : Using profit map for suffic max profit
```cpp
class Solution2 {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,vector<int>& profit) 
    {
        map<int, int> profits; // start -> profit
        unordered_map<int, vector<pair<int, int>>> jobs; 
        // start -> end , profit
        // 2 -> [3,4] , [5,7] ...
        int N = startTime.size();

        for (int i = 0; i < N; i++) 
        {
            profits[startTime[i]] = 0;     // start , profit_max
            jobs[startTime[i]].push_back({endTime[i], profit[i]});
        }


        int max_profit = 0;
        for (auto start = rbegin(profits); start != rend(profits); start++) 
        {
            // start
            for ( auto& [etime, profit] : jobs[start->first]) 
            {
                auto best_end = profits.lower_bound(etime);
                max_profit =
                    max( max_profit ,
                       ( best_end == profits.end()? 0 : best_end -> second) + profit);
            }
            start->second = max_profit;
        }

        return max_profit;
    }
};
```
