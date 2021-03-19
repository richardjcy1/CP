// dp[i]: start from ith index, all possible ways to construct the word
// dp[i]=|(s[i...j] appended by dp[j + 1] if s[i...j] in the dict)
class Solution {
public:
    string s;
    unordered_set<string> st;
    int n;
    unordered_map<int, vector<string>> dp;
    
    vector<string> solve(int idx)
    {
        if (idx == n)
        {
            return {""};
        }
        if (dp.find(idx) != dp.end()) return dp[idx];
        vector<string> ans;
        for (int i = idx; i < n; i++)
        {
            if (st.find(s.substr(idx, i - idx + 1)) != st.end())
            {
                auto v = solve(i + 1);
                for (auto str: v)
                {
                    if (str == "") ans.push_back(s.substr(idx, i - idx + 1));
                    else ans.push_back(s.substr(idx, i - idx + 1) + " " + str);
                }
            }
        }
        dp[idx] = ans;
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& w) {
        st = unordered_set<string>(w.begin(), w.end());
        this->s = s;
        n = s.size();
        dp = {};
        return solve(0);
    }
};