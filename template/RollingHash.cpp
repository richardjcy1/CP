#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const ll MOD = pow(2, 32);
int a = 26;

int search(string s, int L, vector<int>& nums)
{
    ll h = 0, aL = 1;
    for (int i = 0; i < L; i++) h = (h * a + nums[i]) % MOD;
    for (int i = 1; i <= L; i++) aL = (aL * a) % MOD;
    set<ll> seen{h};
    for (int start = 1; start < n - L + 1; start++)
    {
        h = h * a;
        h = (h - nums[start - 1] * aL % MOD + MOD) % MOD;
        h = (h + nums[start + L - 1]) % MOD;
        if (seen.find(h) != seen.end()) return start;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}