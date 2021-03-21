struct Node {
    string s;
    Node *a[26];
    Node(): s("") {memset(a, NULL, sizeof(a));}
};

struct Trie {
    Node *root;
    
    Trie() {root = new Node();}
    
    void add(string s)
    {
        Node *cur = root;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int index = s[i] - 'a';
            if (index < 0 || index >= 26) return;
            if (!cur->a[index]) {
                cur->a[index] = new Node();
            }
            cur = cur->a[index];
        }
        cur->s = s;
    }
    
    bool search(string s)
    {
        Node *cur = root;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int index = s[i] - 'a';
            if (index < 0 || index >= 26) return false;
            if (!cur->a[index]) return false;
            else cur = cur->a[index];
        }
        return !cur->s.empty();
    }
};

const vector<int> dirx = {-1,1,0,0};
const vector<int> diry = {0,0,1,-1};

void dfs(Node *root, vector<vector<char>> &board, int i, int j, unordered_set<string> &ret, vector<vector<int>> &visited)
{
    if (!root->s.empty()) {
        ret.emplace(root->s);
    }
    int m = board.size(), n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) return;
    int idx = board[i][j] - 'a';
    if (!root->a[idx]) return;
    visited[i][j] = 1;
    root = root->a[idx];
    for (int k = 0; k < 4; k++) {
        dfs(root, board, i + dirx[k], j + diry[k], ret, visited);
    }
    visited[i][j] = 0;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for (auto s: words) t.add(s);
        int m = board.size(), n = board[0].size();
        unordered_set<string> ret;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = board[i][j] - 'a';
                if (t.root->a[idx]) {
                    Node *cur = t.root;
                    dfs(cur, board, i, j, ret, visited);
                }
            }
        }
        vector<string> ans(ret.begin(), ret.end());
        return ans;
    }
};