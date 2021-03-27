const int INF = 0x3f3f3f3f;

// Use binary search to guess the minimum value
// find the minimum pieces each of whose sum <= guessed value
class Solution {
public:
    vector<int> a;
    int n, m;
    
    bool check(int x)
    {
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > x) return false;
            if (sum + a[i] > x)
            {
                ++cnt;
                sum = a[i];
            }
            else sum += a[i];
        }
        ++cnt;
        return cnt <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        a = nums;
        n = nums.size();
        this->m = m;
        int left = 0, right = INF;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};