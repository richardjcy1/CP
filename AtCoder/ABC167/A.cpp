#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    if (n == m + 1 && t.substr(0, m) == s) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}