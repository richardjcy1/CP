#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*
Video stitching (Greedy, DP)

key observation:
sort by start time and longer interval
maintain max duration until we have to add one more clip
check gap during between + check final time covered or not

similar problems: Jump Game
*/

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        sort(clips.begin(), clips.end(), [&](const vector<int>& a, const vector<int>& b)
             {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });
        if (clips[0][0] > 0) return -1;
        int cur = clips[0][1], ma = cur, ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (cur >= T) break;
            if (clips[i][0] > ma) return -1;
            if (clips[i][0] > cur)
            {
                ++ans;
                cur = ma;
            }
            ma = max(ma, clips[i][1]);
        }
        if (ma < T) return -1;
        if (cur < T && ma >= T) ++ans;
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}