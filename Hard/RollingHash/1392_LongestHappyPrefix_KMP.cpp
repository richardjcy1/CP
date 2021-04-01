class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> next(n, -1);
        for (int i = 1; i < n; i++)
        {
            int j = next[i - 1];
            while (j != -1 && s[j + 1] != s[i]) j = next[j];
            if (s[j + 1] == s[i]) next[i] = j + 1;
        }
        return s.substr(0, next[n - 1] + 1);
    }
};