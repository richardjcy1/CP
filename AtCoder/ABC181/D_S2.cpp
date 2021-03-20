#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
multiple of 8 -> last three digits divisible by 8
enumerate last three digits from 0 to 1000

ATTENTION!!!
if n >= 2 cannot choose < 10
if n >= 3 cannot choose < 100
then check frequency of each digit to see if it is covered by the original number
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(10);
    for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
    bool ans = false;
    for (int i = 0; i < 1000; i += 8)
    {
        if (!i) continue;
        if (i < 10 && n >= 2) continue;
        if (i < 100 && n >= 3) continue;
        bool ok = true;
        vector<int> tmp(10);
        int v = i;
        while (v)
        {
            int last = v % 10;
            tmp[last]++;
            v /= 10;
        }
        for (int j = 0; j < 10; j++) 
        {
            if (tmp[j] > cnt[j]) ok = false;
        }
        if (ok)
        {
            //cout << i << endl;
            ans = true;
            break;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}