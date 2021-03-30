/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        string tmp;
        istringstream iss(data);
        while (getline(iss, tmp, ','))
        {
            v.push_back(tmp);
        }
        int idx = 0;
        return solve(v, idx);
    }
    
    TreeNode* solve(vector<string>& v, int& idx)
    {
        if (v[idx] == "#")
        {
            ++idx;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(v[idx++]));
        node->left = solve(v, idx);
        node->right = solve(v, idx);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));