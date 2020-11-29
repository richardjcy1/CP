#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;


const int maxn = 5e4 + 5;
int dp[maxn];

/*

Jump game III: (DFS/BFS)

dp solution: at each index, jump to index + arr[index] or index - arr[index];
and keep visited array (seems there is no need to keep dp array, each index at most visisted once)
if using dp array, avoid cutting edge

or do BFS + keep visisted array

T:O(n)
S:O(n)

*/


class Solution {
public:
    vector<int> a;
    int n;
    
    bool solve(int idx)
    {
        if (!a[idx]) return true;
        if (dp[idx] == 2) return false;
        if (dp[idx] != -1) return dp[idx];
        dp[idx] = 2;
        bool ans = false;
        if (idx + a[idx] < n) ans = ans || solve(idx + a[idx]);
        if (idx - a[idx] >= 0) ans = ans || solve(idx - a[idx]);
        return dp[idx] = ans;
    }
    
    bool canReach(vector<int>& arr, int start) {
        a = arr;
        n = a.size();
        memset(dp, -1, sizeof dp);
        return solve(start);
    }
};

class Solution2 {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<bool> vis(n);
        vis[start] = true;
        while (!q.empty())
        {
            int idx = q.front(); q.pop();
            if (!arr[idx]) return true;
            if (idx + arr[idx] < n && !vis[idx + arr[idx]])
            {
                vis[idx + arr[idx]] = true;
                q.push(idx + arr[idx]);
            }
            if (idx - arr[idx] >= 0 && !vis[idx - arr[idx]])
            {
                vis[idx - arr[idx]] = true;
                q.push(idx - arr[idx]);
            }
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> arr{4,2,3,0,3,1,2};
    int start = 5;
    Solution sol;
    cout << sol.canReach(arr, start) << endl;
    return 0;
}