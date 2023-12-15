### 110. Balanced Binary Tree
Link : https://leetcode.com/problems/balanced-binary-tree

```cpp
class Solution {
public:
    int HEIGHT( TreeNode* root )
    {
        if( root == NULL ) return 0;
        return 1 + max( HEIGHT( root -> left ) , HEIGHT( root -> right ) );
    }

    bool isBalanced(TreeNode* root) 
    {
        if( root == NULL ) return true ;

        int lheight = HEIGHT(root->left);
        int rheight = HEIGHT(root->right);

        int balance = abs( lheight - rheight );

        if( balance >= 2 ) return false; // 2 , 3 , 4

        bool check_left_node_balance =  isBalanced( root -> left );
        bool check_right_node_balance = isBalanced( root -> right );
        
        return check_left_node_balance && check_right_node_balance;

    }
};
```
