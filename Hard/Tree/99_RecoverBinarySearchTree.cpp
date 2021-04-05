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
// Inorder traversal + keep track of disorder parts
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    
    void solve(TreeNode* root)
    {
        if (!root) return;
        solve(root->left);
        if (prev->val > root->val)
        {
            if (!first)
            {
                first = prev;
                second = root;
            }
            else
            {
                second = root;
            }
        }
        prev = root;
        solve(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        solve(root);
        if (first && second)
        {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
};