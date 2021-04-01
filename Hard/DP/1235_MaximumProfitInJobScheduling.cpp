class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> v;
        int n = startTime.size();
        for (int i = 0; i < n; i++)
        {
            v.push_back(make_tuple(startTime[i], endTime[i], profit[i]));
        }
        sort(v.begin(), v.end(), [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b)
             {
                 return get<1>(a) < get<1>(b);
             });
        vector<int> dp(n);
        dp[0] = get<2>(v[0]);
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(dp[i - 1], get<2>(v[i]));
            int left = 0, right = i - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (get<1>(v[mid]) <= get<0>(v[i]))
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            if (left - 1 >= 0) dp[i] = max(dp[i], get<2>(v[i]) + dp[left - 1]);
        }
        return dp[n - 1];
    }
};