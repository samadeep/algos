### 572. Subtree of Another Tree
Link : https://leetcode.com/problems/subtree-of-another-tree/description/

#### Approach 1 : Check Function
```cpp
class Solution {
public:
bool check(TreeNode* root,TreeNode* subroot)
{
    if(root==NULL && subroot!=NULL)return false;
    if(root!=NULL && subroot==NULL)return false;
    if(root==NULL && subroot==NULL)return true;
    if( root->val != subroot->val ) return false;
    if(root!=NULL && subroot!=NULL && root->val == subroot->val)
    {
        bool b1= check(root->left,subroot->left);
        bool b2= check(root->right,subroot->right);
        return b1 && b2;
    }

    bool b1=  check(root->left,subroot);
    bool b2=  check(root->right,subroot);
    return b1 or b2;
}

    bool isSubtree(TreeNode* root, TreeNode* subroot) 
    {
        if(root==NULL && subroot!=NULL)return false;
        if(root && subroot==NULL)return false;
        if(root->left==NULL && root->right==NULL && subroot->left==NULL && subroot->right==NULL &&          root->val==subroot->val)
            return true;
        return  check ( root , subroot ) or isSubtree(root->left,subroot) or isSubtree( root->right ,subroot) ;
    }
};

```


#### Approach 2 : Using Leetcode Same Tree Solution

```cpp
class Solution {
public:
public:

// Choose -> check 
// Rechoose and check 

    bool isSameTree(TreeNode* p, TreeNode* q) {

        if( p == NULL && q == NULL ) return true;

        if( p == NULL || q == NULL  ) return false;

        if( p->val == q->val ) return isSameTree( p->left , q-> left ) && isSameTree( p->right , q-> right );
        else return false;

    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) 
    {
        if( root == NULL ) return false;

        return isSameTree( root , subroot ) || isSubtree( root -> left , subroot ) || isSubtree( root -> right , subroot ); 

    }
};
```
