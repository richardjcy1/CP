class Solution {
public:
    int lengthOfLongestSubstring(vector<int>& s, int k) {
        if (k == 0) return 0;
        int n = s.size();
        unordered_map<int, int> mp;
        int left = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (mp.find(s[i]) == mp.end() && mp.size() >= k)
            {
                mp[s[left]]--;
                if (mp[s[left]] == 0) mp.erase(s[left]);
                ++left;
            }
            mp[s[i]]++;
            ans += i - left + 1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        return lengthOfLongestSubstring(A, K) - lengthOfLongestSubstring(A, K - 1);
    }
};