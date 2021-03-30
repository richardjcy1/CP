/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        string s = to_string(root->val);
        s += ',' + to_string(root->children.size());
        for (auto child: root->children)
        {
            s += ',' + serialize(child);
        }
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return NULL;
        istringstream iss(data);
        string tmp;
        queue<string> q;
        while (getline(iss, tmp, ','))
        {
            q.push(tmp);
        }
        return solve(q);
    }
    
    Node* solve(queue<string>& q)
    {
        auto s = q.front(); q.pop();
        int sz = stoi(q.front()); q.pop();
        Node* node = new Node(stoi(s), vector<Node*>());
        for (int i = 0; i < sz; i++)
        {
            node->children.push_back(solve(q));
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));