#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

class Solution {
public:
    vector<pair<int, int>> v;
    map<int, map<int, pair<string, bool>>> dp;
    int n;
    
    pair<string, bool> solve(int idx, int rem)
    {
        if (idx == n)
        {
            if (rem == 0) return {"", true};
            return {"", false};
        }
        if (rem == 0) return {"", true};
        if (dp.find(idx) != dp.end() && dp[idx].find(rem) != dp[idx].end()) return dp[idx][rem];
        pair<string, bool> ans = {"", false};
        for (int i = idx; i < n; i++)
        {
            string tmp;
            if (rem - v[i].second >= 0)
            {
                auto p = solve(i, rem - v[i].second);
                if (p.second)
                {
                    tmp += to_string(v[i].first) + p.first;
                    if (ans.first.empty() || ans.first.size() < tmp.size() || ans.first < tmp)
                    {
                        ans.first = tmp;
                        ans.second = true;
                    }
                }
                auto q = solve(i + 1, rem - v[i].second);
                string tmp2;
                if (q.second)
                {
                    tmp2 += to_string(v[i].first) + p.first;
                    if (ans.first.empty() || ans.first.size() < tmp2.size() || ans.first < tmp2)
                    {
                        ans.first = tmp2;
                        ans.second = true;
                    }
                }
            }
        }
        dp[idx][rem] = ans;
        return ans;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        map<int, int> mp;
        for (int i = 0; i < cost.size(); i++)
        {
            mp[cost[i]] = i + 1;
        }
        for (auto p: mp)
        {
            v.push_back(make_pair(p.second, p.first));
        }
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b)
             {
                 return a.first > b.first;
             });
        n = v.size();
        dp = {};
        auto ans = solve(0, target);
        return ans.second ? ans.first : "0";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}