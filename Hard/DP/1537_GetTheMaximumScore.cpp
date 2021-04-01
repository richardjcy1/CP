typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
ll dp1[maxn], dp2[maxn];

class Solution {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> mp1, mp2;
    int m, n;
    
    ll solve(int idx, int group)
    {
        if (group == 0)
        {
            if (idx == m) return 0;
            if (dp1[idx] != -1) return dp1[idx];
            ll ans = nums1[idx] + solve(idx + 1, group);
            auto it = mp2.find(nums1[idx]);
            if (it != mp2.end())
            {
                ans = max(ans, nums1[idx] + solve(it->second + 1, 1));
            }
            return dp1[idx] = ans;
        }
        else
        {
            if (idx == n) return 0;
            if (dp2[idx] != -1) return dp2[idx];
            ll ans = nums2[idx] + solve(idx + 1, group);
            auto it = mp1.find(nums2[idx]);
            if (it != mp1.end())
            {
                ans = max(ans, nums2[idx] + solve(it->second + 1, 0));
            }
            return dp2[idx] = ans;
        }
    }
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        m = nums1.size(), n = nums2.size();
        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);
        mp1 = {};
        mp2 = {};
        for (int i = 0; i < m; i++) mp1[nums1[i]] = i;
        for (int i = 0; i < n; i++) mp2[nums2[i]] = i;
        ll ans1 = solve(0, 0);
        ll ans2 = solve(0, 1);
        return max(ans1, ans2) % mod;
    }
};