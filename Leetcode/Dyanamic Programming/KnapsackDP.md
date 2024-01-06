[416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)

### Approach 1 : Checking whether Half-Array sum is possible 
```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        // SUBSET-SUM PROBLEM WITH ARRAY_SUM / 2 
        
        int array_sum = accumulate( begin(nums) , end(nums) , 0 );
        // array_sum = 0 + nums[0] + nums[1] + nums[3]

        if( array_sum & 1 ) return false;

        int half_array_sum = array_sum/2 ;
        int N = nums.size();

        vector<vector<bool>> possible( N + 1 , vector<bool>( half_array_sum + 1 , false ) );

        for( int i = 0 ; i <= N ; i++ ) possible[i][0] = true; // make sum 0 is possible
        
        for( int taken = 1 ; taken <= N ; taken++ )
        {
            possible[taken] = possible[taken-1];

            for( int sum = 1 ; sum <= half_array_sum ; sum++ )
            {
                // dont take the ith element
                // possible[taken][sum] = possible[taken-1][sum];

                // take the ith element
                if( sum - nums[taken-1] >= 0 )
                {
                    possible[taken][sum] = ( possible[taken][sum] || possible[taken-1][sum-nums[taken-1]]);
                }
            }
        }

        return possible[N][half_array_sum];
    }
};
```
