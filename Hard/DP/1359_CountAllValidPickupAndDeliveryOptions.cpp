typedef long long ll;
const int mod = 1e9 + 7;

class Solution {
public:
    
    int countOrders(int n) {
        /*dp[i]:number of ways of n orders
        return dp[n]
        base:dp[1]=1;
        dp[i]=C(2n,2)dp[i-1]=n*(2n-1)*dp[i-1]
        */
        vector<ll> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (i * (2 * i - 1) * dp[i - 1]) % mod;
        }
        return dp[n];
    }
};