class Solution {
public:
    string largestMultipleOfThree(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> v(3, vector<int>());
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            v[a[i] % 3].push_back(a[i]);
            sum += a[i];
        }
        for (int i = 0; i < 3; i++)
        {
            sort(v[i].begin(), v[i].end(), greater<int>());
        }
        if (sum % 3 == 1)
        {
            if (v[1].size() >= 1) v[1].pop_back();
            else 
            {
                v[2].pop_back();
                v[2].pop_back();
            }
        }
        else if (sum % 3 == 2)
        {
            if (v[2].size() >= 1) v[2].pop_back();
            else 
            {
                v[1].pop_back();
                v[1].pop_back();
            }
        }
        vector<int> b;
        for (int i = 0; i < 3; i++)
        {
            for (int j: v[i])
            {
                b.push_back(j);
            }
        }
        sort(b.begin(), b.end(), greater<int>());
        string ans;
        for (int i: b)
        {
            ans += to_string(i);
        }
        int i;
        for (i = 0; i < n - 1 && ans[i] == '0'; i++);
        return ans.substr(i);
    }
};