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
    unordered_map<string, int> mp;
    unordered_set<string> st;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        st.insert(s);
    }
    for (auto s: st)
    {
        if (s[0] == '!') mp[s.substr(1)]++;
        else mp[s]++;
    }
    bool ok = false;
    string ans;
    for (auto p: mp)
    {
        if (p.second > 1)
        {
            ok = true;
            ans = p.first;
            break;
        }
    }
    if (ok) cout << ans << endl;
    else cout << "satisfiable" << endl;
    return 0;
}