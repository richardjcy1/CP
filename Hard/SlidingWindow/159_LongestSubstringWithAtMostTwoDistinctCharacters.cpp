class Solution {
public:
    int lengthOfLongestSubstring(string s, int k) {
        if (k == 0) return 0;
        int n = s.size();
        unordered_map<char, int> mp;
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
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
    
    int lengthOfLongestSubstringTwoDistinct(string s) {
        return lengthOfLongestSubstring(s, 2);
    }
};