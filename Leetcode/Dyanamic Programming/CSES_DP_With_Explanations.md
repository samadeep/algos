## CSES Problems on Dynamic Programming

Link : https://cses.fi/problemset/list/

Template For all Problems :
```cpp
// Header Files
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);srand(time(NULL))
const int MOD = 1e9 + 7 ;
const int inf = 1e9+7;

void solve()
{
  
}

int main()
{
	fastio;
	int t = 1;
	while( t-- )
	{
		solve();
	}
	
}
```

### 1. Dice Combinations

**State** :
dp[x] = number of ways to make sum x using numbers from 1 to 6.<br>

**Transitions** :
For a target sum :
`dp[sum] = dp[sum-1] + dp[sum-2]   + dp[sum-3] + dp[sum-4] + dp[sum-5] + dp[sum-6]`

Sum over the last number used to create x, it was some number between 1 and 6. For example, the number of ways to make sum x ending with a 3 is dp[x-3]. Summing over the possibilities gives dp[x] = dp[x-1] + dp[x-2] + dp[x-3] + dp[x-4] + dp[x-5] + dp[x-6].

We initialize by dp[0] = 1, saying there is one way with sum zero (the empty set).

The complexity is 𝑂(𝑛)

```cpp
void solve()
{
	  int target;
    cin >> target;
    vector<int> dp(target+1);

    dp[0] = 1;

    for( int sum = 1 ; sum <= target ; sum++ )
    {
        for( int x = 1 ; x <= 6 ; x++ )
        {
            if( sum - x >= 0 ) dp[sum] = (dp[sum] % MOD +  dp[ sum - x ] % MOD ) %MOD;
        }
    }
    cout << dp[target] << endl;
}
```

### 2 . Minimizing Coins
This is a classical problem called the **unbounded knapsack problem**.<br>

**State**:
`mincoins[x] = minimum number of coins with sum x.` <br>
**Transitions** :
`mincoins[sum] = min( mincoins[sum] ,  mincoins[sum-c[i]] + 1 ) for alli = 0 to N-1`

We look at the last coin added to get sum x, say it has value v. We need mincoins[x-v] coins to get value x-v, and 1 coin for value v. Therefore we need dp[x-v]+1 coins if we are to use a coin with value v. Checking all possibilities for v must include the optimal choice of last coin.

As an implementation detail, we use mincoins[x] = 1e9 = 109≈∞ to signify that it is not possible to make value x with the given coins.

The complexity is 𝑂(𝑛⋅𝑡𝑎𝑟𝑔𝑒𝑡)
```cpp
const int inf = 1e9+7;
void solve()
{
    int target,N;
    cin >> N >> target;

    vector<int> coins(N);

    for( auto &x : coins ) cin >> x;

    vector<int> mincoins(target+1,inf);
    mincoins[0] = 0;

    for( int sum = 1 ; sum <= target ; sum++ )
    {
        for( auto coin : coins )
        {
            if( sum - coin >= 0 )
                mincoins[sum] = min( mincoins[sum] , mincoins[sum-coin] + 1 );

        }
    }
    cout << (mincoins[target] == inf ? -1 : mincoins[target]) << endl;
}
```

### 2. Coin Combinations I
Similar Implementation to Minimising Coins only here we look at ways instead of how to minimise the coins

**State**:
`ways[x] = number of ways to make value x`  <br>
**Transitions** :
`ways[sum] += ways[sum-coin[i]] for each coin available`

```cpp
void solve()
{
    int target,N;
    cin >> N >> target;

    vector<int> coins(N);
    for( auto &x : coins ) cin >> x;

    vector<int> ways(target+1,0);
    ways[0] = 1; // to make zero there is only 1 way

    for( int sum = 1 ; sum <= target ; sum++ )
    {
        for( auto coin : coins )
        {
            if( sum - coin >= 0 )
                (ways[sum] += ways[sum-coin])%MOD ;

        }
    }

    cout << ways[target] << endl;
}
```

### Optimised Code :
```cpp
typedef long long ll;
const int maxN = 100;
const int maxX = 1e6;
const ll MOD = 1e9+7;
 
int N, X, c[maxN];
ll dp[maxX+1];
 
int main(){
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++)
        scanf("%d", &c[i]);
 
    dp[0] = 1;
    for(int i = 0; i < X; i++)
        if(dp[i] != 0)
            for(int j = 0; j < N; j++)
                if(i+c[j] <= X)
                    dp[i+c[j]] = (dp[i+c[j]] + dp[i]) % MOD;
 
    printf("%lld\n", dp[X]);
}
```

### 4. Coin Combinations II
Initially, we say we have ways[0][0] = 1, i.e we have the empty set with sum zero.

When calculating ways[i][x], we consider the i'th coin. Either we didn't pick the coin, then there are ways[i-1][x] possibilities. Otherwise, we picked the coin. Since we are allowed to pick it again, there are ways[i][x — <value of i'th coin>] possibilities (not ways[i-1][x — <value of i'th coin>] possibilities).

Because we consider the coins in order, we will only count one order of coins. This is unlike the previous task, where we considered every coin at all times.

