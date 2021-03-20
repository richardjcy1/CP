#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

ll power(ll a, ll n, ll p)
{
    ll res = 1;
    a %= p;
    
    while (n)
    {
        if (n & 1) res = (res * a ) % p;
        n >>= 1;
        a = (a * a) % p;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    ll sum = 0;
    unordered_map<ll, ll> mp;
    mp[0] = 1;
    ll ans = 0;
    for (int i = n - 1; ~i; i--)
    {
        sum += (s[i] - '0') * power(10, n - 1 - i, 2019);
        sum %= 2019;
        if (mp.find(sum) != mp.end())
        {
            ans += mp[sum]; 
        }
        mp[sum]++;
    }
    cout << ans << endl;
    return 0;
}