#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

struct CMP
{
    bool operator()(const pair<char, int>& a, const pair<char, int>& b)
    {
        return a.second < b.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();
    set<pair<char, int>, CMP> st;
    unordered_map<char, int> mp;
    char c = ' ';
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
        st.insert(make_pair(s[i], mp[s[i]]));
        if ((*st.rbegin()).second > n / 2)
        {
            c = s[i];
            break;
        }
    }
    if (c == ' ') cout << -1 << " " << -1 << endl;
    else
    {
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == c)
            {
                idx1 = i;
                break;
            }
        }
        for (int i = n - 1; ~i; i--)
        {
            if (s[i] == c)
            {
                idx2 = i;
                break;
            }
        }
        cout << idx1 + 1 << " " << idx2 + 1 << endl;
    }
    return 0;
}