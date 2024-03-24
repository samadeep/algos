# DP on Strings

#### Template Code for such problems :

1. For two strings.
```cpp
/* Pre-processing. Define basic cases. */
for( int i = 1; i <= m; i++){
	for( int j = 1; j <= n; j++){
		if(s1[i - 1] == s2[j - 1]){
			/* Your code */
		}
		else{
			/* Your code */
		}
	}
}
```
2. For one string
```cpp
/* Pre-processing. Define basic cases. */
for( int len = 1; len < n; len++){
	for( int i = 0; i + len < n; i++){
		int j = i + len;
		if(s1[i - 1] == s1[j - 1]){
			/* Your code */
		}
		else{
			/* Your code */
		}
	}
}
```

### [44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)

#### **Such Approaches using states can be used only for limited states that are present and we are aware of the transitions to be in the `i-1`th index from the `i`th index for a problem. For example : In the problem **Buy and Sell Stocks** we have 3 options of sell/buy/rest in most cases so there are `3 * n` states for each index so the states are limited to we can use Finite State Machine Thinking for such problems**

The **String Pattern Matching** can be seen as running a **FSM**. 
![image](https://s3-lc-upload.s3.amazonaws.com/users/guozhenli/image_1529467714.png)

The first `for` loop builds up a FSM from `p`. The states of the machine are labeled as 0, 1, 2, ... The last state reached during the FSM building is the accepting state.

The second `for` loop scans string `s` and run the FSM, by tracking what `states` the machine is at, and what `token` is read from `s`. The `*` and `?` tokens are always available. Because you can be at multiple states at the same time, in the second loop the `states` variable is a set of integers, rather than a single integer.

Finally, if any of the state the FSM has reached matches the accepting state, we can conclude `s` and `p` match, otherwise they don't match.

The first loop (FSM building) takes O(p) time. The second loop (string scanning) iterates over `s` once, thus O(s) iterations. Overall there are O(p+s) iterations. However, more strictly speaking in each iteration of the `for char in s` loop, you also iterate through all states you may be at (`for at in states`), which can be as many interations as the number of `*`'s in `p`, which is bounded by p. Thus the overall complexity in worst case is O(p+sp). If you believe the number of `*`'s in `p` can be bounded by a constant, then the overall complexity can be reduced to O(p+s).

### **Code** :
```cpp
class Solution {
public:   
    
    bool isMatch(string s, string p) 
    {

        map<std::pair<int ,char > , int> transfers ;
        // transfer [ input ] -> next state 

        int state = 0;
        
        for (char c : p) 
        {
            if (c == '*') {
                transfers[{state, c}] = state;
            } else {
                transfers[{state, c}] = state + 1;
                state += 1;
            }
        }

        int accept = state ;
        unordered_set<int> states = {0};

        for( auto c : s )
        {
            std::unordered_set<int> newStates;

            for( auto at : states )
            {
                for (char token : {c, '*', '?'})
                {
                    auto next_state = transfers.find( { at , token } ) ;
                    if( next_state != transfers.end() )
                    {
                        newStates.insert( next_state -> second);
                    }

                } 
            }
            states = newStates;
        }

        return states.find(accept) != states.end();

    }
};
```

### Approach 2 : Tabulation :
```cpp
class Solution {
public:   
    
    bool isMatch(string s, string p) {


        if(p.length()==0)
            return (s.length()==0);
        
        int len_s = s.size() , len_p = p.size();
        vector<vector<bool>> dp( len_s + 1 , vector<bool>( len_p + 1 , false ) );

        dp[0][0] = 1 ;

        for( int i = 1 ; i <= len_p ; i++ )
        {
            if( p[i-1] == '*' ) dp[0][i] = 1 ;
            else break;
        }

        for( int i = 1 ; i <= len_s ; i++ )
        {
            for( int j = 1 ; j <= len_p ; j++ )
            {
                if( p[j-1] == '*' )
                {
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }
                else if( p[j-1] == '?' || s[i-1] == p[j-1] )
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

       return dp[len_s][len_p];

    }
};
```

### [97. Interleaving String](https://leetcode.com/problems/interleaving-string/)

![Interleaving](https://github.com/samadeep/data_structures_algorithms/blob/main/Leetcode/Dyanamic%20Programming/Images/Interleaving_picture.jpg)

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        // state -> dp[string1][string2]

       
        int N = s1.size() , M = s2.size();
        int K = s3.size();

        if( N + M != K ) return false;

        vector<vector<bool>> dp( N + 1 , vector<bool>( M + 1 , false ) );

        s1 = '0' + s1 ;
        s2 = '0' + s2 ;
        s3 = '0' + s3 ;

        // cout << s1 << s2 << s3 << endl;

        if( N + M != K ) return false;

        /*
        
        Transitions : dp[s1][s2] ->  
        Represents whether s1 + s2  is interleaving at position s1 + s2 or not

        dp[s1][s2] = dp[s1-1][s2] && s1[s1] == s3[s1+s2] || dp[s1][s2] && s2[s2] == s3[s1+s2]

        */

        for( int i = 0 ; i <= N ; i++ )
        {
            for( int j = 0 ; j <= M ; j++ )
            {
                if( i == 0 && j == 0 ) // both empty
                {
                    dp[i][j] = true;
                }
                else if( i == 0 ) // taken nothing from string 1
                {
                    dp[i][j] = dp[i][j-1] && s2[j] == s3[j];
                }
                else if( j == 0 ) // taken nothing from string 2
                {
                    dp[i][j] = dp[i-1][j] && s1[i] == s3[i];
                }
                else // taken something from both string1 and string2
                {
                    dp[i][j] = dp[i-1][j] && s1[i] == s3[i+j] || dp[i][j-1] && s2[j] == s3[i+j];
                }
            }
        }

        return dp[N][M];
        
    }
};
```
## Edit Distance / Regex Expression Matching / Scramble String

 - [Edit Distance](https://leetcode.com/problems/edit-distance/)
 - [Regex Expression Matching](https://leetcode.com/problems/regular-expression-matching/)
 - [Scramble String](https://leetcode.com/problems/scramble-string/description/)


__Link to Classical DP Problem List__ : https://leetcode.com/list/oqbiuoxe

### Other Questions :

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
