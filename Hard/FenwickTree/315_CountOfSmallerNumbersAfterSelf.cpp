#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Use BIT to store the counts of all numbers smaller than equal to nums[i]
// The answer is sum(nums[i] - 1) because we want all the smaller elements
// Shift every negative number to positive by adding 10005
struct BIT
{
    vector<ll> bit;
    ll n;
    BIT() {init(-1);}
    BIT(ll n_) {init(n_);}
    void init(ll n_)
    {
        n = n_;
        bit.clear();
        bit.resize(n + 1, 0);
    }
    
    ll sum(ll i)
    {
        ll s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    
    void add(ll i, ll x)
    {
        if (i == 0) return;
        while (i <= n)
        {
            bit[i] += x;
            i += i & -i;
        }
    }
    
    ll sum0(ll i)
    {
        return sum(i + 1);
    }
    
    void add0(ll i, ll x)
    {
        add(i + 1, x);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        BIT b((int)(2e4 + 20));
        vector<int> ans(n);
        for (int i = n - 1; ~i; i--)
        {
            int v = nums[i] + 10005;
            ans[i] = b.sum(v - 1);
            b.add(v, 1);
        }
        return ans;
    }
};