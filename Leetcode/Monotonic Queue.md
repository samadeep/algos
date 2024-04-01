## Monotonic Queue

Monotonic Queue is a data structure that keeps it’s elements either entirely in non-increasing, 
or entirely in non-decreasing order. For some problems just a stack can be of use, although 
for a more standardized approach we can apply queue (or deque).


### [1499. Max Value of Equation](https://leetcode.com/problems/max-value-of-equation/)

Because `xi < xj` ,
`yi + yj + |xi - xj|` = `(yi - xi) + (yj + xj)`

So for each pair of `(xj, yj)`,
we have `xj + yj`, and we only need to find out the maximum yi - xi.
To find out the `maximum element` in a sliding window.

Use a Deque storing `yi-xi` , `xi` for each of the previous `i`s and find the max one for this `j`

#### Code : C++
```cpp
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {

        int ans = INT_MIN;
        // (yi - xi) + (yj + xj)
        // xj - xi <= k
        // deque -> x , y - x 

        deque<pair<int,int>> xy;

        for( auto point : points ){

            int x = point[0];
            int y = point[1];

            while( xy.size() && x - xy.front().first > k  ) 
                xy.pop_front();

            if( xy.size() )
                ans = max( ans , xy.front().second + x + y );
            
            while( xy.size() && y - x > xy.back().second ) 
                xy.pop_back();

            xy.push_back(make_pair(x,y-x));

        }

        return ans;
    }
};
```

### [1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

#### Explanation :
Longest subarray can be found using Sliding Window approach where we expand and shrink window
based on condition. 

Now, finding absolute difference between all element is same as finding difference
between Max and Min element inside the window. 

Finding the Max and Min element inside dynamic sizewindow is the challenge. 

This can be solved using 2 Deques. 
Maintaining 2 Deque for tracking Max and Min element gives us a `O(N)` solution.

`Max element` tracking Deque => `maxD` => Non-increasing list
`Min element` tracking Deque => `minD` => Non-decreasing list
`Mismatch condition` : `maxD.front() - minD.front() > limit`

As we loop through the elements we increase the last pointer in each step and insert nums[last] in maxD and minD. 
Now before that we need to remove elements which are less than nums[last] from maxD so
that we can maintain a  Non-increasing list, also the front of maxD will contain max element between first and last pointer 
as we will remove the front element when we find a Mismatch condition and maxD.front()==nums[first].
Incase of Mismatch condition we shrink the window by increasing first pointer.

Similarly we remove the elements from minD which are greater than nums[last] to maintain a 
Non-decreasing list and also remove the minD.front() when there is a Mismatch condition and minD.front()==nums[first].

Example Input: `nums` = `[10,1,2,4,7,2]`, limit = `5`
Output: `4` 
Following is the `simulation` of the algorithm
![image](https://assets.leetcode.com/users/images/cdb78b5f-c364-4c4b-a7b8-eaae6f88851e_1625863474.4878218.png)


#### Code : C++
```cpp
class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {

        deque<int> max_dq , min_dq;
        int N = A.size();
        int ans = 1;

        int i = 0 , j = 0;

        for( i = 0 ; i < N ; i++ ){

            while( max_dq.size() && max_dq.back() < A[i] )   max_dq.pop_back();
            while( min_dq.size() && min_dq.back() > A[i] )   min_dq.pop_back();

            max_dq.push_back(A[i]);
            min_dq.push_back(A[i]);

            while( max_dq.front() - min_dq.front() > limit ){
                if( max_dq.front() == A[j] )  max_dq.pop_front();
                if( min_dq.front() == A[j] )  min_dq.pop_front();
                j++;
            }
            ans = max( i - j + 1 , ans );
        }

        return ans;
        
    }
};
```


