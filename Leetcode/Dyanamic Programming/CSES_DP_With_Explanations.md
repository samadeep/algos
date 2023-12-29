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
mincoins[x] = minimum number of coins with sum x. <br>
**Transitions** :
`mincoins[sum] = min( mincoins[sum] ,  mincoins[sum-c[i]] + 1 ) for alli = 0 to N-1`

We look at the last coin added to get sum x, say it has value v. We need dp[x-v] coins to get value x-v, and 1 coin for value v. Therefore we need dp[x-v]+1 coins if we are to use a coin with value v. Checking all possibilities for v must include the optimal choice of last coin.

As an implementation detail, we use dp[x] = 1e9 = 109≈∞ to signify that it is not possible to make value x with the given coins.

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

### Coin Combinations I
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

