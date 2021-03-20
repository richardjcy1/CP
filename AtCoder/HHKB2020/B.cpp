#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> v;
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (j + 1 < w && v[i][j] == '.' && v[i][j + 1] == '.') ++ans;
            if (i + 1 < h && v[i][j] == '.' && v[i + 1][j] == '.') ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
