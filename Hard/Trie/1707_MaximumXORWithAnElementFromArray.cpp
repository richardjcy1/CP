struct Node
{
    Node* a[2];
    bool isWord{};
    Node() { memset(a, 0, sizeof a); }
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
        for (int i = 31; ~i; i--)
        {
            int curBit = (num >> i) & 1;
            if (!node->a[curBit]) node->a[curBit] = new Node();
            node = node->a[curBit];
        }
    }
    
    int findMaxXor(int num)
    {
        int sum = 0;
        Node* node = root;
        for (int i = 31; ~i; i--)
        {
            int curBit = (num >> i) & 1;
            int otherChoice = 1 - curBit;
            if (!node->a[otherChoice])
            {
                node = node->a[curBit];
            }
            else
            {
                sum += (1 << i);
                node = node->a[otherChoice];
            }
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        for (int i = 0; i < m; i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [&](const vector<int>& a, const vector<int>& b)
             {
                 return a[1] < b[1];
             });
        vector<int> ans(m, -1);
        Trie* trie = new Trie();
        int idx = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < m; i++)
        {
            while (idx < n && nums[idx] <= queries[i][1]) trie->insert(nums[idx++]);
            if (idx) ans[queries[i][2]] = trie->findMaxXor(queries[i][0]);
        }
        return ans;
    }
};