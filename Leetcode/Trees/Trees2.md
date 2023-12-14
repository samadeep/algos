#### 1. Tree Zig Zag Order Traversal


#### 2. Tree Vertical Order Traversal

```cpp
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // Vertical Traversals in a Binary Tree as in a level Order Traversals
        // map < horixzental_level , vertical level , vector<int> nodes_in_level > mp;


        if( root == NULL )  return vector<vector<int>>{};
       
        vector<vector<int> > ans;
        map<int,map<int,multiset<int>>> mp;      // vertical , horizental , value
        queue<pair< TreeNode*, pair<int,int>> > q;  // node , vertical , horizental
        

        q.push({root , { 0 , 0 }});
        

        while( !q.empty() )
        {
            auto [ curr_node , line_level ] = q.front(); 
            q.pop();

            int vertical_line = line_level.first;
            int level = line_level.second;
            mp[vertical_line][level].insert(curr_node->val);

            if( curr_node -> left != NULL )   
                q.push( { curr_node -> left , {  vertical_line - 1 , level + 1  } } );
            if( curr_node -> right != NULL )   
                q.push( { curr_node -> right ,{  vertical_line + 1 , level + 1  } } );

        }

        // vertical , horizental , value : sorted 
        
        for( auto [ vertical , horizental_nodes ] : mp )
        {
            vector<int> vertical_nodes ; 

            for( auto [ horizental , nodes ] : horizental_nodes  )
            {
               vertical_nodes.insert( vertical_nodes.end() , nodes.begin() , nodes.end() ); 
            }

            ans.push_back(vertical_nodes);
        }

        return ans;
        
    }
};

// if inserting into vector<int> a -> [1 2 3 4]
// insert vector<int> b -> [2 3 4]
// Code ->  a.insert( a.end() , b.begin() , b.end() )
```

#### 545. Boundary of Binary Tree


#### 199. Binary Tree Right Side View
Level Wise last element in a Level-Order-Traversal
```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // do a level order traversal and return the first one
        queue<TreeNode*> q;
        vector<int> ans;
        if( root ) q.push(root);

        while( !q.empty() )
        {
            int sz = q.size();
            vector<TreeNode*> level;

            for( int i = 0; i < sz ; i++ )
            {
                auto node = q.front() ; 
                q.pop();
                level.push_back(node);
                if( node -> left )  q.push(node->left);
                if( node -> right)  q.push(node->right);
            }
            // [ a b c ] For last element -> ans.back()
            ans.push_back(level.back()->val);
        }
        return ans; 
    }
};
```

####  116. Populating Next Right Pointers in Each Node
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


####  Concept : Minimum time taken to BURN the Binary Tree from a Node
Link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/



#### All Nodes a distance K in a binary tree
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/



Additional :
