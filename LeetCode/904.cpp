#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
/*

queue + hashMap

from right to left, keep a queue with at most two distince values, use map to keep frequency

update the queue and map at runtime + update ans, which is queue length
*/
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        queue<int> q;
        q.push(tree[n - 1]);
        int ans = 1;
        map<int, int> mp;
        mp[tree[n - 1]] = 1;
        for (int i = n - 2; ~i; i--)
        {
            if (mp.find(tree[i]) != mp.end())
            {
                q.push(tree[i]);
                mp[tree[i]]++;
                ans = max(ans, (int)q.size());
            }
            else if (mp.size() == 1)
            {
                q.push(tree[i]);
                mp[tree[i]]++;
                ans = max(ans, (int)q.size());
            }
            else
            {
                while (mp.size() >= 2)
                {
                    int x = q.front(); q.pop();
                    mp[x]--;
                    if (mp[x] == 0) mp.erase(x);
                }
                q.push(tree[i]);
                mp[tree[i]]++;
                ans = max(ans, (int)q.size());
            }
        }
        return ans;
    }
};


class Solution2 {
/*
Sliding window:
we want to find a subarray with maximum length, which can include at most two distinct values
*/
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        int start = 0, end = 0;
        map<int, int> mp;
        int ans = 0;
        while (end < n)
        {
            mp[tree[end]]++;
            while (mp.size() > 2)
            {
                ans = max(ans, end - start);
                mp[tree[start]]--;
                if (mp[tree[start]] == 0) mp.erase(tree[start]);
                ++start;
            }
            ++end;
        }
        ans = max(ans, end - start);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> v = {{1,2,1},{0,1,2,2},{1,2,3,2,2},{3,3,3,1,2,1,1,2,3,3,4}};
    Solution2 sol2;
    for (auto tree: v)
    {
        cout << sol2.totalFruit(tree) << endl;
    }

    return 0;
}