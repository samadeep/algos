### 2955. Number of Same-End Substrings

You are given a 0-indexed string s, and a 2D array of integers queries, where queries[i] = [li, ri] indicates a substring of s starting from the index li and ending at the index ri (both inclusive), i.e. s[li..ri].

Return an array ans where ans[i] is the number of same-end substrings of queries[i].

A 0-indexed string t of length n is called same-end if it has the same character at both of its ends, i.e., t[0] == t[n - 1].

A substring is a contiguous non-empty sequence of characters within a string.

Example 1:

Input: s = "abcaab", queries = [[0,0],[1,4],[2,5],[0,5]]
Output: [1,5,5,10]
Explanation: Here is the same-end substrings of each query:
1st query: s[0..0] is "a" which has 1 same-end substring: "a".
2nd query: s[1..4] is "bcaa" which has 5 same-end substrings: "bcaa", "bcaa", "bcaa", "bcaa", "bcaa".
3rd query: s[2..5] is "caab" which has 5 same-end substrings: "caab", "caab", "caab", "caab", "caab".
4th query: s[0..5] is "abcaab" which has 10 same-end substrings: "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab", "abcaab".


Example 2:

Input: s = "abcd", queries = [[0,3]]
Output: [4]
Explanation: The only query is s[0..3] which is "abcd". It has 4 same-end substrings: "abcd", "abcd", "abcd", "abcd".


Constraints:

2 <= s.length <= 3 * 104
s consists only of lowercase English letters.
1 <= queries.length <= 3 * 104
queries[i] = [li, ri]
0 <= li <= ri < s.length

Code :
```cpp
class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int Q = queries.size();
        int N = s.size();
        vector<vector<int>> freq( N+1 , vector<int>( 26,0 ) );

        for( int i = 1 ; i <= N ; i++ )
        {
            freq[i] = freq[i-1];
            freq[i][s[i-1]-'a'] += 1;
        }

        for( int i = 0 ; i < Q ; i++ )
        {
            int L = queries[i][0] + 1 , R = queries[i][1] + 1;
            int total_substrings = 0;

            for( int c = 0 ; c <= 25 ; c++ )
            {
                int cnt = freq[R][c] - freq[L-1][c];
                total_substrings += (cnt*(cnt+1))/2 ;
            }
            ans.push_back(total_substrings);
        }
        return ans;
    }
};
```
