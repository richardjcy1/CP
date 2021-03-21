struct Node
{
    Node* a[2];
    bool isWord{};
    int cnt;
    Node(): cnt(0) { memset(a, 0, sizeof a); }
};

struct Trie
{
    Node* root;
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(int num)
    {
        Node* node = root;
        for (int i = 16; ~i; i--)
        {
            int curBit = (num >> i) & 1;
            if (!node->a[curBit]) node->a[curBit] = new Node();
            node = node->a[curBit];
            node->cnt++;
        }
    }
    
    int solve(Node* node, int x, int num, int idx)
    {
        if (!node) return 0;
        int sum = 0;
        int u = (x >> idx) & 1;
        int v = (num >> idx) & 1;
        if (u == 0 && v == 0)
        {
            if (idx == 0) return node->a[0] ? node->a[0]->cnt : 0;
            sum += solve(node->a[0], x, num, idx - 1);
        }
        else if (u == 0 && v == 1)
        {
            if (idx == 0) return (node->a[0] ? node->a[0]->cnt : 0) + (node->a[1] ? node->a[1]->cnt : 0);
            if (node->a[0]) sum += node->a[0]->cnt;
            sum += solve(node->a[1], x, num, idx - 1);
        }
        else if (u == 1 && v == 0)
        {
            if (idx == 0) return node->a[1] ? node->a[1]->cnt : 0;
            sum += solve(node->a[1], x, num, idx - 1);
        }
        else
        {
            if (idx == 0) return (node->a[0] ? node->a[0]->cnt : 0) + (node->a[1] ? node->a[1]->cnt : 0);
            if (node->a[1]) sum += node->a[1]->cnt;
            sum += solve(node->a[0], x, num, idx - 1);
        }
        return sum;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        Trie* trie = new Trie();
        int ans = 0;
        for (int i: nums)
        {
            int hi = trie->solve(trie->root, i, high, 16);
            int lo = trie->solve(trie->root, i, low - 1, 16);
            ans = ans + (hi - lo);
            trie->insert(i);
        }
        return ans;
    }
};