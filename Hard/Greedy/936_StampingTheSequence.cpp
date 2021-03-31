// Think in reverse order
// Restore target string into string(n, '?')
// Time complexity: O(n^2) in the worst case
// Space complexity: O(n)
class Solution {
public:
    bool check(const string& a, const string& b, int idx)
    {
        for (int i = 0; i < b.size(); i++)
        {
            if (a[i + idx] == '?') continue;
            if (a[i + idx] != b[i]) return false;
        }
        return true;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<int> ans;
        while (1)
        {
            string tmp = target;
            for (int i = 0; i + m <= n; i++)
            {
                if (check(target, stamp, i))
                {
                    for (int j = i; j < i + m; j++) target[j] = '?';
                    ans.push_back(i);
                }
            }
            if (target == string(n, '?'))
            {
                reverse(ans.begin(), ans.end());
                return ans;
            }
            if (tmp == target) break;
        }
        return vector<int>();
    }
};