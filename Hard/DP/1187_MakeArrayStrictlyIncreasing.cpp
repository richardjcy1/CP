const int INF = 0x3f3f3f3f;
const int maxn = 2005;
int dp[maxn][maxn];

class Solution {
public:
    int m, n;
    vector<int> a, b;
    
    int solve(int idx1, int idx2)
    {
        if (idx1 == m) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int ans = INF;
        if (idx2 == 0)
        {
            if (idx1)
            {
                if (a[idx1] > a[idx1 - 1])
                {
                    ans = min(ans, solve(idx1 + 1, 0));
                    auto it = upper_bound(b.begin(), b.end(), a[idx1 - 1]);
                    if (it != b.end())
                    {
                        int d = distance(b.begin(), it);
                        ans = min(ans, 1 + solve(idx1 + 1, d + 1));
                    }
                }
                else
                {
                    auto it = upper_bound(b.begin(), b.end(), a[idx1 - 1]);
                    if (it != b.end())
                    {
                        int d = distance(b.begin(), it);
                        ans = min(ans, 1 + solve(idx1 + 1, d + 1));
                    }
                }
            }
            else
            {
                ans = min(ans, 1 + solve(idx1 + 1, 1));
                ans = min(ans, solve(idx1 + 1, 0));
            }
        }
        else
        {
            if (a[idx1] > b[idx2 - 1])
            {
                ans = min(ans, solve(idx1 + 1, 0));
                auto it = upper_bound(b.begin(), b.end(), b[idx2 - 1]);
                if (it != b.end())
                {
                    int d = distance(b.begin(), it);
                    ans = min(ans, 1 + solve(idx1 + 1, d + 1));
                }
            }
            else
            {
                auto it = upper_bound(b.begin(), b.end(), b[idx2 - 1]);
                if (it != b.end())
                {
                    int d = distance(b.begin(), it);
                    ans = min(ans, 1 + solve(idx1 + 1, d + 1));
                }
            }
        }
        dp[idx1][idx2] = ans;
        return ans;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set<int> st(arr2.begin(), arr2.end());
        a = arr1;
        b = vector<int>(st.begin(), st.end());
        m = arr1.size(), n = b.size();
        memset(dp, -1, sizeof dp);
        int ans = solve(0, 0);
        return ans == INF ? -1 : ans;
    }
};