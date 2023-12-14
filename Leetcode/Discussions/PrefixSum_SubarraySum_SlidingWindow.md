
### Prefix Sums 

array
A -> 		1 2 3 4 5 6 6 
prefix_sum[i] = sum[ arr[0] + ... arr[i] ]
prefix_sum = 1 3 6 10 ....

Consider : int arr[N] 
Using 1 indexing 
prefixsum[N+1] 
prefix[0] = 0 
prefix[i] -> sum[ arr[0] + ... arr[i-1] ]

#### Generating the prefix sum array in 1 indexing
```cpp
for( int i = 1 ; i <= N ; i++ )
{
	preix[i] = prefix[i-1] + A[i-1];
}
```

subarray sum i...j -> O(1)

sum -> 2 .... 5 

sum[2...5] = pref[6] - pref[2]

1D Prefix 
2D Matrix 
Link : https://usaco.guide/silver/more-prefix-sums?lang=cpp

__________________________________________________

### Optimising Sum of Subarray using Contribution Technique
```cpp
for( int s = 0 ; s < N ; s++ )
{
	for( int e = s ; e < N ; e++ )
	{
		total += pre[e+1] - pre[s]; // 1 indexing -> N^2
	}
}
```

Newer Data Types : https://en.cppreference.com/w/cpp/types/integer
int16_t
int64_t 
int32_t 

```
for( int i = 0 ; i < N ; i++ )
{
	sum += 1LL * (i + 1) * ( N - i ) * A[i] ;
}
```

Sliding Window Template 
-----------------
```cpp
map<int,int> freq 
int start = 0;

for( int e = 0 ; e < N ; e++  )
{
	freq[e]
	
	condition -> fix the sliding window
	
	check condition and update answer 
}
```
-----------------
