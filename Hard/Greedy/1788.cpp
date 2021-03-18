typedef long long ll;
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int maximumBeauty(vector<int>& a) {
        // find the left and right bounds
        // calculate all the positives in between
        // same value: leftmost rightmost
        // sum[i]: all positives in between
        int n = a.size();
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; i++)
        {
            sum[i] = max(0, a[i - 1]) + sum[i - 1];
        }
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(a[i]) != mp.end())
            {
                mp[a[i]].second = i;
            }
            else
            {
                mp[a[i]].first = mp[a[i]].second = i;
            }
        }
        ll ans = -INF;
        for (const auto& p: mp)
        {
            if (p.second.first != p.second.second)
            {
                ans = max(ans, (ll)p.first * 2 + sum[p.second.second] - sum[p.second.first + 1]);
            }
        }
        return ans;
    }
};