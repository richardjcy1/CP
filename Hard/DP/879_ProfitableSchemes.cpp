typedef long long ll;
const int mod = 1e9 + 7;

ll dp[105][105][105];

class Solution {
public:
    vector<int> group;
    vector<int> profit;
    int m, n, min_profit;
    
    ll solve(int idx, int cur_people, int cur_profit)
    {
        if (idx == m) return cur_profit >= min_profit;
        if (dp[idx][cur_people][cur_profit] != -1) return dp[idx][cur_people][cur_profit];
        ll ans = solve(idx + 1, cur_people, cur_profit);
        if (cur_people + group[idx] <= n)
        {
            ans = (ans + solve(idx + 1, cur_people + group[idx], cur_profit + profit[idx] >= 100 ? 100 : cur_profit + profit[idx])) % mod;
        }
        return dp[idx][cur_people][cur_profit] = ans;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        this->n = n;
        this->group = group;
        this->profit = profit;
        this->min_profit = minProfit;
        m = group.size();
        memset(dp, -1, sizeof dp);
        return solve(0, 0, 0);
    }
};