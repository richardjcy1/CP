#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Since the number can have most 18 digits, we can enumerate all 1 << 18 possibilities by removing/not removing each digit.
(Search the exploration space)
T: O(2^n * n)
S: O(1)
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int ans = 20;
    for (int i = 1; i < 1 << n; i++)
    {
        int num = 0, sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                num++;
                sum += s[j] - '0';
            }
        }
        if (sum % 3 == 0) ans = min(ans, n - num);
    }
    if (ans == 20) ans = -1;
    cout << ans << endl;
    return 0;
}