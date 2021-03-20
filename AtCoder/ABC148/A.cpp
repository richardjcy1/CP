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
    int a, b;
    cin >> a >> b;
    v[a] = 1; v[b] = 1;
    for (int i = 1; i <= 3; i++)
    {
        if (!v[i]) cout << i << endl;
    }
    return 0;
}