#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0, upper = 0;
        int n = s.size();
        if (n & 1) return 0;
        for (char c: s)
        {
            if (c == '(')
            {
                ++lower;
                ++upper;
            }
            else if (c == ')')
            {
                --lower;
                --upper;
            }
            else
            {
                --lower;
                ++upper;
            }
            lower = max(lower, 0);
            if (upper < 0) return 0;
        }
        return lower == 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        Solution sol;
        bool ans = sol.checkValidString(s);
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}