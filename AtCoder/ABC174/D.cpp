#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += (s[i] == 'R');
    int ans = 0;
    for (int i = 0; i < cnt; i++) ans += (s[i] == 'W');
    cout << ans << endl;
    return 0;
}