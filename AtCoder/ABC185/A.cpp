#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v(4);
    int ans = INF;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        ans = min(ans, x);
    }
    cout << ans << endl;
    return 0;
}