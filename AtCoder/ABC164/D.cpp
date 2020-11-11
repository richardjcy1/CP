#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    ll sum = 0;
    unordered_map<int, vector<ll>> mp;
    mp[0].push_back(-1); 
    ll ans = 0;
    vector<ll> modulo(n + 1);
    modulo[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        modulo[i] = modulo[i - 1] * 10;
        modulo[i] %= 2019;
    }
    //for (int i: modulo) cout << i << " ";
    //cout << endl;
    for (int i = 0; i < n; i++)
    {
        sum = sum * 10 + (s[i] - '0');
        sum %= 2019;
        //cout << sum << ": ";
        if (sum == 0) 
        {
            ans += mp[sum].size();
            mp[sum].push_back(i);
            continue;
        }
        for (auto p: mp)
        {
            for (auto q: p.second)
            {
                if (modulo[i - q] * p.first % 2019 == sum) 
                {
                    ++ans;
                    //cout << q << " " << i << " " << s.substr(q, i - q + 1) << endl;
                }
            }
        }
        //cout << endl;
        mp[sum].push_back(i);
    }
    cout << ans << endl;
    return 0;
}