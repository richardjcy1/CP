#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    if (n == 0)
    {
        cout << 'a' << endl;
        return 0;
    }
    vector<char> v(26);
    for (int i = 1; i < 26; i++) v[i] = (char)('a' + i - 1);
    v[0] = 'z';
    string ans;
    while (n)
    {
        int last = n % 26;
        ans += v[last];
        n = (n - 1) / 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}