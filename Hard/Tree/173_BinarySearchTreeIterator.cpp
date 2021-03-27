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
// Use a stack to preserve inorder traversal
// always find the left child until non-exist
// pop one element, push right child and find the left-most
class BSTIterator {
public:
    stack<TreeNode*> stk;
    
    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        stk.push(cur);
        while (cur->left)
        {
            stk.push(cur->left);
            cur = cur->left;
        }
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if (node->right)
        {
            stk.push(node->right);
            TreeNode* cur = node->right;
            while (cur->left)
            {
                stk.push(cur->left);
                cur = cur->left;
            }
        }
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */