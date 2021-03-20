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
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    vector<string> v{"AC","WA","TLE","RE"};
    for (auto s: v)
    {
        cout << s << " x " << mp[s] << endl;
    }
    return 0;
}