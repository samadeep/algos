# Standard Pattern DP with Explanation

## Longest Palindromic Subsequence

### Explanation :
```
Let we have a string S :    C1 - M - C2 
can be its representation : C1, C2 : Characters , M : Rest of Strings

We can get Subsequences :[ C1  or  C1-M  or  M  or M-C2 or C1 - M - C2 ]

For Longest Palindromic Subsequence :

LPS(S) = 
C1 : LPS = 1 // for a single character LPS = 1
C2 : LPS = 1
C1 - M : LPS(M) 
// Does not change as LPS(M) = LPS(C1-M) as thats the max Possible LPS

M - C2 : LPS(M)

if C1 == C2 then LPS( C1 - M - C2 ) = 2 + LPS( M ) // as C1 and C2 is added

else if they are not equal then :

LPS ( C1 - M - C2 ) = max( LPS( C1-M ) , LPS( M-C2 ) ) 
```


```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {

    // Longest Palindromic Subsequence : Gap Strategy

        int N = s.size();
        int LPS[N+1][N+1];

        // initialise the dp
        for( int i = 0 ; i < N ; i++ )
        {
            LPS[i][i] = 1; // starting from i ... i ending in i LPS = 1 ----> gap = 0 i..i 
        }

        // Traverse as id , id + gap
        for( int gap = 1 ; gap < N ; gap++ )
        {
            for( int id = 0 ; id+gap < N ; id++  )
            {
                int start = id, end = id+gap; // left limit and right limit 

                if( gap == 1 ) LPS[start][end] = (s[start] == s[end])? 2 : 1 ;

                else
                {
                    if( s[start] == s[end] )
                    {
                        LPS[start][end] = 2 + LPS[start+1][end-1];
                    }
                    else
                    {
                        LPS[start][end] = max( LPS[start+1][end] , LPS[start][end-1] );
                    }
                }
            }
        }
        return LPS[0][N-1];
        
    }
};

```


## Longest Increasing Subsequence

### Approach 1 : LIS Array : 0(N^2) Approach

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& A) {

        int N = A.size();
        vector<int> LIS(N,1);
        int ans = 0 ;

        for( int i = 1 ; i < N ; i++ )
        {
            for( int j = 0 ; j < i ; j++ )
            {
                if( A[i] > A[j] && LIS[i] < LIS[j] + 1 )
                {
                    LIS[i] = LIS[j] + 1;
                }
            }
        }

        return *max_element( LIS.begin() , LIS.end() );
        
    }
};
```

### Approach 2 : LIS with Binary Search Optimisation

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& A) {

        vector<int> LIS;
        int ans = 0 ;

        int N = A.size();

        for( int i = 0 ; i < N ; i++ )
        {
            if( LIS.empty() || LIS.back() < A[i] )
            {
                LIS.push_back(A[i]);
            }
            else
            {
                int idx = lower_bound( LIS.begin() , LIS.end() , A[i] ) - LIS.begin() ;  
                LIS[idx] = A[i];
            }

            ans = max( ans , (int)LIS.size() );
        }

        return ans;
        
    }
};
```


----


## Longest Common Subsequence : Multi-sequence DP

### Explanations :
```
Let us have two sequences : (may be string or any other type of data)
A[i] . . . . . . N terms

B[i] . . . . . . M terms

### Understanding:
---
**Note : Subsequences( ABC ) —> Subseq( BC ) ( A refuses ) + A + Subseq( BC ) ( A accepts ) <———**

DP[ i ][ j ] ——> LCS upto i of A terms and j of B terms taken from the first

return DP[N][M] // Answer


dp[0][j….M] = 0 and dp[i…N][0] = 0 
// Base Cases —> if 0 Letters taken from A or B then LCS = 0

if( first i terms taken from A and first j terms taken from B ) —> 
### DP Equation and State Transitions : 
---
Consider two strings : 

                        C1-R1   C2-R2  

// C1 , C2 are starting characters and R1 , R2 are the rest of 
// the strings

if C1 not equal to C2 : max( LCS(C1-R1,R2) , LCS(R1,C2-R2 )) 
// that is previous get carried forward

if C1 == C2 : then LCS( C1-R1 ,  C2-R2  ) = 1 + LCS( R1 , R2 ) 
// that is we add 1 more to the already found LCS

```

### Implementation : CPP
--- 
```cpp
int dp[ N ][ M ]

for( int taken_A = 0 ; taken_A <= N ; taken_A++ )
    {

        for( int taken_B = 0 ; taken_B <= M ; taken_B++ )
        {
            if( taken_A == 0 or taken_B == 0 ) dp[ taken_A ][ taken_B ] = 0;
            
            else if( A[taken_A - 1] == B[taken_B - 1] ) dp[taken_A][taken_B] = 1 + dp[taken_A-1][taken_B-1];

            else dp[taken_A][taken_B] = max( dp[taken_A][taken_B-1] , dp[taken_A-1][taken_B] );
        }

    }
```
