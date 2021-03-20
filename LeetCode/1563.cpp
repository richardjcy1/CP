#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 505;
int dp[maxn][maxn];

/*
Stone Game V (DP + memoization)

此题用记忆化搜索不会TLE，迭代DP会TLE
原因是每次cut 一半有很多区间不会访问到，所以用记忆化搜索会更快

同时用前缀和简化求和运算

T:O(N^3)
S:O(N^2)

*/

class Solution {
public:
    vector<int> a;
    vector<int> sum;
    int n;
    
    int solve(int start, int end)
    {
        if (start == end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        int ans = 0, tot = sum[end + 1] - sum[start], cum = 0;
        for (int i = start; i <= end; i++)
        {
            cum += a[i];
            if (cum < tot - cum)
            {
                ans = max(ans, cum + solve(start, i));
            }
            else if (cum > tot - cum)
            {
                ans = max(ans, tot - cum + solve(i + 1, end));
            }
            else
            {
                ans = max(ans, cum + solve(start, i));
                ans = max(ans, cum + solve(i + 1, end));
            }
        }
        return dp[start][end] = ans;
    }
    
    int stoneGameV(vector<int>& a) {
        this->a = a;
        n = a.size();
        memset(dp, -1, sizeof dp);
        sum = vector<int>(n + 1);
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + a[i - 1];
        }
        return solve(0, n - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}