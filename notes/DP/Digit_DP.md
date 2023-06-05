## Resources :
**LC** : https://leetcode.com/problems/count-of-integers/solutions/3595161/recusrion-dp-similar-problems-theory-of-digit-dp/
**Codeforces** : https://codeforces.com/blog/entry/53960


## Questions :

###  Question 1 : Number of digit 1
- https://leetcode.com/problems/number-of-digit-one
#### Explanation :
Keep the lower bound as 0 and upper bound as N as given then proceed as fundamentally as a digit dp where the condition is if dig_added == 1 then count increases

<details>
    
<summary> Code : CPP </summary>
    
#### Code :
```cpp
class Solution {
public:
    // dp[ digs ][ bool ][ count_ones ]
    int dp[ 10 ][ 10 ][ 2 ];

    Solution()
    {
        reset_dp();
    }
    
    void reset_dp()
    {  
        for( int i = 0 ; i < 10 ; i++ ) for( int j = 0 ; j < 10 ; j++ ) for( auto f : {1,0} ) dp[ i ][ j ][ f ] = -1;
    }

    int count_ways( int idx , bool ub_limit , vector<int> &digs , int count  )
    {
        if( idx == digs.size() ) return count;

        if( dp[idx][count][ub_limit] != -1 )
        {
            return  dp[idx][count][ub_limit];
        }
        int u_limit = ub_limit ? digs[idx] : 9;
        int ans = 0 ;

        for( int dig = 0 ; dig <= u_limit ; dig++ )
        {
            int n_count = count + (dig==1);
            ans = ans + count_ways( idx+1 , ub_limit & dig == u_limit , digs , n_count );
        }
        
        return  dp[idx][count][ub_limit] = ans;

    }
    int countDigitOne(int n) {

        vector<int> digs;

        while( n > 0 ) 
        {
            digs.push_back(n%10);
            n = n / 10;
        }   

        reverse( digs.begin() , digs.end() );

        return count_ways( 0 , 1 , digs , 0 );
        
    }
};
```
    
</details>
    
###  Question 2 : 2769. Count of Integers : Leetcode

- https://leetcode.com/problems/count-of-integers/description/

#### Explanation

The variables **tight1 and tight2** are used to keep track of whether the chosen digits so far are the **lowest possible (in num1) and highest possible (in num2), respectively.**

If **tight1 is true**, means all digits chosen so far are lowest possible value according to num1. So, we cannot choose a digit less than the digit at the current index, as it would make the number smaller than num1. Hence, we still choose the lowest digit allowed, tight1 remains true; otherwise, it becomes false, indicating that the lowest digit can be 0 in further places.

Similarly,If **tight2 is true**, it means that all the digits chosen so far are at their highest possible value according to num2. Therefore, we cannot choose a digit higher than the digit at the current index, as it would make the number larger than num2.

**Time complexity:** : $$O( N(digits) * Sum) i.e. O(logN * Sum)$$ 

    
<details>
    
<summary> Code : CPP </summary>
        
#### Code :

```cpp

    class Solution {
    
    public:
   
    const int MOD = 1e9 + 7;
    
    int dp[ 25 ][ 405 ][ 2 ][ 2 ];
    
    void reset_dp()
    {
        for( int i = 0 ; i < 25 ; i++ )
        {
            for( int j = 0 ; j < 405 ; j++ )
            {
                for( auto a : {0,1} )
                {
                    for( auto b : {0,1} )
                    {
                        dp[i][j][a][b] = -1;
                    }
                }
            }
        }
    }
    
    int count_occur( string &s1 , string&s2 , int id , bool lb_lim , bool ub_lim , int cursum )
    {
        if( cursum < 0 ) return 0;

        if( id == s1.size() )
        {
            return 1;
        }

        if( dp[ id ][ cursum ][ lb_lim ][ ub_lim ] != -1 ) return dp[ id ][ cursum ][ lb_lim ][ ub_lim ];

        int lb = lb_lim ? s1[id] - '0' : 0;
        int ub = ub_lim ? s2[id] - '0' : 9;

        int ans = 0;

        for( int dig = lb ; dig <= ub ; dig++ )
        {
            (ans += count_occur( s1 , s2 , id+1 , lb_lim & dig == lb , ub_lim & dig==ub , cursum - dig ))%MOD;
            ans %= MOD;
        }

        return dp[ id ][ cursum ][ lb_lim ][ ub_lim ] = ans;


    }
    
    int count(string num1, string num2, int min_sum, int max_sum) {

        // min_sum <= X <= max_sum --> find the number of numbers

        // max_sum to min sum total numbers in between of X


        num1 = string( num2.size()-num1.size() , '0' ) + num1;

        reset_dp();
        int num1_occur = count_occur( num1 , num2 , 0 , 1 , 1 , min_sum - 1 );
        
        reset_dp();
        int num2_occur = count_occur( num1, num2 , 0 , 1 , 1 , max_sum);

        return (num2_occur - num1_occur)%MOD;   
    }
};
```
    
</details>
