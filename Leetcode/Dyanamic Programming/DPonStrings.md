## DP on Strings

#### Template Code :

```cpp
for (int l = 1; l < n; ++l) {
   for (int i = 0; i < n-l; ++i) {
       int j = i + l;
       if (s[i] == s[j]) {
           dp[i][j] = /*code*/;
       } else {
           dp[i][j] = /*code*/;
       }
   }
}
```

## Related Questions :

### 647. Palindromic Substrings
Link : https://leetcode.com/problems/palindromic-substrings/description/
```cpp
class Solution {
public:
    int countSubstrings(string s) {

        // dp[i][j] -> if s[i...j] = 1 if its a palindrome and 0 if its not a palindrome
        int N = s.size();
        s.insert( s.begin() , '0' );
        vector<vector<int>> dp( N + 1 , vector<int> ( N + 1, 0 ) );
        int count = 0;

        // Base Case if len = 1 start = end and for length = 1 the string is a palindrome
        for( int start = 1 ; start <= N ; start++ ) dp[start][start] = 1 , count++;
    
        for( int len = 2 ; len <= N ; len++ )
        {
            for( int start = 1 ; start + len - 1 <= N ; start++ )
            {
                int end = start + len - 1; // 1 + N - 1

                if( len == 2 && s[start] == s[end] ) { dp[start][end] = 1 ; count++; }
                
                else if( s[start] == s[end] && dp[start+1][end-1] == 1 )
                {
                    dp[start][end] = 1 , count++;
                }
            }
        }
        return count; 
    }
};
```

## More Questions 
Problem List : https://leetcode.com/list/55afh7m7
