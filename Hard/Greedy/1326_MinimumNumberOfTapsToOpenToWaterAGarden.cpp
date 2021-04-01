class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> v;
        for (int i = 0; i <= n; i++)
        {
            if (ranges[i]) v.push_back(make_pair(max(0, i - ranges[i]), i + ranges[i]));
        }
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b)
             {
                 return a.first == b.first ? a.second > b.second : a.first < b.first;
             });
        if (v.empty()) return -1;
        if (v[0].first > 0) return -1;
        int ans = 0, curEnd = 0, curFar = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first > curFar) return -1;
            if (curEnd < v[i].first)
            {
                ++ans;
                curEnd = curFar;
                curFar = max(curFar, v[i].second); 
            }
            else if (curEnd == v[i].first)
            {
                ++ans;
                curFar = max(curFar, v[i].second);
                curEnd = curFar;
            }
            else curFar = max(curFar, v[i].second);
            if (curEnd >= n) break;
        }
        if (curEnd < n && curFar >= n) ++ans;
        if (curFar < n) ans = -1;
        return ans;
    }
};