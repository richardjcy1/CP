#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (int i = 0; i < m; i++)
    {
        int b, num;
        cin >> b >> num;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (num <= 0) break;
            
        }
    }
        
    
    return 0;
}