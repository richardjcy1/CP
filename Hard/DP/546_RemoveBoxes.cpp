const int maxn = 105;
int dp[maxn][maxn][maxn];

class Solution {
public:
    vector<int> a;
    
    int solve(int left, int right, int cnt)
    {
        if (left > right) return 0;
        if (dp[left][right][cnt] != -1) return dp[left][right][cnt];
        int ans = solve(left, right - 1, 0) + (cnt + 1) * (cnt + 1);
        for (int i = left; i < right; i++)
        {
            if (a[i] == a[right])
            {
                ans = max(ans, solve(left, i, cnt + 1) + solve(i + 1, right - 1, 0));
            }
        }
        return dp[left][right][cnt] = ans;
    }
    
    int removeBoxes(vector<int>& b) {
        a = b;
        int n = a.size();
        memset(dp, -1, sizeof dp);
        return solve(0, n - 1, 0);
    }
};