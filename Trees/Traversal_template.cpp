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

// Source : https://leetcode.com/problems/binary-tree-postorder-traversal/solutions/504598/an-iterative-3-in-1-template-for-preinpost-order-traversal/
// Blog : https://www.enjoyalgorithms.com/blog/iterative-binary-tree-traversals-using-stack


        stack<TreeNode*> stack{};
        TreeNode* node = root;
        TreeNode* prev = nullptr;

        while (node or not stack.empty()) {
            while (node) {
                // Pre-order region {
                //   do_something();
                // }
                stack.push(node);
                node = node->left;
            }
            node = stack.top();

            if (not node->right or prev != node->right) {
                // In-order region {
                //   do_something();
                // }
                if (node->right) {
                    node = node->right;
                    continue;
                }
            }

            if (not node->right or prev == node->right) {
                // Post-order region {
                //   do_something();
                // }
                stack.pop();
                prev = node;
                node = nullptr;
            }
        }
