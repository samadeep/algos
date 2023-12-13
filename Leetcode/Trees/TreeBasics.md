## Trees Basics and Traversals

### PostOrder Traversal
Link : https://leetcode.com/problems/binary-tree-postorder-traversal/

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if( root == NULL ) return {};
        vector<int> ans;
        
        function< void( TreeNode* )> postorder = [&]( TreeNode* treeroot )
        {
            if( treeroot == NULL ) return;
            if( treeroot -> left )  postorder(treeroot -> left);
            if( treeroot -> right ) postorder(treeroot -> right);
            ans.push_back(treeroot->val);
        };

        postorder(root);
        return ans;

    }

    // void postorder( TreeNode* root )
    // {
    //     if( root == NULL ) return;
    //     postorder(root -> left);
    //     postorder(root -> right);
    //     ans.push_back(root->val);
    // }
};

// function<int(int,int,vector<int>&)> name = [&]( int a , int b , vector<int> &c )
// {
// };
```


### Level Order Traversal 
Link : https://leetcode.com/problems/binary-tree-level-order-traversal/description/
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public :
vector<vector<int>> levelOrder(TreeNode* root) 
{
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> level;

            int size=q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front(); q.pop();
                
               if(node)
               {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(level.size())
                ans.push_back(level);
        }
        return ans;
    }
};
```


### Same Tree
Link : https://leetcode.com/problems/same-tree/description/

#### Approach : Using a Queue

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        queue<TreeNode*> dfs1 , dfs2;
        dfs1.push(p); 
        dfs2.push(q);

        while( !dfs1.empty() && !dfs2.empty() )
        {
            TreeNode* node1 = dfs1.front(); dfs1.pop();
            TreeNode* node2 = dfs2.front(); dfs2.pop();

            if( node1 == NULL && node2 == NULL ) continue;
            if( node1 == NULL || node2 == NULL || node1 -> val != node2 -> val ) return false;

            dfs1.push(node1->left); dfs1.push(node1->right);
            dfs2.push(node2->left); dfs2.push(node2->right);
        }
        return dfs1.size() == 0 && dfs2.size() == 0;
    }
};

// NULL push not possible
```
#### Approach : Using Recursion

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if( p == NULL && q == NULL ) return true;

        if( p == NULL || q == NULL  ) return false;

        if( p->val != q->val ) return false;

        return isSameTree( p->left , q-> left ) && isSameTree( p->right , q-> right );

    }
};

```



### Symmetric Tree
Link : https://leetcode.com/problems/symmetric-tree/

```cpp
class Solution {
public:
     bool equality(TreeNode* ln ,TreeNode* rn)
     {

        if( ln == NULL and rn == NULL ) return true;
        if( ln == NULL or rn == NULL ) return false;
        
        return ln->val==rn->val and equality(ln->left,rn->right) and equality(ln->right, rn->left);

     }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return equality(root->left,root->right);
    }
};
```