But we can use a a single ways[target] for all the calculations 

```cpp
void solve()
{
    int N , target ; cin >> N >> target;

    vector< int > ways( target + 1 , 0 );
    vector<int> coins(N);

    for( auto &x : coins ) cin >> x;
    ways[0] = 1 ;

    // ways[ coin_level ][ sum ] = ways[ coin_level - 1 ][ sum - coin[i] ]

    // coin -> sum

    for( int coin_level = 1 ; coin_level <= N ; coin_level++ )
    {
        for( int sum = 0 ; sum <= target ; sum++ )
        {
            if( sum - coins[coin_level-1] >= 0 )
            {
                (ways[sum] = ways[sum]%MOD + ways[sum - coins[coin_level-1]]%MOD )%MOD;
                 ways[sum] %= MOD;
            }
        }
    }

    // ways[level] = ways[level-1] can be replaced by a single array 'ways'

    cout << (ways[target])%MOD << endl;
}
```

### 5. Removing Digits

`minways[x]` = minimum number of operations to go from x to zero.

When considering a number x, for each digit in the decimal representation of x, we can try to remove it. The transition is therefore: 
`minways[x] = min𝑑∈𝑑𝑖𝑔𝑖𝑡𝑠(𝑥) minways[x-d].`

We initialize minways[0] = 0.

The complexity is 𝑂(𝑛)
.

```cpp
void solve()
{
    int N ; cin >> N ; vector<int> minways(N+1,1e9);

    minways[0] = 0;

    for( int i = 0 ; i <= N ; i++ )
    {
        string num = to_string(i);
        for( auto c : num )
        {
            minways[i] = min( minways[i] , minways[i-(c-'0')] + 1 );
        }
    }

    cout << minways[N] << endl;
    
}
```
### 6. Grid Paths
ways[r][c] = number of ways to reach row r, column c.

We say there is one way to reach (0,0), ways[0][0] = 1.

When we are at some position with a ., we came either from the left or top. So the number of ways to get to there is the number of ways to get to the position above, plus the number of ways to get to the position to the left. We also need to make sure that the number of ways to get to any position with a # is 0.

```cpp
void solve()
{
    int n ; cin >> n;

    vector< vector<ll> > ways(n,vector<ll>(n,0));

    ways[0][0] = 1 ;

    for( int i = 0 ; i < n ; i++ )
    {
        string row ; cin >> row;
        for( int j = 0 ; j < n ; j++ )
        {
            if( row[j] == '.' ) 
            {
                if( i > 0 ) ways[i][j] += ways[i-1][j] % MOD;
                if( j > 0 ) ways[i][j] += ways[i][j-1] % MOD;
                ways[i][j] %= MOD;
            }
            else
            {
                ways[i][j] = 0;
            }

        }
    }

    cout << ways[n-1][n-1] % MOD << "\n" ;
	
    
}
```


### 7. Book Shop

This is a case of the classical problem called 0-1 knapsack.
<br>
`dp[i][x]` = maximum number of pages we can get for price at most x, only buying among the first `i` books.

Initially `dp[0][x] = 0` for all x, as we can't get any pages without any books.

When calculating `dp[i][x]` , we look at the last considered book, the i'th book. We either didn't buy it, leaving x money for the first i-1 books, giving `dp[i-1][x]` pages. Or we bought it, leaving `x-price[i-1]` money for the other `i-1` books, and giving `pages[i-1]` extra pages from the bought book. 
<br>
Thus, buying the i'th book gives `dp[i-1][x-price[i-1]] + pages[i-1]` pages.

```cpp
void solve()
{
    int N , budget ; 
    cin >> N >> budget;
    vector<int> pages(N) , prices(N);

    for( int &x : prices ) cin >> x;
    for( int &x : pages )  cin >> x;

    vector< vector<ll> > dp(N+1,vector<ll>(budget+1,0));
    // Dp[i][x] -> i books are taken and we have incurred a cost of X

    // Final Subproblem -> Dp[N][Budget]
    // 0 / 1 Knapsack


    // 5 ->   Having 2 books : [5 , 18  ]  [5 , 30]
    // 9 ->  9 - 5 -->  dp[i-1][4] + 30 or dp[i-1][4] + 18

    // 10 ->  10 - 5 -->  dp[1][ 5 ] ->  dp[0][0] + 30 = 30 
    //                    dp[2][10] ->  dp[1][5]=30 + 18 = 48

    // dp[1][5] -> 30
    // dp[2][10] -> 18 + 30 = 48


    for( int i = 1 ; i <= N ; i++ )
    {
        for( int now_budget = 0 ; now_budget <= budget ; now_budget++ )
        {
            // Don't take the ith book and move on
            dp[i][now_budget] = dp[i-1][now_budget];

            // Take the ith book
            int left_money = now_budget - prices[i-1];
            if( left_money >= 0 )
            {
                dp[i][now_budget] = max( dp[i][now_budget] , dp[i-1][left_money] + pages[i-1] );
            }
        }
    }

    cout << dp[N][budget] << endl;
    
}
```



