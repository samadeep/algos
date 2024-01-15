### Merge Intervals
Link : https://leetcode.com/problems/merge-intervals/

Code:
```cpp
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), less_than());
        
        vector<vector<int>> result;

        int N = intervals.size();
        
        int start =  intervals[0][0];
        int maxEnd = intervals[0][1];
        
        for (int i = 1; i < N; i++) {
            
            if ( intervals[i][0] <= maxEnd) {
                maxEnd = max(maxEnd, intervals[i][1]);
                continue;
            } 
            
            else {
                result.push_back({start, maxEnd});
                start = intervals[i][0];    // previous start end
                maxEnd = intervals[i][1];   // current end
            }
        }

        result.push_back({start, maxEnd});
        return result;
        
    }
```
### Insert Interval
Link : https://leetcode.com/problems/insert-interval

Code :
```cpp

```

More Questions : 
- Data Stream as Disjoint Intervals <br>
  Link : https://leetcode.com/problems/data-stream-as-disjoint-intervals/

