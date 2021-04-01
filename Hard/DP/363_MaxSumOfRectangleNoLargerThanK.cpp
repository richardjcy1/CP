const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++) sum[i][j] = sum[i][j - 1] + matrix[i - 1][j - 1];
        }
        int ans = -INF;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                set<int> st{0};
                int tot = 0;
                for (int k = 0; k < m; k++)
                {
                    tot += (sum[k + 1][j + 1] - sum[k + 1][i]);
                    auto it = st.lower_bound(tot - K);
                    if (it != st.end())
                    {
                        ans = max(ans, tot - (*it));
                    }
                    st.insert(tot);
                }
            }
        }
        return ans;
    }
};