
### Binary Search for answer

```
low ..[.]... high
function() -> Predicate Function -> is this answer valid ?

function<bool()> predicate = [&]( int x )
{
	x -> valid ????
}

low = 0 , high = 1e9 for int
low = 0 , high = 1e18 for long long 

int low = 0 , high = MAX(A)

int ans = -1;
while( low <= high )
{
	int mid = ( low + high ) >> 1; // low + (high - low) / 2;


	if( predicate( mid ) )
	{
		ANS = MID;
		HIGH = MID - 1 OR LOW = MID + 1
	}
	else
	{
		high = mid - 1 OR low = mid + 1
	}
}

RETURN ANS;
```

**List of Similar Questions :**

1. [Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) Problem ID: 1011
2. [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) Problem ID: 410
3. [Minimize Maximum Pair Sum in Array](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/) Problem ID: 1877
4. [Maximize Sweetness of Chocolate](https://leetcode.com/problems/divide-chocolate/) Problem ID: 1231


More Questions and Template : https://leetcode.com/discuss/study-guide/3444552/binary-search-on-answer-template-generic-template

Taking example of KOKO Eating banana problem here are steps to approach this problem:

**Initialization** : Set the initial values for the search range. In this case, 'start' is initialized as the minimum possible eating speed (1), and 'end' is set to an initial value (in this case, the maximum pile size in the 'piles' array).

**Binary Search Loop** : Enter a while loop that continues until the 'start' value is less than or equal to the 'end' value. This loop will narrow down the search space until the minimum eating speed is found.

**Middle Value Calculation** : Calculate the middle value, 'mid', as the average of 'start' and 'end'.

**Feasibility Check** : Call the 'ispossible' method to check if it is possible to eat all the piles within the given hours using the current eating speed ('mid'). The 'ispossible' method calculates the total hours required based on the current eating speed and checks if it is less than or equal to the given hours ('h').

**Updating Search Range** : If it is possible to eat all the piles within the given hours, update the 'ans' variable as the minimum of 'end' and 'mid'. This ensures that we find the minimum possible eating speed. Then, update the 'end' variable to 'mid-1' to further narrow down the search space and search for even smaller eating speeds.

**Adjusting Search Range** : If it is not possible to eat all the piles within the given hours, update the 'start' variable to 'mid + 1' to search for a higher eating speed. This adjusts the search range to focus on faster eating speeds.

**Termination** : The binary search loop terminates when the 'start' value is greater than the 'end' value, indicating that the search space has been narrowed down to a single value or that the minimum eating speed has been found.

**Return Result** : Once the binary search loop ends, return the minimum eating speed stored in the 'ans' variable as the result.
