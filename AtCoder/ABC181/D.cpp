#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
math

key observation: multiple of 8 -> last three digits is multiple of 8
8 | 100*a[n-3]+10*a[n-2]+a[m-1]

count the frequency of each digit from 1 to 9
then check 1 digit, 2 digits, 3 digits case
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) 
    {
        if (s == "8") cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    if (n == 2)
    {
        if (((s[0] - '0') * 10 + (s[1] - '0')) % 8 == 0
        || ((s[1] - '0') * 10 + (s[0] - '0')) % 8 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    } 
    vector<int> cnt(10);
    for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
    bool ok = false;
    for (int i = 1; i <= 9; i++)
    {
        if (cnt[i] == 0) continue;
        cnt[i]--;
        for (int j = 1; j <= 9; j++)
        {
            if (cnt[j] == 0) continue;
            cnt[j]--;
            for (int k = 1; k <= 9; k++)
            {
                if (cnt[k] == 0) continue;
                cnt[k]--;
                if ((100 * i + 10 * j + k) % 8 == 0) ok = true;
                cnt[k]++;
            }
            cnt[j]++;
            if (ok) break;
        }
        cnt[i]++;
        if (ok) break;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}