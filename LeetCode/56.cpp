#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Merge intervals (interval + sort)

key observataion:
sort + loop

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans{a[0]};
        int n = a.size();
        for (int i = 1; i < n; i++)
        {
            auto& v = ans.back();
            if (v[1] < a[i][0]) ans.push_back(a[i]);
            else
            {
                v[1] = max(v[1], a[i][1]);
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}