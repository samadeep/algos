
## Matrix Chain Multiplication

**Problem : If a chain of matrices is given, we have to find the minimum number of the correct sequence of matrices to multiply.**

The problem is not actually to perform the multiplications, but **merely to decide in which order** to perform the multiplications.  
**Note**: no matter how we **parenthesize** the product, the result will be the same. For example, if we had four matrices A, B, C, and D, we would have:

**(ABC)D = (AB)(CD) = A(BCD) = ....** 

However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,

(AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations  
A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.

Clearly the first **parenthesization** requires **less number of operations**.  
Note ; We'll be given an array arr[ ] which represents the chain of matrices such that the ith matrix arr[i] is of dimension arr[i-1] x arr[i].  

That's why we start out **'k'** i.e partition from 'i' =1 so that arr[ 1] is of dimentions arr[1-1] * arr[1] else we'll get index out of bound error Eg arr[0-1] * arr[0] is not possible  

So first half of the array **is from i to k & other half is from k+1 to j**  

Also we need to find the cost of multiplication of these 2 resultant matrixes (first half & second half) which is nothing but  `arr[i-1] * arr[k] * arr[j]`


**Code for given Matrix Dimensions :**
```cpp
int matrixMultiplication(int N, int v[])
{
	int dp[501][501] = {0};

	for(int s=N-1;s>=0;s--){
		for(int e=s+2; e < N; e++){
			dp[s][e] = INT_MAX;
			for(int cut =s+1; cut <=e-1; cut++)
				dp[s][e] = min( dp[s][e], dp[s][cut] + dp[cut][e] +v[s]*v[cut]*v[e] );
		}
	}

	return dp[0][N-1];
}

```


### [1547. Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

#### Explanation :


### Code :

```cpp
class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        // dp[ i ] [ j ] ----> minimum cost if i....j of rod is considered
        cuts.push_back(0);
        cuts.push_back(n);


        sort( cuts.begin() , cuts.end() );
        vector<vector<int> > dp(cuts.size(),vector<int> (cuts.size(),INT_MAX));

		// Base Cases :
         for( int i = 0 ; i < cuts.size() ; i++ )
        {
            dp[i][i] = 0;
            if(i+1 < cuts.size()) dp[i][i+1] = 0; 
        }
        
        for( int dis = 2; dis < dp.size() ; dis++ )
        {
            for( int start = 0 ; start < dp.size() - dis ; start++)
            {
                int end = start + dis;

                for( int l = start+1 ; l < end ; l++ ) // cut at every point start ... start+ 1 ....start + 2 ..end
                {
                    dp[start][end] = min( dp[start][end] ,
                                                dp[start][l] + dp[l][end]);
                } 
                dp[start][end] += ( cuts[end] - cuts[start]);
            }
        }

        return dp[ 0 ][ cuts.size() - 1 ];
   
    }
};
```
### [1039. Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/)

#### Explanation :
dp[i][j] means the minimum score to triangulate A[i] ~ A[j],
while there is edge connect A[i] and A[j].

We enumerate all points A[k] with i < k < j to form a triangle.

The score of this triangulation is `dp[i][j] = dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]`
![](https://github.com/samadeep/data_structures_algorithms/blob/main/Leetcode/Dyanamic%20Programming/Images/image_1557470819.png)
Choosing K from all the availble points between `i .... j`
![](https://github.com/samadeep/data_structures_algorithms/blob/main/Leetcode/Dyanamic%20Programming/Images/image_1557471328.png)


#### Code :

```cpp
class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp( n , vector<int>( n , 0 ) );

        // [0 .. 2] -> 3 check for min 3 points 

        for( int g = 2 ; g < n ; g++ ){
            for( int i = 0 , j = g ; j < n ; i++,j++ ){
                int min_cost = INT_MAX;
                for( int k = i + 1 ; k < j ; k++  ){
                    int val = v[i] * v[j] * v[k];
                    val = val + dp[i][k] + dp[k][j];

                    min_cost = min( min_cost , val );

                }

                dp[i][j] = min_cost;
            }
        }

        return dp[0][n-1];
    }
};
```



#### Related Problems :

- [1039. Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/)
- [664. Strange Printer](https://leetcode.com/problems/strange-printer/)
- [1130. Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)
- [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/)
- [1000. Minimum Cost to Merge Stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/)
