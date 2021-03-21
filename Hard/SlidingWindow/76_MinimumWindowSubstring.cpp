class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++) mp[t[i]]++;
        int left = 0, ans = INT_MAX, start = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(s[i]) != mp.end())
            {
                if (mp[s[i]] > 0) ++cnt;
                mp[s[i]]--;
            }
            while (cnt == m)
            {
                if (i - left + 1 < ans)
                {
                    ans = i - left + 1;
                    start = left;
                }
                if (mp.find(s[left]) != mp.end())
                {
                    mp[s[left]]++;
                    if (mp[s[left]] > 0) --cnt;
                }
                ++left;
            }
        }
        if (ans == INT_MAX) return "";
        return s.substr(start, ans);
    }
};