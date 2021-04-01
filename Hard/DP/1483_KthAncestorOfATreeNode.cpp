const int maxn = 5e4 + 5;
int dp[20][maxn];

class TreeAncestor {
public:
    
    TreeAncestor(int n, vector<int>& parent) {
        memset(dp, -1, sizeof dp);
        int m = parent.size();
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = parent[i];
        }
        for (int i = 1; i < 20; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int node = dp[i - 1][j];
                if (node != -1)
                {
                    dp[i][j] = dp[i - 1][node];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++)
        {
            if (k & (1 << i))
            {
                node = dp[i][node];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */