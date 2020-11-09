#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
divisibility of 3: sum of each digit is divisible by 3
sum == 0 -> ok
sum == 1 -> remove 1 digit (mod 1) or remove 2 digits (mod 2) if possible
sum == 2 -> remove 1 digit (mod 2) or remove 2 digits (mod 1) if possible
T: O(n)
S: O(1)
*/

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