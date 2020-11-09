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
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += (s[i] - '0');
    if (ans % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}