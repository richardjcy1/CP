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
        ll n, s, k;
        cin >> n >> s >> k;
        /* (s + x * k) % n == 0 min x?
        s % n == n - (x * k) % n
        ((x % n) * (k % n)) % n = n - s
        
        */


    return 0;
}