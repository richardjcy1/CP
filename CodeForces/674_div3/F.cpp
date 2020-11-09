#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0, cntb = 0, cntc = 0, qc = 0;
    for (int i = n - 1; ~i; i--)
    {
        if (s[i] == 'a')
        {
            ans += cntb;
            ans %= mod;
        }
        else if (s[i] == 'b')
        {
           cntb += cntc + qc;
           cntb %= mod; 
        }
        else if (s[i] == 'c')
        {
           ++cntc;
           cntc %= mod; 
        }
        else if (s[i] == '?')
        {
            ans += cntb;
            ll tmp = cntc;
            cntb += cntc;
            ++cntc;
            qc += tmp;
            qc %= mod;
            ans %= mod;
            cntb %= mod;
            cntc %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}