#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int maxn = 1e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 0;
        unordered_map<ll, ll> mp;
        mp[0] = 1;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (s[i] - '0' - 1);
            if (mp.find(sum) != mp.end())
            {
                ans += mp[sum];     
            }
            mp[sum]++;
        }
        cout << ans << endl;
    }
    return 0;
}