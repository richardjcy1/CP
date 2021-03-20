/*
keep track of the appearance and disappearance of each building.
use a multiset to track current max height to check whether it is a skyline point

NOTICE:
1. first merge buildings with same height
2. multiset erase method: DO NOT erase(val); USE erase(iterator)
erase(val) will remove all equal elements
Time complexity: O(nlogn)
Space complexity: O(n)
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        int n = b.size();
        sort(b.begin(), b.end());
        vector<vector<int>> a{b[0]};
        for (int i = 1; i < n; i++)
        {
            auto& tmp = a.back();
            if (tmp[1] >= b[i][0] && tmp[2] == b[i][2])
            {
                tmp[1] = max(tmp[1], b[i][1]);
            }
            else a.push_back(b[i]);
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < a.size(); i++)
        {
            v.push_back({a[i][0], a[i][2]});
            v.push_back({a[i][1], -a[i][2]});
        }
        sort(v.begin(), v.end(), [&](const pair<int, int>& x, const pair<int, int>& y)
             {
                 return x.first == y.first ? x.second > y.second : x.first < y.first;
             });
        multiset<int> st{0};
        vector<vector<int>> ans;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].second > 0)
            {
                if (v[i].second > (*st.rbegin()))
                {
                    ans.push_back({v[i].first, v[i].second});
                }
                st.insert(v[i].second);
            }
            else
            {
                if (-v[i].second == (*st.rbegin()))
                {
                    st.erase(st.find(-v[i].second));
                    if (((*st.rbegin()) < -v[i].second)) ans.push_back({v[i].first, (*st.rbegin())});
                }
                else st.erase(st.find(-v[i].second));
            }
        }
        return ans;
    }
};