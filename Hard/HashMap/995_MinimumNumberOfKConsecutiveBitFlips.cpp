class Solution {
public:
    int minKBitFlips(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> mp;
        int ans = 0, tot = 0;
        for (int i = 0; i <= n - k; i++)
        {
            tot += mp[i];
            if ((a[i] + tot) % 2 == 0)
            {
                ++ans;
                mp[i + 1]++;
                mp[i + k]--;
            }
        }
        for (int i = n - k + 1; i < n; i++)
        {
            tot += mp[i];
            if ((a[i] + tot) % 2 == 0) return -1;
        }
        return ans;
    }
};