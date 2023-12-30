### State Dynamic Programming


### 121. Best Time to Buy and Sell Stock
Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        
        int buy = prices[0]; 
        int sell = 0;

        for( int i = 1 ; i < prices.size() ; i++ )
        {
            buy =  std::min( buy , prices[i] );
            sell = std::max( sell , prices[i] - buy );
        }

        return sell;
    }
};
```

### Similar Questions :

1. Atmost 1 Transaction [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) 
2. Infinite Transactions [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) 
3. Atmost K Transactions  
    i. [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)   
    ii. [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) 

