#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a;
    string b;
    cin >> a >> b;
    string c;
    for (char ch: b)
    {
        if (ch != '.') c += ch;
    }
    ll ans = a * stoll(c);
    ans /= 100;
    cout << ans << endl;
    return 0;
}