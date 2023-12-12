
### 424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {

        int N = s.size();
        int ans = 0;

        int end = 0 , start = 0;
        unordered_map<int,int> freq;
        int mx_count = 0;

        while( end < N )
        {
            // Lengthen Window
            freq[s[end]]++;
            mx_count = max( mx_count , freq[s[end]] );
            int window_len = end - start + 1 ;

            if( window_len > k + mx_count )
            {
                freq[s[start]]--;
                start++;

                mx_count = 0;
                
                for( auto [ c , count ] : freq ) 
                    mx_count = max( mx_count , count ); 
            }

            ans = max( ans , end - start + 1  );
            end++;

        }
        
        return ans ;
    }
};
```

// (window.length() - largestCount) will not give the actual result if u dont't do iterate on hash map every time, But if u want to keep largestCount every time correct, u need to iterate over the map.
// We are only trying to reduce the value of (window.length() - largestCount) to <= k right ?, So shrinking the window.length() can actually reducae the value of (window.length() - largestCount). Thats why we r not updating largestCount.
