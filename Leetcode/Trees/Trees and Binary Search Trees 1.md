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

#### B. Inorder and Preorder to Tree 
105. Construct Binary Tree from Preorder and Inorder Traversal
Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
```cpp
class Solution {
public:
map<int,int> inorder_val;
TreeNode* build(vector<int>& inorder,int start_in,int end_in,vector<int>& preorder,int start_pre,int end_pre)
{
    if(start_in>end_in || start_pre>end_pre) return NULL;
    
    int root_node = preorder[start_pre] ;
    
    TreeNode* node = new TreeNode(root_node);

    int division = inorder_val[preorder[start_pre]];

    int len = division - start_in;

    // Root Left Right 
    // Left Root Right
    
    node->left=build(inorder, start_in , start_in + len - 1 , preorder, start_pre + 1 , start_pre + len );
    
    node->right=build(inorder, division+1 , end_in, preorder, start_pre + len + 1  , end_pre);
    
    return node;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()!=preorder.size())return nullptr;
        int index=0;
        int n=inorder.size()-1;
        
        for(auto val:inorder )inorder_val[val]=index++;
       
       return build(inorder,0,n,preorder,0,n);
    }
};
```

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



Additional : Daily Question 
#### Desing a Food Rating System 

Link : https://leetcode.com/problems/design-a-food-rating-system/description/
```cpp

class FoodRatings {
    private:
    vector<string> foods;
    vector<string> cuisines;
    vector<int> ratings;
    
    map<string,string> food_cuisine; // cuisine , foods
    map<string,int> food_rating;
    map<string,set<pair<int,string>>> cuisine_food_rating ; // cuisine -> food -> top rating 

public:
   FoodRatings( vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
   {
       this->foods=foods;
       this->cuisines=cuisines;
       this->ratings=ratings;

        for( int i = 0 ; i < foods.size() ; i++ )
        {
            food_rating[foods[i]] = ratings[i];
            food_cuisine[foods[i]] = cuisines[i];
            cuisine_food_rating[cuisines[i]].insert( { -ratings[i] , foods[i]} );
        }
    }
    
    void changeRating(string food, int newRating) 
    {
        // Log(N)
        string cuisine = food_cuisine[food];
        cuisine_food_rating[cuisine].erase({ -food_rating[food] , food }) ;
        cuisine_food_rating[cuisine].insert({ -newRating  , food }) ;
        food_rating[food] = newRating;
    }

    string highestRated(string cuisine) 
    {
        return cuisine_food_rating[cuisine].begin() -> second;
    }
};

```


