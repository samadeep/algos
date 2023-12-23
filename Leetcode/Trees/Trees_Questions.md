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
### 10034. Find Number of Coins to Place in Tree Nodes
Link : https://leetcode.com/problems/find-number-of-coins-to-place-in-tree-nodes/
```cpp
class Solution {
public:
    class Node
    {
        int subtreenodes;
        vector<int> pos , neg;

        public :
        int val;
        Node() 
        {
            val = 0;
        }
        
        Node( int v )
        {
            subtreenodes = 1 ;
            val = v;
            if( v > 0 ) pos.push_back(val);
            else neg.push_back(val);
        }
        
        void merge_update( Node child_node )
        {
            subtreenodes += child_node.subtreenodes;
            pos.insert( pos.end() , child_node.pos.begin() ,  child_node.pos.end() );
            neg.insert( neg.end() , child_node.neg.begin() ,  child_node.neg.end() );
            sort( pos.begin() , pos.end() );
            reverse( pos.begin() , pos.end() ); // sort( pos.begin() , pos.end() , greater<int>() )
            sort(neg.begin(),neg.end()); 
            // pos -> top3 neg -> top2 
            int pos_poss = min( static_cast<int>(pos.size()) , 3 ); 
            int neg_poss = min( static_cast<int>(neg.size()) , 2 );
            pos.resize( pos_poss );
            neg.resize( neg_poss );
        }

        long long placed_coins()
        {
            if( subtreenodes < 3 ) return 1 ;
            
            long long optimal = 0;
            
            if( (int)pos.size() == 3 )  optimal = max( optimal , 1LL * pos[0] * pos[1] * pos[2] );
            if( (int)neg.size() == 2 && pos.size() >= 1 ) optimal = max( optimal , 1LL * neg[0] * neg[1] * pos[0] );
            
            return optimal;   
        } 
    };
    
    
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) 
    {
        int n = cost.size();
        vector<long long> ans(n);
        
        vector<vector<int>> graph(n);
        
        for( auto e : edges ) 
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        function< Node(int,int) > dfs = [&]( int src , int par )
        {
            
            Node parentnode( cost[src] );
            // int a(0);
            
            for( int nxt : graph[src] )
            {
                if( nxt == par ) continue;
                Node child = dfs( nxt , src );
                parentnode.merge_update( child );
            }
            
            ans[src] =  parentnode.placed_coins();
            
            return parentnode;
        };
        
        dfs( 0 , -1 );
        
        return ans;
        
    }
};
```
