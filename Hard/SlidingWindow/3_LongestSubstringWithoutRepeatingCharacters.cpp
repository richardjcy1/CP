class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int left = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (mp.find(s[i]) != mp.end() && mp[s[i]] >= 1)
            {
                mp[s[left++]]--;
            }
            mp[s[i]]++;
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};