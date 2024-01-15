### Next Permutation Algorithm

In total an array has N! Permutations next_permutation( A.begin() , A.end()) gives the next bigger permutation of the given sequence of numbers

![Next Permutation](https://media.geeksforgeeks.org/wp-content/uploads/20220908060940/Nextpermutation.png)
 ```cpp
void next_permutation( vector<int> &A )
{
 int break_point = -1;
	// Complete Ascending Order : 1 2 3 4 5
		
	for( int i = N - 2 ; i >= 0 ; i-- )
	{
		if( A[i] < A[i+1] )
		{
			break_point = i;
			break;
		}
	}

	if( break_point == -1){ reverse(A.begin(),A.end()); return; }

	for( int i = N - 1 ; i >= 0 ; i-- )
	{
		if( A[break_point] < A[i] )
		{
			swap( A[break_point] , A[i] );
			reverse(A.begin(),A>end());
			return;
		}
	}

	return;
}
```
