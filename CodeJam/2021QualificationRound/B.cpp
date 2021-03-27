#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = n - 1; ~i; i--)
        {
            if (s[i] == '?')
            {
                if (i != n - 1)
                {
                    if (s[i + 1] == '?')
                    {
                        dp[i] = dp[i + 2];
                    }
                    else if (s[i + 1] == 'C')
                    {
                        dp[i]
                        
                    }
                    else if (s[i + 1] == 'J')
                    {
                        
                    }
                }
                
            }
            else if (s[i] == 'C')
            {
                
            }
            else if (s[i] == 'J')
            {
                
            }
        }


    return 0;
}