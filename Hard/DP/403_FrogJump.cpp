class Solution {
public:
    unordered_set<int> st;
    map<int, map<int, int>> dp;
    int last;
    
    bool solve(int pos, int prev)
    {
        if (pos == last) return true;
        if (prev > 2000) return false;
        if (dp.find(pos) != dp.end() && dp[pos].find(prev) != dp[pos].end()) return dp[pos][prev];
        bool ans = false;
        if (prev > 1 && pos + prev - 1 <= last && st.find(pos + prev - 1) != st.end()) ans = ans || solve(pos + prev - 1, prev - 1);
        if (pos + prev <= last && st.find(pos + prev) != st.end()) ans = ans || solve(pos + prev, prev);
        if (pos + prev + 1 <= last && st.find(pos + prev + 1) != st.end()) ans = ans || solve(pos + prev + 1, prev + 1);
        return dp[pos][prev] = ans;
    }
    
    bool canCross(vector<int>& s) {
        dp = {};
        last = s.back();
        st = unordered_set<int>(s.begin(), s.end());
        if (st.find(1) == st.end()) return false;
        return solve(1, 1);
    }
};