#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) cout << "Won" << endl;
    else cout << "Lost" << endl;
    return 0;
}