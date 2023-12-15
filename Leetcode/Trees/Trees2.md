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

Path Sum
Chack at the Leaf Node for the sum 

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
class Solution {
public:
    bool add_and_send( TreeNode* root , int target )
    {
        if( root -> left == NULL && root -> right == NULL )
        {
            if( target - root->val == 0 ) return true ;
            else return false;
        }

        bool done = false;
        if( !done && root -> left )  
            done |= add_and_send( root -> left , target - root -> val );
        if( !done && root -> right )  
            done |= add_and_send( root -> right , target - root -> val );
        return done ;
    }

    bool hasPathSum(TreeNode* root, int target) {

        if( !root ) return false;
        
        return add_and_send( root , target );

    }
};
```
### Binary Tree Paths 
Link : https://leetcode.com/problems/binary-tree-paths/description/

```cpp
class Solution {
public:
    vector<string> ans;
    void add_path( TreeNode* root , string path )
    {
        if( root -> left == NULL && root ->right == NULL )
        {
            string val = to_string(root->val);
            path += val;
            ans.push_back(path);
            path = path.substr( 0 , path.size() - val.size() );
            return;
        }
        if( root -> left ) 
        {
            string val = to_string(root->val);
            path += val;
            path.push_back('-');path.push_back('>');
            add_path(root -> left,path);
            path = path.substr( 0 , path.size() - val.size() );
            path.pop_back();path.pop_back();
        }
        if( root -> right )
        {
            string val = to_string(root->val);
            path += val;
            path.push_back('-');path.push_back('>');
            add_path(root -> right,path);
            path = path.substr( 0 , path.size() - val.size() );
            path.pop_back();path.pop_back();
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        if( !root ) return {};
        add_path(root,"");
        return ans;

    }
};
```



####  116. Populating Next Right Pointers in Each Node
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


####  Concept : Minimum time taken to BURN the Binary Tree from a Node
Link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
```cpp
// edges[N][2] -> { 0 , 2 } { 2 , 3 } { 3 , 4 }
// vector<int> graph(N+1);
//  for( auto e : edges )
//  {
//      graph[e[0]].push_back(e[1]);
//      graph[e[1]].push_back(e[0]); // only if undirected
//  }

class Solution {
public:
    vector<int> edges[100005]; // val unique

    // int arr[N] -> 1 1 2 3 45 
    // vector<int> edges[N] -> forms 

    void create_graph(TreeNode* root)
    {
      if( !root ) return;

      if(root->left){
          edges[root->val].push_back(root->left->val);
          edges[root->left->val].push_back(root->val);
      }

      if(root->right){
          edges[root->val].push_back(root->right->val);
          edges[root->right->val].push_back(root->val);
      }

      create_graph(root->left);
      create_graph(root->right);
    }


    int amountOfTime(TreeNode* root, int start) 
    {
        create_graph(root);
        int time = -1;
        vector<bool> vis(100005,false);

        queue<int> q;
        vis[start] = true;
        q.push(start);

        while( q.size() )
        {
          int sz = q.size();
          for( int i = 0 ; i < sz ; i++ )
          {
              int curr = q.front(); q.pop();
              vis[curr] = true;

              for( auto neighbour : edges[curr] )
              {
                  if( !vis[neighbour] )
                  {
                      q.push(neighbour);
                      vis[neighbour] = true;
                  }
              }

          }
          time++;
      }
      return time;
    }
};
```

#### All Nodes a distance K in a binary tree
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/



Additional :
#### CF : Anji's Binary Tree
Link : https://codeforces.com/problemset/problem/1900/C

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int N ; cin >> N ; 
	string s ; cin >> s; 
	s.insert(s.begin(),'0'); // root 1 index s[1] 
	
	vector<pair<int,int>> edges(N+1); // 1 index
	int R , L ;
	
	vector<int> leaves;
	
	for( int i = 1 ; i <= N ; i++ ) // N Nodes -> left and right 
	{
		cin >> L >> R ;
		
		edges[i] = {L,R}; 
		
		if( L == 0 && R == 0 ) leaves.push_back(i);
	}

	vector<int> modifications(N+1,0); // Here , dfs( root -> left ) -> edges[node].first

	function<void(int,int)> dfs = [&]( int node , int operations )
	{
		if( edges[node].first > 0 )
		{
			if( s[node] != 'L' ) dfs( edges[node].first , operations + 1 );
			
			else dfs( edges[node].first , operations );
		}
		
		if( edges[node].second > 0 )
		{
			if( s[node] != 'R' ) dfs( edges[node].second , operations + 1 );
			else dfs( edges[node].second , operations );
		}
		
		else if( edges[node].first == 0 && edges[node].second == 0 ) 
			modifications[node] = operations;
		return;
	};
	dfs( 1 , 0 ); // root , modifications
	int ans = INT_MAX;
	for( auto leaf : leaves )
	{
		ans = min( ans , modifications[leaf] );
	}
     cout << ans << endl;
    
}


signed main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);srand(time(NULL));
    int t=1;
    cin >> t ;
    while(t--) solve();
    return 0;
}
```
