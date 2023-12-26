### Bitmasking Theory 

1 << N --> 2 ^ N

### Combinations Using Bitmasking 
Link : https://leetcode.com/problems/combinations/description/
Code :
```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        // Any K bits are set from nums 0 .... 2^N
        // 1 ... N
        vector<int> nums_with_k_bits_on;

        // for( int i = 0 ; i < 31 ; i++ ) if( num & ( 1 << i ) ) on++;

        for( int i = 1 ; i < (1 << n) ; i++ )
        {
            if( __builtin_popcount(i) == k ) // one of our combinations
                nums_with_k_bits_on.push_back(i);
        }

        vector<vector<int>> ans;

        for( auto mask : nums_with_k_bits_on )
        {

            vector<int> comb;
            for( int i = 0 ; i < n ; i++ )
            {
                if( (1 << i) & mask  )
                    comb.push_back(i+1);
            }
            ans.push_back(comb);
        }
        
        return ans;

    }
};
```

