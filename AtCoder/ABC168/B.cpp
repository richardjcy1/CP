#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    if (n <= k) cout << s << endl;
    else
    {
        cout << s.substr(0,k) + "..." << endl;
    }
    return 0;
}