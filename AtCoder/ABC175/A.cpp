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
    int start = 0, end = 0, ans = 0;
    while (end < n)
    {
        if (s[end] == 'R')
        {
            ++end;
            continue;
        }
        ans = max(ans, end - start);
        end++;
        start = end;
    }
    ans = max(ans, end - start);
    cout << ans << endl;
    return 0;
}