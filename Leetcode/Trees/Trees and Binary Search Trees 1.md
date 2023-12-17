### 1. Construct Tree From Traversals 
Template for Stack Traversal of a Binary Tree 

```cpp
    vector<int> inorderTraversal(TreeNode* root)
    {

        stack<TreeNode*> inorder; vector<int> inorder_list;

        while( root != NULL || !inorder.empty() )
        {
            while( root != NULL )
            {
                inorder.push(root);
                root = root -> left;
            }

            root = inorder.top(); inorder.pop();
            inorder_list.push_back(root->val);
            root = root -> right;
        }
        return inorder_list;
    }
```

#### A. Inorder and Postorder to Tree 
Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Recursive Approach 
```cpp
class Solution {
public:
    map<int,int> inorder_val_index ;
    TreeNode* build(vector<int> &inorder ,int start_inorder ,int end_inorder,
                    vector<int> &postorder, int start_postorder ,int end_postorder )
    {
        if( start_inorder > end_inorder or start_postorder > end_postorder ) return NULL;

        int root_node = postorder[end_postorder]; 

        TreeNode* node = new TreeNode(root_node); // root_node -> postorder[last_element]

        int division = inorder_val_index[ root_node ]; 
        
        int poid = division - start_inorder ;
        
        // Observation -> Length is same for inorder and postorder
        node-> left = build( inorder , start_inorder , division-1 , postorder , start_postorder , start_postorder+ poid - 1 );

        node->right = build( inorder , division+1 , end_inorder , postorder , start_postorder+ poid , end_postorder -1 );

        return node;
    }


    TreeNode* buildTree(vector<int>& inorder , vector<int>& postorder ) 
    {
        if( inorder.size()-1!=postorder.size()-1 ) return nullptr;
        
        int n = inorder.size()-1;
        int index = 0;

        for( auto val : inorder ) inorder_val_index[val] = index++; 

        return build( inorder ,0,n, postorder , 0 , n ); // inorder , start , end | postorder , start , end

    }
};
```

#### B. Inorder and Postorder to Tree 
105. Construct Binary Tree from Preorder and Inorder Traversal
Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


#### 543. Diameter of Binary Tree
Link : https://leetcode.com/problems/diameter-of-binary-tree/description/

```cpp
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int reach = 0;

        function<int(TreeNode*,int&)> dfs = [&]( TreeNode* treeRoot,int &mx_depth )
        {
            if( treeRoot == NULL ) return 0;
            int left = dfs( treeRoot -> left , mx_depth );
            int right = dfs( treeRoot -> right , mx_depth );


            mx_depth = max( mx_depth , left + right ); 
            // THIS IS ACTUAL ROOT FOR DIAMETER 
           
           
            return 1 + max( left , right ); 
            // MAX HEIGHT FROM A NODE -> THIS NODE IS PART OF HEIGHT CALCULATION ONLY 

        };

        int max_distance = 0;
        int diameter = 
        dfs( root -> left , max_distance ) + dfs( root -> right , max_distance );
        
        return max( diameter , max_distance );

    }
};
```



 ## Binary Search Tree Questions 

### 530. Minimum Absolute Difference in BST
Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

```cpp
 class Solution {
public:
    int getMinimumDifference(TreeNode* root) {

        stack<TreeNode*> inorder; vector<int> inorder_list;
        
        while( root != NULL || !inorder.empty() )
        {
            while( root != NULL )
            {
                inorder.push(root);
                root = root -> left;
            }
            root = inorder.top(); inorder.pop();
            inorder_list.push_back(root->val);
            root = root -> right;
        }

        int ans = INT_MAX; // sorted -> a1 < a2 < a4 < a3

        for( int i = 1 ; i < inorder_list.size() ; i++ )
        {
            ans = min( ans , inorder_list[i] - inorder_list[i-1] );        
        }

        return ans; // left , root ,  right 

        
    }
};
```
### 98. Validate Binary Search Tree
Link : https://leetcode.com/problems/validate-binary-search-tree/description/

Approach : Inorder Traversal of Tree 
```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root,long int prevmax = LONG_MAX  , long int prevmin = LONG_MIN ) {

        stack<TreeNode*> inorder; 
        vector<int> inorder_list;

        TreeNode* prev = NULL;

        while( root != NULL || !inorder.empty() )
        {
            while( root != NULL )
            {
                inorder.push(root);
                root = root -> left;
            }
            root = inorder.top(); inorder.pop();
            inorder_list.push_back(root->val);
            root = root -> right;
        }

        for( int i = 0 ; i < inorder_list.size() - 1 ; i++ )
        {
            if( inorder_list[i] >= inorder_list[i+1] ) return false;
        }

        return true;

    }
};
```

Approach 2 : Recursive Approach 

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root,long int prevmax = LONG_MAX  , long int prevmin = LONG_MIN ) {

        if( root == NULL ) return true;
        
        bool ans = (root -> val < prevmax && root -> val > prevmin);

        return (ans & 
               isValidBST(root->left,root->val,prevmin) & 
               isValidBST(root -> right,prevmax,root->val));
        
    }
};
```

Other Questions BST : 
Kth Smallest Element in a BST
Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/




