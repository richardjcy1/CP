#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v(26);
    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        v[c - 'a'] = 1;
    }
    ll cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[s[i] - 'a']) ++cnt;
        else if (cnt)
        {
            ans += (cnt + 1) * cnt / 2;
            cnt = 0;
        }
    }
    if (cnt) ans += (cnt + 1) * cnt / 2;
    cout << ans << endl;
    return 0;
}