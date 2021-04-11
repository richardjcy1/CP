// greedy + pq
// keep tracking of all stations that can reach and add max values if necessary
// Time complexity: O(nlogn)
// Space complexity: O(n)
const int INF = 0x3f3f3f3f;

class Solution {
public:
    int minRefuelStops(int target, int start, vector<vector<int>>& s) {
        s.push_back({target, INF});
        int n = s.size();
        priority_queue<int> pq;
        int cur = start;
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cur -= (s[i][0] - prev);
            while (pq.size() && cur < 0)
            {
                cur += pq.top(); pq.pop();
                ++ans;
            }
            if (cur < 0) return -1;
            pq.push(s[i][1]);
            prev = s[i][0];
        }
        return ans;
    }
};