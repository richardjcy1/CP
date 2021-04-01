const int maxn = 1005;
int dp[maxn];

class Solution {
public:
    vector<int> a;
    int n;
    int d;
    
    int solve(int idx)
    {
        if (dp[idx] != -1) return dp[idx];
        int ans = 1;
        for (int i = idx + 1; i < n && i - idx <= d; i++)
        {
            if (a[idx] > a[i])
            {
                ans = max(ans, 1 + solve(i));
            }
            else break;
        }
        for (int i = idx - 1; ~i && idx - i <= d; i--)
        {
            if (a[idx] > a[i])
            {
                ans = max(ans, 1 + solve(i));
            }
            else break;
        }
        return dp[idx] = ans;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        a = arr;
        n = a.size();
        this->d = d;
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, solve(i));
        }
        return ans;
    }
};