### 2D Prefix Sums 


![2d Prefix sums](https://miro.medium.com/v2/resize:fit:1400/1*2Cg6VNrqQL7IODV61evbGg.png)


For a 2D array <br>
  `prefix_2d[i][j] = ∑∑arr[i][j]` <br>
  `prefix_2d[i][j] = prefix_2d[i-1][j] + prefix_2d[i][j-1] - prefix_2d[i-1][j-1] + A[i][j]`<br> <br><br>

  #### Code for 2d Prefix Calculation :
  
  ```cpp
       vector<vector<int>> prefix_2D( R + 1 , vector<int>( C + 1 , 0 ) );
        // prefix_2d[i][j] = prefix_2d[i-1][j] + prefix_2d[i][j-1] - prefix_2d[i-1][j-1] + A[i][j]

        for( int i = 1 ; i <= R ; i++ ){
            for( int j = 1 ; j <= C ; j++ ){
                prefix_2D[i][j] = prefix_2D[i-1][j] + prefix_2D[i][j-1] - prefix_2D[i-1][j-1] + matrix[i-1][j-1];
            }
        }
  ```


#### Calculating for each Submatrix 

For a given `i , j` we create a submatrix for some `{ [pre_i , pre_j] , [ i , j ] }`<br>

For each submatrix ending at `i,j` and starting at `[pre_i , pre_j]` <br>

`Submatrix-Sum = prefix_2D[i][j] + prefix_2D[pre_i-1][pre_j-1] - prefix_2D[pre_i-1][j] - prefix_2D[i][pre_j-1]`<br>

where `1 <= pre_i <= i` and `1 <= pre_j <= j` for the given `i,j`.

### Code :
```cpp

        for( int i = 1 ; i <= R ; i++ ){
            for( int j = 1 ; j <= C ; j++ ){
                for ( int pre_i = 1 ; pre_i <= i ; pre_i++ ){
                    for ( int pre_j = 1 ; pre_j <= j ; pre_j++ ){

                        int submatrix_sum = prefix_2D[i][j] + prefix_2D[pre_i-1][pre_j-1] - prefix_2D[pre_i-1][j] - prefix_2D[i][pre_j-1];

                    }
                }
            }
        }

```


### Related Problems :
[1074. Number of Submatrices That Sum to Target](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)

