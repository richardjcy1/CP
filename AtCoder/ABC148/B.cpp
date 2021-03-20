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
    cin >> n;
    string s, t;
    cin >> s >> t;
    string ans;
    for (int i = 0; i < n; i++)
    {
        ans += s[i];
        ans += t[i];
    }
    cout << ans << endl;
    return 0;
}