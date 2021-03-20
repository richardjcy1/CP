/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

/* Interval (sorting) problem:
sort by start time, then keep track of end time.
when found there is a gap between next start time and cur end time, add free time in result;
then udpate cur end time to be next end time.
Time complexity: O(nlogn)
Space complexity: O(n) where n is total number of intervals
*/
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> a) {
        int n = a.size();
        vector<Interval> v;
        for (int i = 0; i < n; i++)
        {
            for (auto& j: a[i]) v.push_back(j);
        }
        sort(v.begin(), v.end(), [&](const Interval& x, const Interval& y)
             {
                 return x.start < y.start;
             });
        int cur = v[0].end;
        vector<Interval> ans;
        for (int i = 1; i < v.size(); i++)
        {
            if (cur < v[i].start)
            {
                ans.push_back(Interval(cur, v[i].start));
            }
            cur = max(cur, v[i].end);
        }
        return ans;
    }
};