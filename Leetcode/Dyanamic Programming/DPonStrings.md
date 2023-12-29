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

### 1531. String Compression II

#### Approach 1 : Recursion and 3D Memoization
Link : https://leetcode.com/problems/string-compression-ii/description/

```cpp
    int dp[101][27][101][101]; -> Define Outside class for space in Heap 

      // ---> Class -> Variables -> stack
    // index , prev_char , freq_upto_prev , int ops
    // char -> int ==> char - 'a'
    // dp[id = 101 ][prev_char = 27 ][freq_prev = 101 ][ops = 101 ] -> [10^6 * 27] -> not available in stack
    int count( string &s , int id , int prev_char , int freq_prev , int ops   )
    {
        if( ops < 0 ) return 100000; // option to be rejected -> Max will auto eliminate 

        if( id >= s.size() ) return 0;

        if( dp[id][prev_char][freq_prev][ops] != -1 ) return dp[id][prev_char][freq_prev][ops];
   
        int delete_id = count( s,  id + 1 , prev_char , freq_prev , ops - 1  );

        int take_i = 0;

        if( s[id] - 'a' == prev_char )
        {
            if( freq_prev == 1 || freq_prev == 99 || freq_prev == 9 ) 
            {
                take_i = 1 +  count( s,  id + 1 , (s[id] - 'a') , freq_prev + 1 , ops  );
            }
            else
            {
                take_i = count( s,  id + 1 , (s[id] - 'a') , freq_prev + 1 , ops  );
            }
        }
        else
        {
            take_i = 1 + count( s,  id + 1 , (s[id] - 'a') , 1 , ops  );
        }

        return dp[id][prev_char][freq_prev][ops] = min( delete_id , take_i );

    }


    int getLengthOfOptimalCompression(string s, int k) {
        memset( dp , -1 , sizeof(dp) );
        // memset( variable , value , sizeof(dp) ) --> assign same values to all in the address location
        return count( s , 0 , 26 , 0 , k );
        
    }
```

#### Approach 2 : Bottom - Up DP

```cpp
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int K) {

        int N = s.size();
        // s.insert( s.begin() , '0' );
        // Base Case --> dp[0][any Number of operations] = 0

        vector<vector<int>> dp( N + 1 , vector<int>( K + 1 , INT_MAX  ) );

        for( int i = 0 ; i <= K ; i++ ) dp[0][i] = 0;

        for( int i = 1 ; i <= N ; i++ )
        {
            for( int ops = 0 ; ops <= K ; ops++ )
            {
                if( ops ) dp[i][ops] = dp[i-1][ops-1];
                int same = 0 , del = 0 ; 
                int pos = i;
                for( ; pos >= 1 ; --pos )
                {
                    if( s[i-1] == s[pos-1] ) same++;
                    else del++;

                    if( del > ops ) break;

                    dp[ i ][ ops ] = min( dp[ i ][ ops ] ,    dp[pos-1][ops-del] + 1 + ((same>=100)?3:(same>=10)?2:(same>1)?1:0));

                }
            }
        }

        return dp[N][K];
        
    }
```

## More Questions 
Problem List : https://leetcode.com/list/55afh7m7
