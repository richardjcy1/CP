typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

// 第一个元素val作为根节点，然后将剩余元素分成>val(x个),<val(y个)两部分,分别递归调用
// 然后计算组合数，x+y个位置放x个>val方法数
// template: 组合数
class Solution {
public:
    vector<vector<ll>> c;
    
    ll solve(vector<int>& v)
    {
        int m = v.size();
        if (m == 1) return 1;
        vector<int> a, b;
        int val = v[0];
        for (int i = 1; i < m; i++)
        {
            if (v[i] > val) a.push_back(v[i]);
            else b.push_back(v[i]);
        }
        ll ans = 1;
        if (a.empty())
        {
            ans = solve(b);
            ans %= mod;
        }
        else if (b.empty())
        {
            ans = solve(a);
            ans %= mod;
        }
        else
        {
            int x = a.size(), y = b.size();
            ans = solve(a) % mod * solve(b) % mod * c[x + y][x] % mod;
        }
        return ans;
    }
    
    int numOfWays(vector<int>& nums) {
        /*[3,4,5,1,2]
        [3][4,5][1,2]
        [1,2,4,5]
        4C2=6
        reorder to be [x,>x,<x]
        */
        int n = nums.size();
        c = vector<vector<ll>>(n + 1, vector<ll>(n + 1));
        c[1][0] = c[1][1] = 1;
        for (ll i = 2; i <= n; i++)
        {
            c[i][0] = c[i][i] = 1;
            for (ll j = 1; j < i; j++)
            {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
                c[i][j] %= mod;
            }
        }
        return (solve(nums) - 1 + mod) % mod;
    }
};