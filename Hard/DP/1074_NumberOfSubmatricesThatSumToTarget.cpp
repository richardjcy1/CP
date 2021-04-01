class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum[i + 1][j + 1] = sum[i + 1][j] + matrix[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int tot = 0;
                for (int k = 0; k < m; k++)
                {
                    tot += (sum[k + 1][j + 1] - sum[k + 1][i]);
                    if (mp.find(tot - target) != mp.end())
                    {
                        ans += mp[tot - target];
                    }
                    mp[tot]++;
                }
            }
        }
        return ans;
    }
};