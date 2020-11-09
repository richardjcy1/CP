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
    vector<int> cnt(3);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cnt[(s[i] - '0') % 3]++;
        sum += (s[i] - '0');
        sum %= 3;
    }
    if (sum == 0) cout << 0 << endl;
    else
    {
        if (sum == 1)
        {
            if (cnt[1] && n > 1) cout << 1 << endl;
            else if (cnt[2] >= 2 && n > 2) cout << 2 << endl;
            else cout << -1 << endl;
        }
        else
        {
            if (cnt[2] && n > 1) cout << 1 << endl;
            else if (cnt[1] >= 2 && n > 2) cout << 2 << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}