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

### 968. Binary Tree Cameras
Link : https://leetcode.com/problems/binary-tree-cameras/description/

```cpp
class Solution {
public:
    int not_covered = 0 , hasCamera = 1 , covered = 2 ;
    int number = 0;

    int find_cover( TreeNode* root )
    {
        if( root == NULL ) return covered;
        
        int left = find_cover( root -> left );
        int right = find_cover( root -> right );

        if( left == not_covered || right == not_covered )
        {
            number++;
            return hasCamera;
        }

        else if( left == hasCamera || right == hasCamera )
        {
            return covered;
        } 

        else
        {
            return not_covered;
        }

    }

    int minCameraCover(TreeNode* root) {

        int root_covered = find_cover(root);

        if( root_covered == not_covered ) return number + 1 ;
        else return number ;
        
    }
};

```
