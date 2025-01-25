[1301. Number of Paths with Max Score](https://leetcode.com/problems/number-of-paths-with-max-score/)

You are given a square `board` of characters. You can move on the board starting at the bottom right square marked with the character `'S'`.

You need to reach the top left square marked with the character `'E'`. The rest of the squares are labeled either with a numeric character `1, 2, ..., 9` or with an obstacle `'X'`. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there.

Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, **taken modulo `10^9 + 7`**.

In case there is no path, return `[0, 0]`.

**Example 1:**

**Input:** board = ["E23","2X2","12S"]
**Output:** [7,1]

**Example 2:**

**Input:** board = ["E12","1X1","21S"]
**Output:** [4,2]

**Example 3:**

**Input:** board = ["E11","XXX","11S"]
**Output:** [0,0]

**Constraints:**

- `2 <= board.length == board[i].length <= 100`




## Intuition

To solve the problem, imagine you're navigating a grid where each cell has a score or is blocked by an obstacle. You start at the bottom-right and want to reach the top-left while collecting the maximum possible score. You can only move up, left, or diagonally up-left. The goal is to find the maximum score you can collect and count how many different paths give you that maximum score.

## Approach

Initialization:

Create a 2D array called dp where dp[r][c] will store two things:  
The maximum score you can collect to reach cell (r, c).  
The number of different ways to achieve that maximum score.

Processing Each Cell:

Start from the bottom-right corner of the grid and move towards the top-left.  
For each cell, check the possible moves you can make:  
Move Up: Check the cell directly above.  
Move Left: Check the cell directly to the left.  
Move Diagonally Up-Left: Check the cell diagonally up-left.  
Update the current cell’s maximum score and the number of ways to achieve that score based on the best possible moves from the neighboring cells.

Result:

Once you have processed all cells, the top-left cell of the dp array will give you the maximum score you can achieve and the number of ways to reach that score.

For example, if your grid looks like this:

E 1 1  
X X X  
1 1 S

1 - Initialize dp such that each cell starts with a score of 0 and a path count of 0.

2 - Process the grid from bottom-right to top-left:

- For cell (2, 2), which is S, the score is 0 and there’s 1 way to be there (start point).
    
- Update the cells around it based on possible moves.
    

3 - Finally, dp[0][0] will have the maximum score and the count of paths to achieve that score.

## Complexity

- Time complexity:  
    O(n^2) because we visit each cell in the n x n grid once and update it based on its neighbors.
    
- Space complexity:  
    O(n^2) due to the dp table which stores information for every cell in the grid.
    

## Code
Track the maximum score and paths for each cell from 3 directions:

- The starting cell has score `0` and `1` paths.
- If the current score for a cell is smaller, update it and **overwrite** the number of paths.
- If the score in the same, **add** the number of paths.

```cpp
vector<vector<int>> dirs {{1, 0}, {0, 1}, {1, 1}};
vector<int> pathsWithMaxScore(vector<string>& board) {
    auto sz = board.size();
    vector<vector<int>> score(sz + 1, vector<int>(sz + 1)), paths(sz + 1, vector<int>(sz + 1));
    board[0][0] = board[sz - 1][sz - 1] = '0';
    paths[0][0] = 1;
    for (int i = 1; i <= sz; ++i) {
        for (int j = 1; j <= sz; ++j) {
            if (board[i - 1][j - 1] == 'X') 
                continue;
            for (auto d : dirs) {
                auto i1 = i - d[0], j1 = j - d[1];
                auto val = score[i1][j1] + (board[i - 1][j - 1] - '0');
                if (score[i][j] <= val && paths[i1][j1] > 0) {
                    paths[i][j] = ((score[i][j] == val ? paths[i][j] : 0) + paths[i1][j1]) % 1000000007; 
                    score[i][j] = val;
                }
            }
        }
    }
    return {paths[sz][sz] ? score[sz][sz] : 0, paths[sz][sz]};
} 
```
