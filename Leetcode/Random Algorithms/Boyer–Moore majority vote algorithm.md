
## Bayer Moore Majority Voting Algorithm

The **Boyer–Moore majority vote algorithm** is an [algorithm](https://www.wikiwand.com/en/Algorithm "Algorithm") for finding the [majority](https://www.wikiwand.com/en/Majority "Majority") of a sequence of elements using [linear time](https://www.wikiwand.com/en/Linear_time "Linear time") and a constant number of words of memory. It is named after [Robert S. Boyer](https://www.wikiwand.com/en/Robert_S._Boyer "Robert S. Boyer") and [J Strother Moore](https://www.wikiwand.com/en/J_Strother_Moore "J Strother Moore"), who published it in 1981,[](https://www.wikiwand.com/en/Boyer%E2%80%93Moore_majority_vote_algorithm#cite_note-bm-1)


#### Algorithm

- Initialize an element m and a counter c with _c_ = 0
- For each element x of the input sequence:
    - If _c_ = 0, then assign _m_ = _x_ and _c_ = 1
    - else if _m_ = _x_, then assign _c_ = _c_ + 1
    - else assign _c_ = _c_ − 1

### Majority Element in O(N) time 

[169. Majority Element](https://leetcode.com/problems/majority-element/)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int candidate = nums[0];
        int score = 0;
        for (auto n : nums) {
            if (n == candidate) {
                score++;
            } 
            else {
                score--;
                if (score < 0) {
                    candidate = n;
                    score = 1;
                }
            }
        }
        return candidate; 
    }
};
```
Related :
- [2780. Minimum Index of a Valid Split](https://leetcode.com/problems/minimum-index-of-a-valid-split/)
- Based on 2 **Candidate** **Majority Voting Algorithm** [229. Majority Element II](https://leetcode.com/problems/majority-element-ii/)
