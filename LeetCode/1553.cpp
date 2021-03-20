#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Minimum number of days to dat N oranges: (DP, greedy)

prefer 2 and 3 if possible.

from one state, check 2 | N, 3 | N

T:O(logn)

*/

class Solution {
public:
    unordered_map<int, int> dp;
    
    int solve(int n)
    {
        if (n == 1) return 1;
        if (n == 0) return 0;
        if (dp.find(n) != dp.end()) return dp[n];
        int ans = min(1 + n % 2 + solve(n / 2), 1 + n % 3 + solve(n / 3));
        dp[n] = ans;
        return ans;
    }
    
    int minDays(int n) {
        dp = {};
        return solve(n);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v{10,6,1,56};
    Solution sol;
    for (int i: v) cout << sol.minDays(i) << endl;
    return 0;
}