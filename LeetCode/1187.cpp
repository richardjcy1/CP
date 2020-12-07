#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int INF = 0x3f3f3f3f;
const int maxn = 2005;
int dp[maxn][maxn];

/*
dp[i][j]: start from index i in arr1, j in arr2 min number of removal

a[i - 1], a[i]
b[j]

j == -1:
    a[i] > a[i - 1]: min(dp[i + 1][-1], 1 + dp[i + 1][idx]) b[idx]>a[i - 1] upper_bound(a[i - 1])
    a[i] <= a[i - 1]: 1 + dp[i + 1][idx] upper_bound(a[i - 1])

j != -1:
    a[i] > b[j]: min(dp[i + 1][-1], 1 + dp[i + 1][idx]) upper_bound(b[j])
    a[i] <= b[j]: 1 + dp[i + 1][idx] upper_bound(b[j])

*/

class Solution {
public:
    // map<int, map<int, int>> dp;
    int m, n;
    vector<int> a, b;
    
    int solve(int idx1, int idx2)
    {
        if (idx1 == m) return 0;
        // if (dp.find(idx1) != dp.end() && dp[idx1].find(idx2) != dp[idx1].end()) return dp[idx1][idx2];
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
        // dp = {};
        memset(dp, -1, sizeof dp);
        int ans = solve(0, 0);
        return ans == INF ? -1 : ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}