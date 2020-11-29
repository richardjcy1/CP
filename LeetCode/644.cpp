#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

/*

Maximum average subarray II (binary search + prefix sum + greedy)

find the maximum -> from low to high -> true to false
error within 10^-5 is right -> floating point binary search
sum / n >= x -> (a[i] - x) + (a[i + 1] - x) + ... + (a[i + n - 1] - x) >= 0

HIGHLIGHT:
for length >= k, just keep min prev_sum, if (cur_sum - min_prev_sum) does not satisfy >= 0, then no need to check others

be careful about boundary, 0,1,...k - 2, k - 1

*/

class Solution {
public:
    int n, k;
    
    bool check(double x, vector<int>& a)
    {
        double cur = 0.0, prev = 0.0, mi = 0.0;
        for (int i = 0; i < n; i++)
        {
            cur += a[i] - x;
            if (i < k - 1) continue;
            if (cur - mi >= 0.0) return true;
            prev += a[i - k + 1] - x;
            mi = min(mi, prev);
        }
        return false;
    }
    
    double findMaxAverage(vector<int>& nums, int k) {
        n = nums.size();
        this->k = k;
        int ma = nums[0], mi = nums[0];
        for (int i = 1; i < n; i++)
        {
            ma = max(ma, nums[i]);
            mi = min(mi, nums[i]);
        }
        double left = mi, right = ma;
        while (right - left > 1e-5)
        {
            double mid = (left + right) / 2;
            if (check(mid, nums)) left = mid;
            else right = mid;
        }
        return left;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums{1,12,-5,-6,50,3};
    int k = 4;
    Solution sol;
    cout << sol.findMaxAverage(nums, k) << endl;
    return 0;
}